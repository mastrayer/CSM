#include "stdafx.h"
#include "ClientSession.h"
#include "PacketType.h"
#include "ClientManager.h"

#include "PlayerInput.h"
#include "UserSession.h"
#include "PlayerManager.h"
#include "ClientManager.h"
#include "DBCommand.h"
bool ClientSession::OnConnect(SOCKADDR_IN* addr)
{
	memcpy( &mClientAddr, addr, sizeof(SOCKADDR_IN) );

	/// 소켓을 넌블러킹으로 바꾸고

	u_long arg = 1 ;
	::ioctlsocket( mSocket, FIONBIO, &arg );

	/// nagle 알고리즘 끄기
	int opt = 1;
	::setsockopt( mSocket, IPPROTO_TCP, TCP_NODELAY, (const char*)&opt, sizeof(int) );

	printf( "[DEBUG] Client Connected: IP=%s, PORT=%d\n", inet_ntoa(mClientAddr.sin_addr), ntohs(mClientAddr.sin_port) );

	/// 패킷 핸들링
	mPacketHandler[PKT_CS_LOGIN] = ClientLoginPacket;
	mPacketHandler[PKT_CS_KEYSTATE] = ClientKeyStatePacket;
	mPacketHandler[PKT_CS_MOUSEANGLE] = ClientMouseAnglePacket;
	mPacketHandler[PKT_CS_EMOTICON] = EmoticonPacket;

	mConnected = true;

	return PostRecv();
}

bool ClientSession::PostRecv()
{
	if ( !IsConnected() )
		return false;

	DWORD recvbytes = 0;
	DWORD flags = 0;
	WSABUF buf;
	buf.len = (ULONG)mRecvBuffer.GetFreeSpaceSize();
	buf.buf = (char*)mRecvBuffer.GetBuffer();

	memset( &mOverlappedRecv, 0, sizeof(OverlappedIO) );
	mOverlappedRecv.mObject = this;

	/// 비동기 입출력 시작
	if ( SOCKET_ERROR == WSARecv(mSocket, &buf, 1, &recvbytes, &flags, &mOverlappedRecv, RecvCompletion) )
	{
		if ( WSAGetLastError() != WSA_IO_PENDING )
			return false;
	}

	IncOverlappedRecvRequest();

	return true;
}

void ClientSession::Disconnect()
{
	if ( !IsConnected() )
		return;
	
	mConnected = false;
	

	::shutdown(mSocket, SD_BOTH);
	::closesocket(mSocket);
	// delete player //	
	char query[255] = "";
	
	

	LogoutResult outPacket;
	outPacket.mPlayerId = mPlayerId;
	BroadcastWithoutSelf(&outPacket);
	printf("[DEBUG] Client Disconnected: IP=%s, PORT=%d\n", inet_ntoa(mClientAddr.sin_addr), ntohs(mClientAddr.sin_port));

	sprintf_s(query,"DELETE FROM tbl_player WHERE user_id=%d",mPlayerId);
	ExcuteNonQuery(query);
	//mysql_close(GMYSQLConnection);
	//GMYSQLConnection = nullptr;
	
}
	

void ClientSession::OnRead(size_t len)
{
	mRecvBuffer.Commit(len);

	/// 패킷 파싱하고 처리
	while ( true )
	{
		/// 패킷 헤더 크기 만큼 읽어와보기
		PacketHeader header;
		if ( false == mRecvBuffer.Peek((char*)&header, sizeof(PacketHeader)) )
			return;

		/// 패킷 완성이 되는가? 
		if ( mRecvBuffer.GetStoredSize() < (header.mSize - sizeof(PacketHeader)) )
			return;

		/// 패킷 핸들링
		if ( mPacketHandler[header.mType] )
		{
			mPacketHandler[header.mType]( this, &header, &mRecvBuffer );
		}
		else
		{
			/// 여기 들어오면 이상한 패킷 보낸거다.
			Disconnect() ;
			return ;
		}

		/// 패킷 핸들링
		/*
		switch ( header.mType )
		{
		case PKT_CS_LOGIN:
			{
				LoginRequest inPacket ;
				mRecvBuffer.Read((char*)&inPacket, header.mSize) ;

				int id = mPlayerId = GPlayerManager->GetNewPlayerId();
				GPlayerManager->NewPlayer(id);

				/// 로그인은 DB 작업을 거쳐야 하기 때문에 DB 작업 요청한다.
				LoadPlayerDataContext* newDbJob = new LoadPlayerDataContext(mSocket, id);
				GDatabaseJobManager->PushDatabaseJobRequest(newDbJob) ;

				LoginResult outPacket ;
				outPacket.mMyPlayerInfo = GPlayerManager->GetPlayer(id)->GetPlayerInfo();
				outPacket.mNowPlayersLength = GPlayerManager->GetPlayersLength();
				std::map<int,Player*> players = GPlayerManager->GetPlayers();
				int i=0;
				for( std::map<int,Player*>::iterator it = players.begin(); it != players.end(); ++it ) 
				{
					outPacket.mPlayerInfo[i] = it->second->GetPlayerInfo();
					i++;
				}
				if(!Send(&outPacket) )
					return;

				LoginBroadcastResult outPacketBroadCast;
				outPacketBroadCast.mMyPlayerInfo = GPlayerManager->GetPlayer(id)->GetPlayerInfo();
				if(!BroadcastWithoutSelf(&outPacketBroadCast) )
					return;
			}
			break ;

			case PKT_CS_KEYSTATE:
			{
				GameKeyStatesUpdateRequest inPacket ;
				mRecvBuffer.Read((char*)&inPacket, header.mSize);

				Player* _player = GPlayerManager->GetPlayer(inPacket.mMyPlayerInfo.mPlayerId);
				_player->SetGameKeyStates(inPacket.mMyPlayerInfo.mGameKeyStates);
				//_player->SetPosition(Point(inPacket.mMyPlayerInfo.mX, inPacket.mMyPlayerInfo.mY));
				_player->SetRotation(inPacket.mMyPlayerInfo.mAngle);
				GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
				outPacket.mMyPlayerInfo = _player->GetPlayerInfo();

				if( !Broadcast(&outPacket) )
					return;
			}
			break ;
			case PKT_CS_MOUSEANGLE:
			{
				MouseAngleUpdateRequest inPacket ;
				mRecvBuffer.Read((char*)&inPacket, header.mSize);

				Player* _player = GPlayerManager->GetPlayer(inPacket.mPlayerId);
				_player->SetRotation(inPacket.mAngle);
				MouseAngleUpdateResult outPacket = MouseAngleUpdateResult();
				outPacket.mPlayerId = inPacket.mPlayerId;
				outPacket.mAngle = inPacket.mAngle;

				if( !Broadcast(&outPacket) )
					return;
			}
			break ;
			default:
				{
					/// 여기 들어오면 이상한 패킷 보낸거다.
					Disconnect() ;
					return ;
				}
				break ;
		}
		*/
	}
}

