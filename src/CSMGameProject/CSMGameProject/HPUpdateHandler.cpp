
#include "PacketHandler.h"
#include <stdio.h>
#include <assert.h>
#include "PlayerManager.h"

HPUpdateHandler::HPUpdateHandler()
{

}
HPUpdateHandler::~HPUpdateHandler()
{

}
void HPUpdateHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
	case PKT_SC_HP:
		{
			if ( circularBuffer->Read((char*)&mHPUpdateResult, header->mSize) )
			{
				// 패킷처리
				if ( mHPUpdateResult.mPlayerId == -1  )
				{
					/// 잘못된 데이터
					/// 무시한다
					return;
				}
				//로그인이 잘못되어 캐릭터가 없을 수 있으므로
				CPlayerManager::GetInstance()->NewPlayer( mHPUpdateResult.mPlayerId );
				
				CPlayerManager::GetInstance()->UpdatePlayerHP( mHPUpdateResult.mPlayerId, mHPUpdateResult.mHP );
				printf("HP Changed[%d] Pos : %d \n", mHPUpdateResult.mPlayerId,
					mHPUpdateResult.mHP) ;
			}
			else
			{
				assert(false) ;
			}
		}
		break;
	}
}
