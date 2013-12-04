
#pragma once

#include "Effect.h"
#include "NNParticleSystem.h"
#include "Player.h"

class UserEffect : public IEffect
{
public:
	UserEffect(CPlayer* follower);
	virtual ~UserEffect();

	void Render();
	void Update( float dTime );

private:
	NNParticleSystem *m_UserEffect;
	CPlayer* m_Follower;
};