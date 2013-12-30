#include "PacketHandler.h"
#include <stdio.h>
#include "PlayerManager.h"

MouseAngleUpdateHandler::MouseAngleUpdateHandler()
{

}
MouseAngleUpdateHandler::~MouseAngleUpdateHandler()
{

}
void MouseAngleUpdateHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
	case PKT_SC_MOUSEANGLE:
		{
			if ( circularBuffer->Read((char*)&mMouseAngleUpdateResult, header->mSize) )
			{
				// 패킷처리
				if ( mMouseAngleUpdateResult.mPlayerId == -1  )
				{
					/// 잘못된 데이터
					/// 무시한다
					return;
				}
				//로그인이 잘못되어 캐릭터가 없을 수 있으므로
				CPlayerManager::GetInstance()->NewPlayer( mMouseAngleUpdateResult.mPlayerId );
				
				CPlayerManager::GetInstance()->UpdatePlayerRotation( mMouseAngleUpdateResult.mPlayerId, mMouseAngleUpdateResult.mAngle );
				printf("Mouse Angle Changed[%d] angle : %.1f\n", mMouseAngleUpdateResult.mPlayerId,
					mMouseAngleUpdateResult.mAngle) ;
			}
			else
			{
			}
		}
		break;
	}
}
