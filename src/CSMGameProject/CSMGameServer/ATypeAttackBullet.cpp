#include "stdafx.h"
#include "ATypeAttackBullet.h"
#include "ClientManager.h"


ATypeAttackBullet::ATypeAttackBullet(Player* ownerPlayer, Point position, float angle):Bullet(ownerPlayer)
{
	mVelocity = 500;
	SetPosition(position);
	SetAngle(angle);
	SetShape(CIRCLE);
	SetRadius(10);
	SetDamage(10);
	SetLifeTime(0.5f);
	mDidExplosed = false;
}


ATypeAttackBullet::~ATypeAttackBullet(void)
{
}

void ATypeAttackBullet::Update(float dTime)
{
	Bullet::Update(dTime);
}

bool ATypeAttackBullet::isLive()
{
	return !mDidExplosed && mLifeTime >= 0;
}

void ATypeAttackBullet::Hit(Player* victimPlayer, Player* attackerPlayer)
{
	victimPlayer->Damaged(mDamage, attackerPlayer);
	mDidExplosed = true;
	mLifeTime = -1;
	ATypeAttackEndResult outPacket = ATypeAttackEndResult();
	outPacket.mIndex = GetBulletNumber();
	GClientManager->BroadcastPacket(nullptr,&outPacket);
}