
#include <stdio.h>
#include <assert.h>

#include "PacketHandler.h"
#include "GameManager.h"

#include "NNLogger.h"

KillScoreHandler::KillScoreHandler()
{

}
KillScoreHandler::~KillScoreHandler()
{

}
void KillScoreHandler::HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header)
{
	switch (packetType)
	{
	case PKT_SC_KILLSCORE:
		{
			if (circularBuffer->Read((char*)&mKillScoreResult, header->mSize))
			{
				// 菩哦贸府

				//CPlayerManager::GetInstance()->SetKillLimit(mKillScoreResult.mKillLimit);
				//CPlayerManager::GetInstance()->SetKillScore(mKillScoreResult.mKillScore);

				GameManager::GetInstance()->SetKillLimit( mKillScoreResult.mKillLimit );
				GameManager::GetInstance()->SetKillScore( mKillScoreResult.mKillScore );

				printf("NEW Score %d / %d for %d[%d] \n", mKillScoreResult.mKillScore[0], mKillScoreResult.mKillScore[1], mKillScoreResult.mKillLimit);
			}
			else
			{
				assert(false);
			}
		}
		break;

	case PKT_SC_PLAYER_KILLSCORE_UPDATE:
		{
			if (circularBuffer->Read((char*)&mKillScoreResult, header->mSize))
 			{
				// 菩哦贸府
				NNLogger::DebugLog("DEBUG");
			}
			else
			{
				assert(false);
			}
		}
		break;
	}
}