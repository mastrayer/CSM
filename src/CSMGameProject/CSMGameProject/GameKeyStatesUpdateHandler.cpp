
#include "PacketHandler.h"
#include <stdio.h>
#include <assert.h>
#include "PlayerManager.h"

GameKeyStatesUpdateHandler::GameKeyStatesUpdateHandler()
{

}
GameKeyStatesUpdateHandler::~GameKeyStatesUpdateHandler()
{

}
void GameKeyStatesUpdateHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
	case PKT_SC_KEYSTATE:
		{
			if ( circularBuffer->Read((char*)&mGameKeyStatesUpdateResult, header->mSize) )
			{
				// 패킷처리
				if ( mGameKeyStatesUpdateResult.mMyPlayerInfo.mPlayerId == -1  )
				{
					/// 잘못된 데이터
					/// 무시한다
					return;
				}
				//로그인이 잘못되어 캐릭터가 없을 수 있으므로
				CPlayerManager::GetInstance()->NewPlayer( mGameKeyStatesUpdateResult.mMyPlayerInfo.mPlayerId );
				
				CPlayerManager::GetInstance()->UpdatePlayerInfo( mGameKeyStatesUpdateResult.mMyPlayerInfo );
				printf("Key State Changed[%d] Pos : %.1f, %.1f %.1f\n", mGameKeyStatesUpdateResult.mMyPlayerInfo.mPlayerId,
					mGameKeyStatesUpdateResult.mMyPlayerInfo.mX, mGameKeyStatesUpdateResult.mMyPlayerInfo.mY, mGameKeyStatesUpdateResult.mMyPlayerInfo.mAngle) ;
			}
			else
			{
				assert(false) ;
			}
		}
		break;
	}
}
