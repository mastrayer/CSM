#include "stdafx.h"
#include "GameManager.h"
#include "ClientManager.h"
#include "PacketType.h"
#include "PlayerManager.h"
#include "DBCommand.h"
#include "SkillManager.h"
#include "BulletManager.h"
GameManager::GameManager()
{
	mIsRunning = false;
	memset(mIsFinishGame,false,sizeof(mIsFinishGame));
	memset(mVictoryTeam,-1,sizeof(mVictoryTeam));
	memset(mIsDestoring,false,sizeof(mIsDestoring));
	memset(mKillScore,0,sizeof(mKillScore));
	memset(mPlayerCount,0,sizeof(mPlayerCount));
	LoadMap();
}


GameManager::~GameManager(void)
{
}

bool GameManager::DiePlayer(int playerId)
{
	int gameId =GPlayerManager->GetPlayer(playerId)->GetGameId();
	int team = GPlayerManager->GetPlayer(playerId)->GetTeam();
	return AddScore(gameId,(team+1)%2,1);
	
}
bool GameManager::AddScore(int gameId,int team, int scoreAmount)
{
	mKillScore[gameId][team] += scoreAmount;
	if(mKillScore[gameId][team] >= mKillLimit[gameId])
	{
		EndOfGame(gameId, team);
		return true;
	}
	else
	{
		KillScoreResult outPacket = KillScoreResult();
		outPacket.mKillLimit = mKillLimit[gameId];
		outPacket.mKillScore[0] = mKillScore[gameId][0];
		outPacket.mKillScore[1] = mKillScore[gameId][1];
		GClientManager->BroadcastPacket(nullptr,&outPacket, gameId);
		return false;
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
	else if(mPlayerCount[gameId][1] < mPlayerCount[gameId][0])
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

void GameManager::EndOfGame(int gameId, int team)
{
	if(mIsFinishGame[gameId] == true) return;
	EndOfGameResult outPacket = EndOfGameResult();
	outPacket.mWinnerTeam = team;
	GClientManager->BroadcastPacket(nullptr,&outPacket, gameId);
	mIsFinishGame[gameId] = true;
	mVictoryTeam[gameId] = team;
}

void GameManager::DestroyGame(int gameId)
{
	if(mIsDestoring[gameId] == true)
		return;
	else
		mIsDestoring[gameId] = true;
	GSkillManager->RemoveSkill(gameId);
	GBulletManager->RemoveBullet(gameId);

	std::map<int,Player*> players;
	GPlayerManager->GetPlayers(gameId,&players);
	char query[255] = "";
	for( std::map<int,Player*>::iterator it = players.begin(); it != players.end(); ++it ) 
	{
		int playerId = it->second->GetPlayerInfo().mPlayerId;
		int playerTeam = it->second->GetPlayerInfo().mTeam;
		int playerKillscore = it->second->GetPlayerInfo().mKillScore;
		
		sprintf_s(query,"update tbl_user set play_count = play_count+1 where id=%d",playerId);
		ExcuteNonQuery(query);

		sprintf_s(query,"update tbl_user set kill_sum = kill_sum + %d where id = %d",playerKillscore,playerId);
		ExcuteNonQuery(query);

		if(mVictoryTeam[gameId] == playerTeam)
		{
			sprintf_s(query,"update tbl_user set win_count=win_count+1 where id=%d",playerId);
			ExcuteNonQuery(query);
		}
		else
		{
			sprintf_s(query,"update tbl_user set lose_count=lose_count+1 where id=%d",playerId);
			ExcuteNonQuery(query);
		}
		GPlayerManager->DeletePlayer(playerId);
		if(it == players.end()) break;
	}
	sprintf_s(query,"delete from tbl_room where id=%d",gameId);
	ExcuteNonQuery(query);
	mIsFinishGame[gameId] = false;
	mVictoryTeam[gameId] = -1;
	//GMYSQLConnection = NULL;
	mIsDestoring[gameId] = false;
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
	/*case DEATHMATCH88:
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
		break;*/
	default:
		break;
	}
}

void GameManager::Update(float dTime)
{
	mIsRunning = true;
	for(auto it = mGames.begin(); it != mGames.end(); it++)
	{
		if(mIsFinishGame[it->first] == true)
		{
			this->DestroyGame(it->first);
			delete it->second;
			it = mGames.erase(it);
			if(it == mGames.end() )
				break;
		}
		else
			it->second->Update(dTime);
	}
	mIsRunning = false;
}
void GameManager::LoadMap() // in gameManager Init
{
	mGameMap[DEATHMATCH44] = new GameMap(L"map/44.csm");
	//mGameMap[DEATHMATCH88] = new GameMap(L"map/88.csm");
	//mGameMap[FLAGCAPTURE] = new GameMap(L"map/88.csm");
}

GameManager* GGameManager = nullptr;