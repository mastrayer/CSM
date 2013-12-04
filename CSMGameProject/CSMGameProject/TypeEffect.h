
#pragma once

#include "Effect.h"
#include "NNParticleSystem.h"
#include "Player.h"

class TypeEffect : public IEffect
{
public:
	TypeEffect(CPlayer* follower);
	virtual ~TypeEffect();

	void Render();
	void Update( float dTime );

private:
	NNParticleSystem *m_TypeEffect;
	CPlayer* m_Follower;
};