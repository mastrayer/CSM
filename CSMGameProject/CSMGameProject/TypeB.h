
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"
#include "PlayerManager.h"

class BTypeSkillEffect : public IEffect
{
public:
	BTypeSkillEffect(NNPoint startPosition, NNPoint targetPosition, int index);
	virtual ~BTypeSkillEffect();

	void Render();
	void Update(float dTime);
	NNPoint FindTarget(NNPoint startPosition);
	void Explose();

	int GetIndex(){ return mIndex; }

private:
	bool mIsCrash;
	int mIndex;
	float mMoveSpeed;
	float mDirection;
	NNPoint mSource;
	NNPoint mDestination;
	NNAnimation *mFlyAnimation;
	NNAnimation *mExplosionAnimation;
	CPlayer* mFollower;
};
class BTypeAttackEffect : public IEffect
{
public:
	BTypeAttackEffect(float angle, NNPoint startPoint);
	virtual ~BTypeAttackEffect();

	void Render();
	void Update(float dTime);
	void Explose();

private:
	bool mIsCrash;
	NNAnimation *mBullet;
	NNAnimation *mExplosion;
	float mAngle;
	float mSpeed;
	CPlayer *mFollower;
};