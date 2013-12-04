
#pragma once

#include "Effect.h"
#include "NNParticleSystem.h"
#include "Player.h"

class BTypeEffect : public IEffect
{
public:
	BTypeEffect(CPlayer* follower);
	virtual ~BTypeEffect();

	void Render();
	void Update(float dTime);

private:
	CPlayer* m_Follower;
};