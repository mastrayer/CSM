#pragma once

#include "Player.h"
#include <map>

class PlayerManager
{
public:
	PlayerManager(void);
	~PlayerManager(void);
	
	Player* NewPlayer(int playerId, int gameId, ClientSession* client);
	void DeletePlayer(int playerId);
	
	void UpdatePlayerGameKeyStates(int _playerId, GameKeyStates _gameKeyStaets);
	void UpdatePlayerPosition(int _playerId, Point point);
	void UpdatePlayerRotation(int _playerId, float angle);
	void UpdatePlayers();

	Player* GetPlayer(int playerId) { return mPlayers.find(playerId)->second; };

	int GetNewPlayerId();
	int GetPlayersLength(int gameId) { return mPlayersLength[gameId]; };

	void GetPlayers(int gameId, std::map<int,Player*>* players); 
	int GeneratePlayerId();
private:
	std::map<int,Player*> mPlayers;
	int mPlayersLength[255];
	int prevTime;
	int nowTime;
	
};

extern PlayerManager* GPlayerManager;