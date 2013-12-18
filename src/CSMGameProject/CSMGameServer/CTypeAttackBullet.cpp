#include "stdafx.h"
#include "CTypeAttackBullet.h"
#include "ClientManager.h"


CTypeAttackBullet::CTypeAttackBullet(Player* ownerPlayer, Point position, float angle):Bullet(ownerPlayer)
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


CTypeAttackBullet::~CTypeAttackBullet(void)
{
}

void CTypeAttackBullet::Update(float dTime)
{
	Bullet::Update(dTime);
}

bool CTypeAttackBullet::isLive()
{
	return !mDidExplosed && mLifeTime >= 0;
}

void CTypeAttackBullet::Hit(Player* victimPlayer, Player* attackerPlayer)
{
	victimPlayer->Damaged(mDamage, attackerPlayer);
	mDidExplosed = false;
	mLifeTime = -1;
	CTypeAttackEndResult outPacket = CTypeAttackEndResult();
	outPacket.mIndex = GetBulletNumber();
	GClientManager->BroadcastPacket(nullptr,&outPacket);
}