bool ClientSession::Send()
{
	if ( !IsConnected() )
		return false;
	/// 보낼 데이터가 있는지 검사
	if ( mSendBuffer.GetContiguiousBytes() == 0 )
	{
		return false;
	}

	DWORD sendbytes = 0;
	DWORD flags = 0;

	WSABUF buf;
	buf.len = (ULONG)mSendBuffer.GetContiguiousBytes();
	buf.buf = (char*)mSendBuffer.GetBufferStart();

	memset( &mOverlappedSend, 0, sizeof(OverlappedIO) );
	mOverlappedSend.mObject = this;

	// 비동기 입출력 시작
	if ( SOCKET_ERROR == WSASend(mSocket, &buf, 1, &sendbytes, flags, &mOverlappedSend, SendCompletion) )
	{
		if ( WSAGetLastError() != WSA_IO_PENDING )
			return false;
	}
	IncOverlappedSendRequest();
	return true;
}

void ClientSession::OnWriteComplete( size_t len )
{
	/// 보내기 완료한 데이터는 버퍼에서 제거
	mSendBuffer.Remove(len);

	/// 얼래? 덜 보낸 경우도 있나? (커널의 send queue가 꽉찼거나, Send Completion이전에 또 send 한 경우?)
	if ( mSendBuffer.GetContiguiousBytes() > 0 )
	{
		//assert(false);
	}

}
bool ClientSession::Write( PacketHeader* pkt )
{
	if ( false == mSendBuffer.Write((char*)pkt, pkt->mSize) )
	{
		Disconnect();
		return false;
	}
	return true;
}
bool ClientSession::Broadcast( PacketHeader* pkt  )
{
	if( !Write(pkt) )
		return false;

	return BroadcastWithoutSelf(pkt);
}

bool ClientSession::BroadcastWithoutSelf( PacketHeader* pkt )
{
	if ( !IsConnected() )
		return false;

	GClientManager->BroadcastPacket( this, pkt );

	return true;
}
void ClientSession::OnTick()
{
	/// 클라별로 주기적으로 해야될 일은 여기에

	/// 특정 주기로 DB에 위치 저장
}


///////////////////////////////////////////////////////////

void CALLBACK RecvCompletion( DWORD dwError, DWORD cbTransferred, LPWSAOVERLAPPED lpOverlapped, DWORD dwFlags )
{
	ClientSession* fromClient = static_cast<OverlappedIO*>(lpOverlapped)->mObject;

	fromClient->DecOverlappedRecvRequest();

	if ( !fromClient->IsConnected() )
		return ;

	/// 에러 발생시 해당 세션 종료
	if ( dwError || cbTransferred == 0 )
	{
		fromClient->Disconnect();
		return;
	}

	/// 받은 데이터 처리
	fromClient->OnRead(cbTransferred);

	/// 다시 받기
	if ( false == fromClient->PostRecv() )
	{
		fromClient->Disconnect();
		return;
	}
}


void CALLBACK SendCompletion( DWORD dwError, DWORD cbTransferred, LPWSAOVERLAPPED lpOverlapped, DWORD dwFlags )
{
	ClientSession* fromClient = static_cast<OverlappedIO*>(lpOverlapped)->mObject;

	fromClient->DecOverlappedSendRequest();

	if ( !fromClient->IsConnected() )
		return;

	/// 에러 발생시 해당 세션 종료
	if ( dwError || cbTransferred == 0 )
	{
		fromClient->Disconnect();
		return;
	}

	fromClient->OnWriteComplete(cbTransferred);
}

