#include <stdio.h>

#include "PacketHandler.h"
#include "GameManager.h"
#include "PlayerManager.h"
#include "NNSceneDirector.h"
#include "GameEnd.h"

EndOfGameHandler::EndOfGameHandler()
{

}
EndOfGameHandler::~EndOfGameHandler()
{

}
void EndOfGameHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
	case PKT_SC_ENDOFGAME:
		{
			if ( circularBuffer->Read((char*)&mEndOfGameResult, header->mSize) )
			{
				//TODO
				//mEndOfGameResult.mWinnerTeam
				if (CPlayerManager::GetInstance()->GetMyPlayer()->GetTeam() == mEndOfGameResult.mWinnerTeam)
					NNSceneDirector::GetInstance()->ChangeScene(CGameEnd::Create(true));
				else if (CPlayerManager::GetInstance()->GetMyPlayer()->GetTeam() != mEndOfGameResult.mWinnerTeam)
					NNSceneDirector::GetInstance()->ChangeScene(CGameEnd::Create(false));
			}
			else
			{
			}
		}
		break;
	}
}
