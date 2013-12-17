#include "stdafx.h"
#include "BtypeAttackBullet.h"
#include "ClientManager.h"


BTypeAttackBullet::BTypeAttackBullet(Player* ownerPlayer, Point position, float angle):Bullet(ownerPlayer)
{
	mVelocity = 10;
	SetPosition(position);
	SetAngle(angle);
	SetShape(CIRCLE);
	SetRadius(20);
	SetDamage(5);
	mHeal = 10;
	SetLifeTime(1.0f);
}


BTypeAttackBullet::~BTypeAttackBullet(void)
{
}

void BTypeAttackBullet::Update(float dTime)
{
	Bullet::Update(dTime);
}

bool BTypeAttackBullet::isLive()
{
	return !mDidExplosed;
}

void BTypeAttackBullet::Hit(Player* victimPlayer, Player* attackerPlayer)
{
	if(victimPlayer->GetTeam() != attackerPlayer->GetTeam())
	{
		victimPlayer->Damaged(mDamage, attackerPlayer);
	}
	else
	{
		victimPlayer->Heal(mHeal);
	}
	mLifeTime = -1;
	BTypeAttackEndResult outPacket = BTypeAttackEndResult();
	outPacket.mIndex = GetBulletNumber();
	GClientManager->BroadcastPacket(nullptr,&outPacket);
}