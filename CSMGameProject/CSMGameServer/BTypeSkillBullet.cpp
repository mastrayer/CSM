
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
	return !mDidExplosed;
}

void BTypeSkillBullet::Hit(Player* victimPlayer, Player* attackerPlayer)
{
	if(victimPlayer->GetTeam() == attackerPlayer->GetTeam())
	{
		victimPlayer->Heal(mHeal);
	}
	mLifeTime = -1;
	BTypeAttackEndResult outPacket = BTypeAttackEndResult();
	outPacket.mIndex = GetBulletNumber();
	GClientManager->BroadcastPacket(nullptr,&outPacket);
}