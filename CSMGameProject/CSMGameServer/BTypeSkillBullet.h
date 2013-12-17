#pragma once
#include "Bullet.h"
class BTypeSkillBullet : public Bullet
{
public:
	BTypeSkillBullet(Player* ownerPlayer, Point position);
	virtual ~BTypeSkillBullet(void);

	virtual bool isLive(void);
	virtual void Update(float dTime);
	virtual void Hit(Player* victimPlayer, Player* attackerPlayer);

private:
	bool mDidExplosed;
	int mHeal;
};

