
#pragma once

#include "Effect.h"
#include "NNParticleSystem.h"
#include "Player.h"

class CUserEffect : public IEffect
{
public:
	CUserEffect(CPlayer* follower);
	virtual ~CUserEffect();

	void Render();
	void Update(float dTime);

private:
	CPlayer* m_Follower;
};