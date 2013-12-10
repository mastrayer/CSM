
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"

class BUserEffect : public IEffect
{
public:
	BUserEffect(CPlayer* follower);
	virtual ~BUserEffect();

	void Render();
	void Update(float dTime);

private:
	NNAnimation *mAnimation;
	CPlayer* mFollower;
};