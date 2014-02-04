#pragma once
#include "Skill.h"
#include "Player.h"
class BTypeAttack : public Skill
{
	
public:
	BTypeAttack(float angle, Point startPosition, Player* ownerPlayer);
	virtual ~BTypeAttack(void);
	virtual void Update(float dTime);
	virtual bool IsLive();

private:
	float mLifeTime;
	float mAngle;
	Point mStartPosition;
	float mExploseRadius;
	float mDamage;
	float mExploseDistance;
};

