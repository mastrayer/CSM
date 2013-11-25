
#include "PacketHandler.h"
#include <stdio.h>
#include <assert.h>
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
	}
}