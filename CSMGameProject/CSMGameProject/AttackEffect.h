
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"

class AttackEffect : public IEffect
{
public:
	AttackEffect(CPlayer* follower);
	virtual ~AttackEffect();

	void Render();
	void Update( float dTime );

private:
	NNAnimation *mAnimation;
	float mDirection;
	CPlayer* mFollower;
};