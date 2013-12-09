
#pragma once

#include "Effect.h"
#include "NNParticleSystem.h"
#include "Player.h"

class BUserEffect : public IEffect
{
public:
	BUserEffect(CPlayer* follower);
	virtual ~BUserEffect();

	void Render();
	void Update(float dTime);

private:
	CPlayer* mFollower;
};