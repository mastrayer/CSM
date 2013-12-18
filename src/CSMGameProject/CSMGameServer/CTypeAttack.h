#pragma once
#include "Skill.h"
#include "Player.h"
class CTypeAttack : public Skill
{
	
public:
	CTypeAttack(float angle, Point startPosition, Player* ownerPlayer);
	virtual ~CTypeAttack(void);
	virtual void Update(float dTime);
	virtual bool IsLive();

private:
	float mLifeTime;
	float mAngle;
	Point mStartPosition;
	float mExploseRadius;
	float mDamage;
	Player* mOwnerPlayer;
};

