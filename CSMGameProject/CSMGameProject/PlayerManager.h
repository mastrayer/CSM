
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

	void UpdatePlayerMoveDirection(int _playerId, NNPoint direction);
	void UpdatePlayerPosition(int _playerId, NNPoint point);
	void UpdatePlayerRotation(int _playerId, float angle);
	void UpdatePlayerInfo(PlayerInfo info);
	void UpdatePlayerHP(int _playerId, int hp);
	void UpdatePlayerState(int _playerId, short state );
	int GetMyPlayerId() { return m_MyPlayerId; };

private:
	std::map<int,CPlayer*> m_Players;
	CPlayer* m_MyPlayer;
	int m_MyPlayerId; // init : -1
};

