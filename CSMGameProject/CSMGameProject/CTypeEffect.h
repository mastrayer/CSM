
#pragma once

#include "Effect.h"
#include "NNParticleSystem.h"
#include "Player.h"

class CTypeEffect : public IEffect
{
public:
	CTypeEffect(CPlayer* follower);
	virtual ~CTypeEffect();

	void Render();
	void Update(float dTime);

private:
	CPlayer* m_Follower;
};