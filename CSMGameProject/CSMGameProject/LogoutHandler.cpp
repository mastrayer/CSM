
#include "PacketHandler.h"
#include <stdio.h>
#include <windows.h>
#include <assert.h>
#include "PlayerManager.h"
LogoutHandler::LogoutHandler()
{

}
LogoutHandler::~LogoutHandler()
{

}
void LogoutHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
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
				printf("Logout ClientId[%d] \n", m_LogoutResultPacket.m_PlayerId) ;
			}
			else
			{
				assert(false) ;
			}
		}
		break;
		
	}
}
