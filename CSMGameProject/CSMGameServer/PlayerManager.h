#pragma once
#include "Player.h"
#include <map>
#define SINGLETON(type) \
	public:\
	static type* GetInstance() {static type instance; return &instance;}
class PlayerManager
{
	SINGLETON(PlayerManager);
public:
	PlayerManager(void);
	~PlayerManager(void);
	
	Player* NewPlayer(int id);
	void DeletePlayer(int id);
	
	void UpdatePlayerGameKeyStates(int _playerId, GameKeyStates _gameKeyStaets);
	void UpdatePlayerPosition(int _playerId, Point point);
	void UpdatePlayers();

	Player* GetPlayer(int id) { return mPlayers.find(id)->second; };

	int GetNewPlayerId();
	int GetPlayersLength() { return mPlayersLength; };

	std::map<int,Player*> GetPlayers() { return mPlayers; };
private:
	std::map<int,Player*> mPlayers;
	Player* mMyPlayer;
	int mPlayersLength;
	int prevTime;
	int nowTime;
	
};