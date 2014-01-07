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

	Player* GetPlayer(int playerId) { if(mPlayers.find(playerId) != mPlayers.end()) return mPlayers.find(playerId)->second; else return nullptr; };

	int GetNewPlayerId();
	int GetPlayersLength() { return mPlayersLength; };

	void GetPlayers(int gameId, std::map<int,Player*>* players); 
	
private:
	std::map<int,Player*> mPlayers;
	int mPlayersLength;
	int prevTime;
	int nowTime;
	
};

extern PlayerManager* GPlayerManager;