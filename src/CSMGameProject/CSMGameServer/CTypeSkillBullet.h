#pragma once
#include "Bullet.h"
class CTypeSkillBullet : public Bullet
{
public:
	CTypeSkillBullet(Player* ownerPlayer, Point position, float angle);
	virtual ~CTypeSkillBullet(void);

	virtual bool isLive(void);
	virtual void Update(float dTime);
	virtual void Hit(Player* victimPlayer, Player* attackerPlayer);

private:
	bool mDidExplosed;
};

