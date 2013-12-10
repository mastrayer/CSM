
#pragma once

#include "Player.h"

#define SINGLETON(type) \
	public:\
	static type* GetInstance() {static type instance; return &instance;}

enum TeamColor
{
	BLUE = 0,
	RED = 1
};

class CPlayerManager
{
	SINGLETON(CPlayerManager);
public:
	CPlayerManager(void);
	~CPlayerManager(void);

	void SetMyPlayerId(int id);
	CPlayer* NewPlayer(int id);
	void DeletePlayer(int id);

	bool IsLogin() { return mMyPlayerId==-1 ? false : true; };

	CPlayer* GetMyPlayer() { return mMyPlayer; };

	void UpdatePlayerMoveDirection(int _playerId, NNPoint direction);
	void UpdatePlayerPosition(int _playerId, NNPoint point);
	void UpdatePlayerRotation(int _playerId, float angle);
	void UpdatePlayerInfo(PlayerInfo info);
	void UpdatePlayerHP(int _playerId, int hp);
	void UpdatePlayerState(int _playerId, short state );
	void UpdatePlayerTeam(int _playerId, int team);
	void UpdatePlayerType(int _playerId, int type);
	int GetMyPlayerId() { return mMyPlayerId; };

	void SetKillLimit(int limit) { mKillLimit = limit; }
	void SetKillScore(int* Score) { mKillScore[0] = Score[0]; mKillScore[1] = Score[1];}
	int GetKillScore(TeamColor color) { return mKillScore[color]; }

private:
	std::map<int,CPlayer*> mPlayers;
	CPlayer* mMyPlayer;
	int mMyPlayerId; // init : -1
	
	//일단 스코어 관리도 플레이어매니저가 합시다
	int mKillScore[2];
	int mKillLimit;
};

