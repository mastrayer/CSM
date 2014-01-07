
#pragma once

#include "NNObject.h"
#include "NNSprite.h"
#include "NNLabel.h"
#include "NNAnimation.h"
#include "PacketType.h"
#include "NNParticleSystem.h"

#include "PlayerUI.h"
#include "config.h"

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
	void SetPlayerHP(int hp) { mHp = hp; }	void SetPlayerTeam(int team) { mTeam = team; }
	void SetPlayerType( PlayerType type ) { mPlayerType = type; InitWithType(); }
	void SetKillScore( int killScore ) { mKillScore = killScore; }
	
	NNPoint GetPlayerPosition() { return GetPosition(); }
	float GetPlayerRotation( ) { return mRotation; }
	int GetPlayerHP() { return mHp; }
	PlayerType GetPlayerType() { return mPlayerType; }
	int GetTeam() { return mTeam; }
	int GetKillScore() const { return mKillScore; }
	
	bool IsEmoticonRunning() { return mIsEmoticonRunning; }
	void SetEmoticonRunning(bool value) { mIsEmoticonRunning = value; }

	NNCREATE_FUNC(CPlayer);

private:
	void Render();
	void Update( float dTime );

	void InitStopImage();
	void InitMoveImage();
	void InitAttackImage();
	void INitDieImage();

private:
	NNSprite* mDie;
	NNAnimation* mMoveNormal;
	NNAnimation* mMoveFire;
	NNAnimation* mMoveWind;
	NNAnimation* mMoveWater;
	NNAnimation* mMoveEarth;

	NNAnimation* mStopNormal;
	NNAnimation* mStopFire;
	NNAnimation* mStopWind;
	NNAnimation* mStopWater;
	NNAnimation* mStopEarth;

	NNAnimation* mAttackNormal;
	NNAnimation* mAttackFire;
	NNAnimation* mAttackWind;
	NNAnimation* mAttackWater;
	NNAnimation* mAttackEarth;

	NNAnimation* mDieNormal;
	NNAnimation* mDieFire;
	NNAnimation* mDieWind;
	NNAnimation* mDieWater;
	NNAnimation* mDieEarth;

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

	bool mIsEmoticonRunning;
	PlayerType mPlayerType;

	friend class PlayerManager;
};