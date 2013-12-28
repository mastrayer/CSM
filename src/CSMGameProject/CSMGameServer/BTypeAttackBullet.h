#pragma once
#include "Bullet.h"
class BTypeAttackBullet : public Bullet
{
public:
	BTypeAttackBullet(Player* ownerPlayer, Point position, float angle);
	virtual ~BTypeAttackBullet(void);

	virtual bool isLive(void);
	virtual void Update(float dTime);
	virtual void Hit(Player* victimPlayer, Player* attackerPlayer);
	virtual void Boom();
private:
	bool mDidExplosed;
	int mHeal;
};

