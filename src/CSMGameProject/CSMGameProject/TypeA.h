
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"

class ATypeSkillEffect : public IEffect
{
public:
	ATypeSkillEffect(float angle, NNPoint startPosition);
	virtual ~ATypeSkillEffect();

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
	ATypeAttackEffect(float angle, NNPoint startPoint, int index);
	virtual ~ATypeAttackEffect();

	void Render();
	void Update(float dTime);
	void Explose();
	
	int GetIndex(){ return mIndex; }
private :
	bool mIsCrash;
	int mIndex;
	NNAnimation *mBullet;
	NNAnimation *mExplosion;
	float mAngle;
	float mSpeed;
	CPlayer *mFollower;
};