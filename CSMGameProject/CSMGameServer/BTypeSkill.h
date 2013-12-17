#pragma once
#include "Player.h"
#include "Skill.h"
class BTypeSkill : public Skill
{
public:
	BTypeSkill(float angle, Point startPosition, Player* ownerPlayer);
	virtual ~BTypeSkill(void);
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
	Player* mOwnerPlayer;
};