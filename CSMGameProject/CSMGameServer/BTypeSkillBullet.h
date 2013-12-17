#pragma once
#include "Bullet.h"
class BTypeSkillBullet : public Bullet
{
public:
	BTypeSkillBullet(Player* ownerPlayer, Point position, float angle);
	virtual ~BTypeSkillBullet(void);

	virtual bool isLive(void);
	virtual void Update(float dTime);
private:
	bool mDidExplosed;
};

