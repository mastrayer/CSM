#pragma once
#include "Player.h"
#include "Skill.h"
class ATypeSkill : public Skill
{
public:
	ATypeSkill();
	ATypeSkill(float angle, Point startPosition);
	virtual ~ATypeSkill(void);
	virtual void Update(float dTime);
	virtual bool IsLive();
private:
	float mLifeTime;
	float mAngle;
	Point mStartPosition;
	float mExploseRadius;
	float mDamage;
	float mExploseDistance;
	float mBoomTimeDistance;
	bool didFirstBoomFinish;
	bool didSecondBoomFinish;
	bool didThirdBoomFinish;
};

