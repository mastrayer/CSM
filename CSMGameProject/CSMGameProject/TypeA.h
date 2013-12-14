
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"

class ATypeEffect : public IEffect
{
public:
	ATypeEffect(float angle, NNPoint startPosition);
	virtual ~ATypeEffect();

	void Render();
	void Update(float dTime);

private:
	NNAnimation *mExplosion[3];
	float mDistance;
	float mDirection;
	float mExplosionTerm;
	float mTimeCount;
	NNPoint mNextExplosionPoint;
	int mIndex;
};

class AUserEffect : public IEffect
{
public:
	AUserEffect(CPlayer* follower);
	virtual ~AUserEffect();

	void Render();
	void Update(float dTime);

private:
	NNParticleSystem *mPaticleEffect;
	CPlayer* mFollower;
};