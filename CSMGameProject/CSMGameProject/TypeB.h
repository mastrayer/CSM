
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"
#include "PlayerManager.h"

class BTypeEffect : public IEffect
{
public:
	BTypeEffect(NNPoint startPosition, NNPoint targetPosition, int index);
	virtual ~BTypeEffect();

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
	BTypeAttackEffect(float angle, NNPoint startPosition);
	virtual ~BTypeAttackEffect();

	void Render();
	void Update(float dTime);

private:
	NNSprite *mSprite;
	float mAngle;
	float mSpeed;
};