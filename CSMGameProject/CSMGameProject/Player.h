
#pragma once

#include "NNObject.h"
#include "NNSprite.h"
#include "NNLabel.h"
#include "NNAnimationAtlas.h"
#include "PacketType.h"
#include "NNParticleSystem.h"

#include "PlayerUI.h"

#define SKILL_COUNT 2

enum PlayerState
{
	IDLE = 0,
	WALK = 1,
	ATTAACK = 2,
	DIE = 3,
	TYPE_ACTIVE_SKILL = 4,
	USER_ACTIVE_SKILL = 5,	
};
enum PlayerType
{
	TYPE_A = 0,
	TYPE_B = 1,
	TYPE_C = 2,
};
class CPlayer : public NNObject
{
public:
	CPlayer(void);
	virtual ~CPlayer(void);
	void Init();
	void InitWithType();
	void TransState( PlayerState state );
	
	void SetPlayerPosition( NNPoint position ) { SetPosition(position); }
	void SetPlayerRotation( float angle ) { SetRotation(angle); /*mAngle = angle; mMove->SetRotation(angle); mStop->SetRotation(angle);*/ }
	void SetPlayerMoveDirection( NNPoint direction) { mMoveVelocity = direction; }
	void SetPlayerHP(int hp) { mHp = hp; }
	void SetSkillCount(float value, PlayerState skillType) { mSkillCount[skillType - TYPE_ACTIVE_SKILL] = value; }
	void SetSkillCooldown(bool value, PlayerState skillType) { mSkillCooldown[skillType - TYPE_ACTIVE_SKILL] = value; }
	void SetPlayerTeam(int team) { mTeam = team; }
	void SetPlayerType( PlayerType type ) { mPlayerType = type; InitWithType(); }
	void SetKillScore( int killScore ) { mKillScore = killScore; }
	
	NNPoint GetPlayerPosition() { return GetPosition(); }
	float GetPlayerRotation( ) { return mRotation; }
	int GetPlayerHP() { return mHp; }
	float GetSkillCount(PlayerState skillType) { return mSkillCount[skillType - TYPE_ACTIVE_SKILL]; }
	bool GetSkillCooldown(PlayerState skillType) { return mSkillCooldown[skillType - TYPE_ACTIVE_SKILL]; }
	PlayerType GetPlayerType() { return mPlayerType; }
	int GetTeam() { return mTeam; }
	int GetKillScore() const { return mKillScore; }

	void CreateSkillEffect(PlayerType type, PlayerState skillType);

	NNCREATE_FUNC(CPlayer);

private:
	void Render();
	void Update( float dTime );

private:
	NNSprite* mDie;
	NNAnimationAtlas* mMove;
	NNSpriteAtlas* mStop;

private:
	std::list<NNParticleSystem*> mParticleSystemList;
	PlayerUI* mPlayerUI;
	PlayerState mPlayerState;
	
	NNParticleSystem *mUserEffect;
	NNPoint mMoveVelocity;
	NNLabel *mRebirthTimer;
	
	float mRebirthDelayTime;
	int mHp;
	int mTeam;
	int mSpeed;

	int mKillScore;

	float mSkillCount[SKILL_COUNT];
	bool mSkillCooldown[SKILL_COUNT];

	PlayerType mPlayerType;

	friend class PlayerManager;
	friend class GameUISet;
};