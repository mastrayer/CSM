#include "stdafx.h"
#include "BTypeSkillBullet.h"


BTypeSkillBullet::BTypeSkillBullet(Player* ownerPlayer, Point position, float angle):Bullet(ownerPlayer)
{
	mVelocity = 10;
	SetPosition(position);
	SetAngle(angle);
	SetShape(CIRCLE);
	SetRadius(20);
	SetDamage(12);
}


BTypeSkillBullet::~BTypeSkillBullet(void)
{
}

void BTypeSkillBullet::Update(float dTime)
{
	Bullet::Update(dTime);
}

bool BTypeSkillBullet::isLive()
{
	return !mDidExplosed;
}