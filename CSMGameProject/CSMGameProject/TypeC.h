
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"

class CTypeEffect : public IEffect
{
public:
	CTypeEffect(NNPoint startPosition, float angle);
	virtual ~CTypeEffect();

	void Render();
	void Update(float dTime);

private:
	float mMoveSpeed;
	float mDirection;
	NNAnimation *mAnimation;
	CPlayer* mFollower;
};