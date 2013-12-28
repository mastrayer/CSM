
#include "stdafx.h"
#include "BTypeSkillBullet.h"
#include "ClientManager.h"


BTypeSkillBullet::BTypeSkillBullet(Player* ownerPlayer, Point position):Bullet(ownerPlayer)
{
	mVelocity = 10;
	SetPosition(position);
	SetShape(CIRCLE);
	SetRadius(20);
	mHeal = 20;
	mDidExplosed = false;
	SetLifeTime(0.f);
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
	return !mDidExplosed && mLifeTime >= 0;
}

void BTypeSkillBullet::Hit(Player* victimPlayer, Player* attackerPlayer)
{
	if(victimPlayer->GetTeam() == attackerPlayer->GetTeam())
	{
		victimPlayer->Heal(mHeal);
	}
	Boom();
}
void BTypeSkillBullet::Boom()
{
	mLifeTime = -1;
	mDidExplosed = true;
}