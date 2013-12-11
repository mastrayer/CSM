
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
	void Init() {};
	void InitWithType();
	void TransState( PlayerState state );
	
	void SetPlayerPosition( NNPoint position ) { SetPosition(position); }
	void SetPlayerRotation( float angle ) { mAngle = angle; mMove->SetRotation(angle); mStop->SetRotation(angle); }
	void SetPlayerMoveDirection( NNPoint direction) { mMoveVelocity = direction; }
	void SetPlayerHP(int hp) { mHp = hp; }
	void SetSkillCount(float value, PlayerState skillType) { mSkillCount[skillType - TYPE_ACTIVE_SKILL] = value; }
	void SetSkillCooldown(bool value, PlayerState skillType) { mSkillCooldown[skillType - TYPE_ACTIVE_SKILL] = value; }
	void SetPlayerTeam(int team) { mTeam = team; }
	void SetPlayerType( PlayerType type ) { mPlayerType = type; InitWithType(); }
	
	NNPoint GetPlayerPosition() { return GetPosition(); }
	float GetPlayerRotation( ) { return mAngle; }
	int GetPlayerHP() { return mHp; }
	//NNSprite* GetPlayerSprite() { return mPlayerSprite; }
	float GetSkillCount(PlayerState skillType) { return mSkillCount[skillType - TYPE_ACTIVE_SKILL]; }
	bool GetSkillCooldown(PlayerState skillType) { return mSkillCooldown[skillType - TYPE_ACTIVE_SKILL]; }
	PlayerType GetPlayerType() { return mPlayerType; }
	int GetTeam() { return mTeam; }


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
	//NNSprite* mPlayerSprite;
	PlayerUI* mPlayerUI;
	PlayerState mPlayerState;
	
	NNParticleSystem *mUserEffect;
	// NNParticleSystem *mBuffEffect;
	NNPoint mMoveVelocity;
	NNLabel *mRebirthTimer;
	
	float mRebirthDelayTime;
	float mAngle;
	int mHp;
	int mTeam;
	int mSpeed;

	float mSkillCount[SKILL_COUNT];
	bool mSkillCooldown[SKILL_COUNT];

	PlayerType mPlayerType;

	friend class PlayerManager;
	friend class GameUISet;
};