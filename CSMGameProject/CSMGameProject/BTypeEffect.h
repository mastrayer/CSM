
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"

class BTypeEffect : public IEffect
{
public:
	BTypeEffect(CPlayer* follower);
	virtual ~BTypeEffect();

	void Render();
	void Update(float dTime);

private:
	NNAnimation *mAnimation;
	CPlayer* mFollower;
};