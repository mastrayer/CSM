#pragma once
#include "PacketType.h"
#include "ClientSession.h"

#include "Item.h"
#include "DamageBuff.h"
#include "HPBuff.h"
#include	"Flag.h"

#define PLAYER_STATE_IDLE 0
#define PLAYER_STATE_WALK 1
#define PLAYER_STATE_ATTACK 2
#define PLAYER_STATE_DIE 3
#define PLAYER_STATE_TYPESKILL 4
#define PLAYER_STATE_USERSKILL 5

#define TYPE_ZERO 0
#define TYPE_A 1
#define TYPE_B 2
#define TYPE_C 3
#define TYPE_D 4

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
	float mPreDelay;

	float mDTime;

	int mRadius;

	int mKillScore;
	
	float mDSkillPostDelay;

	int mGameId;

	//Items
	DamageBuff* mDamageBuff;
	HPBuff* mHPBuff;
	Flag* mFlag;

public:
	Player();
	Player(int gameId, int playerId, ClientSession* client);
	virtual ~Player(void);


	void SetGameKeyStates(GameKeyStates _gameKeySates) { mGameKeyStates = _gameKeySates; }
	void SetPosition(Point position) { mPosition = position; }
	void SetRotation(float angle) { mRotation = angle; }
	
	Point GetPosition() { return mPosition; }
	PlayerInfo GetPlayerInfo();
	int GetTypeChangeResult(int killerType, int victimType);
	int GetType(){ return mType; }
	int GetTeam(){ return mTeam; }
	int GetRadius(){ return mRadius; }
	int GetGameId(){ return mGameId; }
	ClientSession* GetClient(){ return mClient; }

	bool Damaged(int damage, Player* player); // return value : true - die, false - non-die
	void Heal(int dHP);

	void Update( float dTime );
	bool CouldGoPosition(Point position);

	void ConsumeItem(Item* item);
	void DropItem(Item* item);

	bool HasDamageBuff(){ return mDamageBuff != nullptr; }
	bool HasHPBuff(){ return mHPBuff != nullptr; }
	bool HasFlag(){ return mFlag != nullptr; }

private:
	void SetHP(int hp) {mHP = hp;}
	void ChangeType(int type);
	void TransState(short state);
	void InitWithType();
};

