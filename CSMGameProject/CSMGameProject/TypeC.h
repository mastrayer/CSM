
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"

class CTypeEffect : public IEffect
{
public:
	CTypeEffect(NNPoint startPosition, float angle);
	virtual ~CTypeEffect();

	void Render();
	void Update(float dTime);

private:
	float mMoveSpeed;
	float mDirection;
	NNAnimation *mAnimation;
	CPlayer* mFollower;
};
class CTypeAttackEffect : public IEffect
{
public:
	CTypeAttackEffect(float angle, NNPoint startPosition);
	virtual ~CTypeAttackEffect();

	void Render();
	void Update(float dTime);

private:
	NNAnimation *mAnimation;
};