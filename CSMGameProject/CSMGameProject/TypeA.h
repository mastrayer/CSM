
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
class ATypeAttackEffect : public IEffect
{
public :
	ATypeAttackEffect(float angle, NNPoint startPosition);
	virtual ~ATypeAttackEffect();

	void Render();
	void Update(float dTime);

private :
	NNAnimation *mAnimation;
};