
#pragma once

#include "Effect.h"
//#include "NNParticleSystem.h"
#include "NNAnimation.h"
#include "Player.h"

class ATypeEffect : public IEffect
{
public:
	ATypeEffect(float angle, NNPoint startPosition);
	virtual ~ATypeEffect();

	void Render();
	void Update( float dTime );

private:
	NNAnimation *mExplosion[3];
	float mDistance;
	float mDirection;
	float mExplosionTerm;
	float mTimeCount;
	NNPoint mNextExplosionPoint;
	int mIndex;
};