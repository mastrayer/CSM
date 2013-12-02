#pragma once
#include "PacketType.h"
#include "ClientSession.h"
#include "GameMap.h"
#define PLAYER_STATE_IDLE 0
#define PLAYER_STATE_WALK 1
#define PLAYER_STATE_ATTACK 2
#define PLAYER_STATE_DIE 3
#define PLAYER_STATE_TYPESKILL 4
#define PLAYER_STATE_USERSKILL 5


class Player
{
private:
	short mPlayerState;
	GameKeyStates mGameKeyStates;
	Point mPosition;
	int mPlayerId;
	float mRotation;
	ClientSession* mClient;
	float mAttackRange;
	int mHP;
	int mDamage;
	float mResponTime;
	int mMovedInfo;
	float mDTime;

public:
	Player(void);
	Player(int id, ClientSession* client);
	virtual ~Player(void);
	void TransState(short state);
	void SetGameKeyStates(GameKeyStates _gameKeySates) { mGameKeyStates = _gameKeySates; }
	void SetPosition(Point position) { mPosition = position; }
	void SetRotation(float angle) { mRotation = angle; }
	Point GetPosition() { return mPosition; }
	void Damaged(int damage);
	void SetHP(int hp) {mHP = hp;}
	PlayerInfo GetPlayerInfo();
	void Update( float dTime );
};

