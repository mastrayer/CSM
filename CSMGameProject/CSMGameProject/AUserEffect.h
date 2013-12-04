
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
	NNParticleSystem *m_UserEffect;
	CPlayer* m_Follower;
	float m_Direction;
	float m_Speed;
};