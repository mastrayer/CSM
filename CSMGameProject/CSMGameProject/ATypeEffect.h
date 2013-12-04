
#pragma once

#include "Effect.h"
#include "NNParticleSystem.h"
#include "Player.h"

class ATypeEffect : public IEffect
{
public:
	ATypeEffect(CPlayer* follower);
	virtual ~ATypeEffect();

	void Render();
	void Update( float dTime );

private:
	NNParticleSystem *m_TypeEffect;
	CPlayer* m_Follower;
};