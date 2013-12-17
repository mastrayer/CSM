#pragma once
#include "Bullet.h"
class ATypeAttackBullet : public Bullet
{
public:
	ATypeAttackBullet(Player* ownerPlayer, Point position, float angle);
	virtual ~ATypeAttackBullet(void);

	virtual bool isLive(void);
	virtual void Update(float dTime);
	virtual void Hit(Player* victimPlayer, Player* attackerPlayer);

private:
	bool mDidExplosed;
};

