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

#define TYPE_A 0
#define TYPE_B 1
#define TYPE_C 2
#define TYPE_D 3

#define TYPE_A_MAXHP 50
#define TYPE_B_MAXHP 50
#define TYPE_C_MAXHP 50
#define TYPE_D_MAXHP 50


class Player
{
private:
	ClientSession* mClient;
	int mPlayerId;
	
	short mPlayerState;
	GameKeyStates mGameKeyStates;
	Point mPosition;
	float mRotation;
	Point mMoveDirection;
	int mTeam;
	int mType;

	float mAttackRange;
	int mHP;
	int mMaxHP;
	float mSpeed;
	float mResponTime;
	float mAttackDelay;
	float mUserSkillDelay;
	float mTypeSkillDelay;

	float mDTime;

	int mRadius;

	int mKillScore;
	
public:
	Player(void);
	Player(int id, ClientSession* client);
	virtual ~Player(void);
	void TransState(short state);

	void InitWithType();

	void SetGameKeyStates(GameKeyStates _gameKeySates) { mGameKeyStates = _gameKeySates; }
	void SetPosition(Point position) { mPosition = position; }
	void SetRotation(float angle) { mRotation = angle; }
	void SetHP(int hp) {mHP = hp;}
	void ChangeType(int type);

	Point GetPosition() { return mPosition; }
	PlayerInfo GetPlayerInfo();
	int GetTypeChangeResult(int killerType, int victimType);
	int GetType(){ return mType; }
	int GetTeam(){ return mTeam; }
	int GetRadius(){ return mRadius; }

	bool Damaged(int damage, Player* player); // return value : true - die, false - non-die
	void Heal(int dHP);

	void Update( float dTime );


private:
	bool CouldGoPosition(Point position);
};

