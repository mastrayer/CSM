#pragma once
#include "Player.h"
#include "Skill.h"
class CTypeSkill : public Skill
{
public:
	CTypeSkill(float angle, Point startPosition, Player* ownerPlayer);
	virtual ~CTypeSkill(void);
	virtual void Update(float dTime);
	virtual bool IsLive();
private:
	float mLifeTime;
	float mAngle;
	Point mStartPosition;
};

