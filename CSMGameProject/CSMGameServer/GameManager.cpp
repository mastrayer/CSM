#include "stdafx.h"
#include "GameManager.h"
#include "ClientManager.h"
#include "PacketType.h"

GameManager::GameManager(int killLimit):mKillLimit(killLimit), mKillScore(), mPlayerCount()
{
}


GameManager::~GameManager(void)
{
}

void GameManager::DiePlayer(int team)
{

	mKillScore[team] ++;
	if(mKillScore[team] > mKillLimit)
	{
		EndOfGame(team);
	}
	else
	{
		KillScoreResult outPacket = KillScoreResult();
		outPacket.mKillLimit = mKillLimit;
		outPacket.mKillScore[0] = mKillScore[0];
		outPacket.mKillScore[1] = mKillScore[1];
		GClientManager->BroadcastPacket(nullptr,&outPacket);
	}
}

int GameManager::GiveTeamNumber()
{
	//딱히 밸런스 알고리즘은 없음
	if(mPlayerCount[1] == mPlayerCount[1])
	{
		int team = rand()%2;
		
		mPlayerCount[team]++;
		return team;
	}
	else if(mPlayerCount[1] < mPlayerCount[0])
	{
		mPlayerCount[1]++;
		return 1;
	}
	mPlayerCount[0]++;
	return 0;
}

void GameManager::LogOutPlayer(int team)
{
	mPlayerCount[team]--;
}

void GameManager::EndOfGame(int winnerTeam)
{
	EndOfGameResult outPacket = EndOfGameResult();
	outPacket.mWinnerTeam = winnerTeam;
	GClientManager->BroadcastPacket(nullptr,&outPacket);
	mKillLimit = 1024*1024;
	mKillScore[0] = mKillScore[1] = -1024*1024;
}

GameManager* GGameManager = nullptr;