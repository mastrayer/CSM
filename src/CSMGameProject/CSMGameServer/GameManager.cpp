#include "stdafx.h"
#include "GameManager.h"
#include "ClientManager.h"
#include "PacketType.h"
#include "PlayerManager.h"

GameManager::GameManager()
{
	memset(mKillScore,0,sizeof(mKillScore));
	memset(mPlayerCount,0,sizeof(mPlayerCount));
	LoadMap();
}


GameManager::~GameManager(void)
{
}

void GameManager::DiePlayer(int playerId)
{
	int gameId =GPlayerManager->GetPlayer(playerId)->GetGameId();
	int team = GPlayerManager->GetPlayer(playerId)->GetTeam();
	AddScore(gameId,team,1);
	
}
void GameManager::AddScore(int gameId,int team, int scoreAmount)
{
	mKillScore[gameId][team] += scoreAmount;
	if(mKillScore[gameId][team] > mKillLimit[gameId])
	{
		EndOfGame(gameId);
	}
	else
	{
		KillScoreResult outPacket = KillScoreResult();
		outPacket.mKillLimit = mKillLimit[gameId];
		outPacket.mKillScore[0] = mKillScore[team][0];
		outPacket.mKillScore[1] = mKillScore[team][1];
		GClientManager->BroadcastPacket(nullptr,&outPacket, gameId);
	}
}

int GameManager::GenerateTeamNumber(int gameId)
{
	//딱히 밸런스 알고리즘은 없음
	if(mPlayerCount[gameId][0] == mPlayerCount[gameId][1])
	{
		int team = rand()%2;
		
		mPlayerCount[gameId][team]++;
		return team;
	}
	else if(mPlayerCount[1] < mPlayerCount[0])
	{
		mPlayerCount[gameId][1]++;
		return 1;
	}
	mPlayerCount[gameId][0]++;
	return 0;
}

void GameManager::LogOutPlayer(int playerId)
{
	int gameId =GPlayerManager->GetPlayer(playerId)->GetGameId();
	int team = GPlayerManager->GetPlayer(playerId)->GetTeam();
	mPlayerCount[gameId][team]--;
}

void GameManager::EndOfGame(int playerId)
{
	int gameId =GPlayerManager->GetPlayer(playerId)->GetGameId();
	int team = GPlayerManager->GetPlayer(playerId)->GetTeam();
	EndOfGameResult outPacket = EndOfGameResult();
	outPacket.mWinnerTeam = team;
	GClientManager->BroadcastPacket(nullptr,&outPacket, gameId);
	mGames[gameId] = nullptr;
}

void GameManager::NewGame(int gameId, int mapType)
{
	memset(mPlayerCount[gameId],0,sizeof(mPlayerCount[gameId]));
	memset(mKillScore[gameId],0,sizeof(mKillScore[gameId]));
	
	mGameMapTypes[gameId] = mapType;
	
	switch (mapType)
	{
	case DEATHMATCH44:
		{
			mGames[gameId] = new DeathMatch44(gameId);
			mKillLimit[gameId] = 40;
		}
		break;
	case DEATHMATCH88:
		{
			mGames[gameId] = new DeathMatch88(gameId);
			mKillLimit[gameId] = 80;
		}
		break;
	case FLAGCAPTURE:
		{
			mGames[gameId] = new FlagCaptureGame(gameId);
			mKillLimit[gameId] = 200;
		}
		break;
	default:
		break;
	}
}

void GameManager::LoadMap() // in gameManager Init
{
	mGameMap[0] = new GameMap(L"map/44.csm");
	mGameMap[1] = new GameMap(L"map/44.csm");
	mGameMap[2] = new GameMap(L"map/44.csm");
	mGameMap[3] = new GameMap(L"map/44.csm");
}

GameManager* GGameManager = nullptr;