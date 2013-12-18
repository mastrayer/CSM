
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"
#include "PlayerManager.h"

class BTypeSkillEffect : public IEffect
{
public:
	BTypeSkillEffect(NNPoint startPosition);
	virtual ~BTypeSkillEffect();

	void Render();
	void Update(float dTime);
	NNPoint FindTarget(NNPoint startPosition);
	//void Explose();


private:
	bool mIsCrash;
	//float mMoveSpeed;
	//float mDirection;
	NNPoint mSource;
	//NNPoint mDestination;
	NNAnimation *mHealAnimation;
	NNAnimation *mExplosionAnimation;
	CPlayer* mFollower;
};
class BTypeAttackEffect : public IEffect
{
public:
	BTypeAttackEffect(float angle, NNPoint startPosition, int index);
	virtual ~BTypeAttackEffect();

	void Render();
	void Update(float dTime);
	
	int GetIndex(){ return mIndex; }
	void Explose();
private:
	bool mIsCrash;
	NNAnimation *mBullet;
	NNAnimation *mExplosion;
	int mIndex;
	float mAngle;
	float mSpeed;
	CPlayer *mFollower;
};