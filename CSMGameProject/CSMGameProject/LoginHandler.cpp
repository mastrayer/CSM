
#include "PacketHandler.h"
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include "PlayerManager.h"
LoginHandler::LoginHandler()
{

}
LoginHandler::~LoginHandler()
{

}
void LoginHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
	case PKT_SC_LOGIN:
		{
			if ( circularBuffer->Read((char*)&m_LoginResultPacket, header->m_Size) )
			{
				// 패킷처리
				if ( m_LoginResultPacket.m_MyPlayerInfo.m_PlayerId == -1  )
				{
					/// 여기 걸리면 로그인 실패다.
					PostQuitMessage(-1) ;
				}
				CPlayerManager::GetInstance()->SetMyPlayerId( m_LoginResultPacket.m_MyPlayerInfo.m_PlayerId );
				//먼저 들어와있던 플레이어의 객체 만들기
				for(int i=0; i<m_LoginResultPacket.m_NowPlayersLength; i++)
				{
					if( m_LoginResultPacket.m_MyPlayerInfo.m_PlayerId != m_LoginResultPacket.m_PlayerInfo[i].m_PlayerId )
					{
						CPlayerManager::GetInstance()->NewPlayer( m_LoginResultPacket.m_PlayerInfo[i].m_PlayerId );
						CPlayerManager::GetInstance()->UpdatePlayerInfo( m_LoginResultPacket.m_PlayerInfo[i] );
					}
				}
				printf("LOGIN SUCCESS ClientId[%d] \n", m_LoginResultPacket.m_MyPlayerInfo.m_PlayerId) ;
			}
			else
			{
				assert(false) ;
			}
		}
		break;
	case PKT_SC_LOGIN_BROADCAST:
		{
			if ( circularBuffer->Read((char*)&m_LoginBroadcastResultPacket, header->m_Size) )
			{
				// 패킷처리
				if ( m_LoginBroadcastResultPacket.m_MyPlayerInfo.m_PlayerId == -1  )
				{
					/// 여기 걸리면 로그인 실패다.
					//내 로그인 아니니까 일단은 그냥 무시할것
				}
				CPlayerManager::GetInstance()->NewPlayer( m_LoginBroadcastResultPacket.m_MyPlayerInfo.m_PlayerId );
				CPlayerManager::GetInstance()->UpdatePlayerInfo( m_LoginBroadcastResultPacket.m_MyPlayerInfo );
				printf("NEW LOGIN SUCCESS ClientId[%d] \n", m_LoginBroadcastResultPacket.m_MyPlayerInfo.m_PlayerId) ;
			}
			else
			{
				assert(false) ;
			}
		}
		break;
	case PKT_SC_LOGOUT:
		{
			if ( circularBuffer->Read((char*)&m_LogoutResultPacket, header->m_Size) )
			{
				// 패킷처리
				if ( m_LogoutResultPacket.m_PlayerId == -1  )
				{
					/// 잘못된 로그아웃.
					//내 로그아웃 아니니까 일단은 그냥 무시할것
				}
				CPlayerManager::GetInstance()->DeletePlayer( m_LogoutResultPacket.m_PlayerId );
				printf("NEW LOGIN SUCCESS ClientId[%d] \n", m_LoginBroadcastResultPacket.m_MyPlayerInfo.m_PlayerId) ;
			}
			else
			{
				assert(false) ;
			}
		}
		break;
		
	}
}
