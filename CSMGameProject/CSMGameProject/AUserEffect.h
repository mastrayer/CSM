
#pragma once

#include "Effect.h"
#include "NNParticleSystem.h"
#include "Player.h"

class AUserEffect : public IEffect
{
public:
	AUserEffect(CPlayer* follower);
	virtual ~AUserEffect();

	void Render();
	void Update( float dTime );

private:
	NNParticleSystem *mUserEffect;
	CPlayer* mFollower;
	float mDirection;
	float mSpeed;
};