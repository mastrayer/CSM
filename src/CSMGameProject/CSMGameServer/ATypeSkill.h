#pragma once
#include "Player.h"
#include "Skill.h"
class ATypeSkill : public Skill
{
public:
	ATypeSkill(float angle, Point startPosition, Player* ownerPlayer);
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
	float mbulletTimeDistance;
	bool didFirstbulletFinish;
	bool didSecondbulletFinish;
	bool didThirdbulletFinish;
	Player* mOwnerPlayer;
};

