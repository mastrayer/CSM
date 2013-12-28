
#pragma once

#include "NNObject.h"
#include "NNSprite.h"
#include "NNLabel.h"
#include "NNAnimationAtlas.h"
#include "PacketType.h"
#include "NNParticleSystem.h"

#include "PlayerUI.h"
#include "config.h"

#define SKILL_COUNT 2

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
	void SetSkillCount(float value, SkillType type) { mSkillCount[type] = value; }
	void SetSkillCooldown(bool value, SkillType type) { mSkillCooldown[type] = value; }
	void SetPlayerTeam(int team) { mTeam = team; }
	void SetPlayerType( PlayerType type ) { mPlayerType = type; InitWithType(); }
	void SetKillScore( int killScore ) { mKillScore = killScore; }
	
	NNPoint GetPlayerPosition() { return GetPosition(); }
	float GetPlayerRotation( ) { return mRotation; }
	int GetPlayerHP() { return mHp; }
	float GetSkillCount(SkillType type) { return mSkillCount[type]; }
	bool GetSkillCooldown(SkillType type) { return mSkillCooldown[type]; }
	PlayerType GetPlayerType() { return mPlayerType; }
	int GetTeam() { return mTeam; }
	int GetKillScore() const { return mKillScore; }

	void CreateSkillEffect(PlayerType type, SkillType skillType);

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