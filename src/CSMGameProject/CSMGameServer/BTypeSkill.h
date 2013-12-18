#pragma once
#include "Player.h"
#include "Skill.h"
class BTypeSkill : public Skill
{
public:
	BTypeSkill(Player* ownerPlayer);
	virtual ~BTypeSkill(void);
	virtual void Update(float dTime);
	virtual bool IsLive();
private:
	float mLifeTime;
	Point mStartPosition;
	float mHealRadius;
	float mHeal;
	Player* mOwnerPlayer;
};