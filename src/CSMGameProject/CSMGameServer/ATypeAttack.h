#pragma once
#include "Skill.h"
#include "Player.h"
class ATypeAttack : public Skill
{
	
public:
	ATypeAttack(float angle, Point startPosition, Player* ownerPlayer);
	virtual ~ATypeAttack(void);
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

