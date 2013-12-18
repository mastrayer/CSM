#pragma once

#include "Player.h"
#include <map>

class PlayerManager
{
public:
	PlayerManager(void);
	~PlayerManager(void);
	
	Player* NewPlayer(int id, ClientSession* client);
	void DeletePlayer(int id);
	
	void UpdatePlayerGameKeyStates(int _playerId, GameKeyStates _gameKeyStaets);
	void UpdatePlayerPosition(int _playerId, Point point);
	void UpdatePlayerRotation(int _playerId, float angle);
	void UpdatePlayers();

	Player* GetPlayer(int id) { return mPlayers.find(id)->second; };

	int GetNewPlayerId();
	int GetPlayersLength() { return mPlayersLength; };

	std::map<int,Player*>& GetPlayers() { return mPlayers; };
private:
	std::map<int,Player*> mPlayers;
	int mPlayersLength;
	int prevTime;
	int nowTime;
	
};

extern PlayerManager* GPlayerManager;