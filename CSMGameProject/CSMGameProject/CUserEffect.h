
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"

class CUserEffect : public IEffect
{
public:
	CUserEffect(CPlayer* follower);
	virtual ~CUserEffect();

	void Render();
	void Update(float dTime);

private:
	NNAnimation *mSrcAnimation;
	NNAnimation *mDstAnimation;
	bool mDstAnimationStart;
	float mDirection;
	float mDistance;
	NNPoint mDstPoint;
	CPlayer* mFollower;
};