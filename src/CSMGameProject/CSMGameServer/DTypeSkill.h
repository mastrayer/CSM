#pragma once
#include "Player.h"
#include "Skill.h"
class DTypeSkill : public Skill
{
public:
	DTypeSkill(float angle, Player* ownerPlayer);
	virtual ~DTypeSkill(void);
	virtual void Update(float dTime);
	virtual bool IsLive();
private:
	float mLifeTime;
	float mAngle;
	float mDamage;
	float mVelocity;
	Player* mOwnerPlayer;
};

