
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"

class CTypeSkillEffect : public IEffect
{
public:
	CTypeSkillEffect(NNPoint startPosition, float angle);
	virtual ~CTypeSkillEffect();

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
	CTypeAttackEffect(float angle, NNPoint startPoint);
	virtual ~CTypeAttackEffect();

	void Render();
	void Update(float dTime);
	void Explose();

private:
	bool mIsCrash;
	NNAnimation *mBullet;
	NNAnimation *mExplosion;
	float mAngle;
	float mSpeed;
	CPlayer *mFollower;
};