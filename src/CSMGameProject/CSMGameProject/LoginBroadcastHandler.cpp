
#include "PacketHandler.h"
#include <stdio.h>
#include "PlayerManager.h"
LoginBroadcastHandler::LoginBroadcastHandler()
{

}
LoginBroadcastHandler::~LoginBroadcastHandler()
{

}
void LoginBroadcastHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
	case PKT_SC_LOGIN_BROADCAST:
		{
			if ( circularBuffer->Read((char*)&mLoginBroadcastResultPacket, header->mSize) )
			{
				// 패킷처리
				if ( mLoginBroadcastResultPacket.mMyPlayerInfo.mPlayerId == -1  )
				{
					/// 여기 걸리면 로그인 실패다.
					//내 로그인 아니니까 일단은 그냥 무시할것
				}
				CPlayerManager::GetInstance()->NewPlayer( mLoginBroadcastResultPacket.mMyPlayerInfo.mPlayerId );
				CPlayerManager::GetInstance()->UpdatePlayerInfo( mLoginBroadcastResultPacket.mMyPlayerInfo );
				CPlayerManager::GetInstance()->UpdatePlayerNickname(mLoginBroadcastResultPacket.mMyPlayerInfo.mPlayerId, mLoginBroadcastResultPacket.mMyPlayerInfo.mName);
				printf("NEW LOGIN SUCCESS ClientId[%d] \n", mLoginBroadcastResultPacket.mMyPlayerInfo.mPlayerId) ;
			}
			else
			{
			}
		}
		break;
	}
}