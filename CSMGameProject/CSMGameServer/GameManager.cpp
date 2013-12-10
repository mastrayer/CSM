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
}

int GameManager::GiveTeamNumber()
{
	//���� �뷱�� �˰������� ����
	if(mPlayerCount[1] < mPlayerCount[0])
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