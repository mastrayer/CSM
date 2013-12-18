#include "stdafx.h"
#include "BtypeAttackBullet.h"
#include "ClientManager.h"


BTypeAttackBullet::BTypeAttackBullet(Player* ownerPlayer, Point position, float angle):Bullet(ownerPlayer)
{
	mIsTeamKill = true;
	mVelocity = 500;
	SetPosition(position);
	SetAngle(angle);
	SetShape(CIRCLE);
	SetRadius(10);
	SetDamage(5);
	mHeal = 10;
	mDidExplosed = false;
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
	return !mDidExplosed && mLifeTime >= 0;
}

void BTypeAttackBullet::Hit(Player* victimPlayer, Player* attackerPlayer)
{
	printf("%d -> %d\n",victimPlayer->GetTeam(), attackerPlayer->GetTeam());
	if(victimPlayer->GetTeam() != attackerPlayer->GetTeam())
	{
		victimPlayer->Damaged(mDamage, attackerPlayer);
	}
	else
	{
		victimPlayer->Heal(mHeal);
	}
	mLifeTime = -1;
	mDidExplosed = true;
	BTypeAttackEndResult outPacket = BTypeAttackEndResult();
	outPacket.mIndex = GetBulletNumber();
	GClientManager->BroadcastPacket(nullptr,&outPacket);
}