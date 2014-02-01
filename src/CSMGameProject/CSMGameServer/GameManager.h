#pragma once
#include "GameMap.h"
#include "Map"
#include "DeathMatch44.h"
#include "DeathMatch88.h"
#include "Game.h"

#define DEATHMATCH44 0
//#define DEATHMATCH88 1

#define MAP_AMOUNMT 1


class GameManager
{
public:
	GameManager( void );
	~GameManager(void);
	void DiePlayer(int playerId);
	int GenerateTeamNumber(int gameId);
	void EndOfGame(int gameId, int team);
	void LogOutPlayer(int playerId);
	int GetKillLimit(int gameId) { return mKillLimit[gameId]; }
	int* GetKillScore(int gameId) { return mKillScore[gameId]; }
	void AddScore(int gameId, int team, int scoreAmount);
	void Update(float dTime);
	void NewGame(int gameId, int mapType);

	GameMap* GetGameMap(int gameId){ return mGameMap[mGameMapTypes[gameId]]; }
	std::map<int, Game*>& GetGames(){ return mGames; }
private:
	void LoadMap(); // in gameManager Init

private:
	int mPlayerCount[64][2];
	int mKillScore[64][2];
	int mKillLimit[64];
	GameMap* mGameMap[MAP_AMOUNMT];
	std::map<int, int> mGameMapTypes;
	std::map<int, Game*> mGames;
};

extern GameManager* GGameManager;