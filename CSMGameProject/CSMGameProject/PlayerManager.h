
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
	void UpdatePlayerTeam(int _playerId, int team);
	void UpdatePlayerType(int _playerId, int type);
	int GetMyPlayerId() { return m_MyPlayerId; };

	void SetKillLimit(int limit) { m_KillLimit = limit; }
	void SetKillScore(int* Score) { m_KillScore[0] = Score[0]; m_KillScore[1] = Score[1];}

private:
	std::map<int,CPlayer*> m_Players;
	CPlayer* m_MyPlayer;
	int m_MyPlayerId; // init : -1
	
	//일단 스코어 관리도 플레이어매니저가 합시다
	int m_KillScore[2];
	int m_KillLimit;
};

