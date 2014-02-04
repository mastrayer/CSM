#include <stdio.h>

#include "PacketHandler.h"
#include "GameManager.h"
#include "GameScene.h"

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
				dynamic_cast<CGameScene*>(NNSceneDirector::GetInstance()->GetNowScene())->GameSet();
			}
			else
			{
			}
		}
		break;
	}
}
