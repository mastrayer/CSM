#pragma once

#include "Player.h"

#define SINGLETON(type) \
	public:\
	static type* GetInstance() {static type instance; return &instance;}

class CPlayerManager
{
	SINGLETON(CPlayerManager);
public:
	CPlayerManager(void);
	~CPlayerManager(void);
	
	void SetMyPlayerId(int id);
	CPlayer* NewPlayer(int id);
	void DeletePlayer(int id);
	
	bool IsLogin() { return m_MyPlayerId==-1 ? false : true; };

	CPlayer* GetMyPlayer() { return m_MyPlayer; };

	void UpdateMyPlayerGameKeyStates(GameKeyStates _gameKeyStates);
	void UpdatePlayerGameKeyStates(int _playerId, GameKeyStates _gameKeyStaets);
	void UpdatePlayerPosition(int _playerId, NNPoint point);
	void UpdatePlayerInfo(PlayerInfo info);

	int GetMyPlayerId() { return m_MyPlayerId; };
private:
	
public:

private:
	std::map<int,CPlayer*>m_Players;
	CPlayer* m_MyPlayer;
	int m_MyPlayerId; // init : -1
	
};

