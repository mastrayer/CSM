
#include "PacketHandler.h"
#include <stdio.h>
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
			if ( circularBuffer->Read((char*)&mLogoutResultPacket, header->mSize) )
			{
				// 패킷처리
				if ( mLogoutResultPacket.mPlayerId == -1  )
				{
					/// 잘못된 로그아웃.
					//내 로그아웃 아니니까 일단은 그냥 무시할것
				}
				CPlayerManager::GetInstance()->DeletePlayer( mLogoutResultPacket.mPlayerId );
				printf("Logout ClientId[%d] \n", mLogoutResultPacket.mPlayerId) ;
			}
			else
			{
				assert(false) ;
			}
		}
		break;
		
	}
}
