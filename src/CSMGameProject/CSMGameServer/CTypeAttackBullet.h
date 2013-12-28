#pragma once
#include "Bullet.h"
class CTypeAttackBullet : public Bullet
{
public:
	CTypeAttackBullet(Player* ownerPlayer, Point position, float angle);
	virtual ~CTypeAttackBullet(void);

	virtual bool isLive(void);
	virtual void Update(float dTime);
	virtual void Hit(Player* victimPlayer, Player* attackerPlayer);
	virtual void Boom();
private:
	bool mDidExplosed;
};

