
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"
#include "PlayerManager.h"

class BTypeEffect : public IEffect
{
public:
	BTypeEffect(CPlayer* follower);
	virtual ~BTypeEffect();

	void Render();
	void Update(float dTime);
	NNPoint FindTarget();
	void Explosion();

private:
	bool mIsCrash;
	float mMoveSpeed;
	float mDirection;
	NNPoint mSource;
	NNPoint mDestination;
	NNAnimation *mFlyAnimation;
	NNAnimation *mExplosionAnimation;
	CPlayer* mFollower;
};