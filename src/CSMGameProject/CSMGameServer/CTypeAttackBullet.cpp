#include "stdafx.h"
#include "CTypeAttackBullet.h"
#include "ClientManager.h"


CTypeAttackBullet::CTypeAttackBullet(Player* ownerPlayer, Point position, float angle):Bullet(ownerPlayer)
{
	mIsTeamKill = false;
	mVelocity = 1000;
	SetPosition(position);
	SetAngle(angle);
	SetShape(CIRCLE);
	SetRadius(4);
	SetDamage(4);
	mDidExplosed = false;
	SetLifeTime(0.3);
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
	Boom();
}

void CTypeAttackBullet::Boom()
{
	mDidExplosed = false;
	mLifeTime = -1;
	CTypeAttackEndResult outPacket = CTypeAttackEndResult();
	outPacket.mIndex = GetBulletNumber();
	GClientManager->BroadcastPacket(nullptr,&outPacket);
}