#pragma once
#include "Skill.h"
#include "Player.h"
class DTypeAttack : public Skill
{
	
public:
	DTypeAttack(float angle, Point startPosition, Player* ownerPlayer);
	virtual ~DTypeAttack(void);
	virtual void Update(float dTime);
	virtual bool IsLive();

private:
	float mLifeTime;
	float mAngle;
	Point mStartPosition;
};

