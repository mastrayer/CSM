#include "stdafx.h"
#include "BTypeAttack.h"
#include "Bullet.h"
#include "SkillManager.h"
#include "ClientManager.h"
#include "BTypeAttackBullet.h"

BTypeAttack::BTypeAttack(float angle, Point startPosition, Player* ownerPlayer):mOwnerPlayer(ownerPlayer),mLifeTime(0.f),mAngle(angle),mStartPosition(startPosition),mExploseRadius(50),mDamage(10),mExploseDistance(80)
{
	GSkillManager->AddSkill(this);
	BTypeAttackBullet* bullet = new BTypeAttackBullet(mOwnerPlayer,mStartPosition,mAngle);
	BTypeAttackShootResult outPacket = BTypeAttackShootResult();
	outPacket.mAngle = mAngle;
	outPacket.mStartPosition = mStartPosition;
	outPacket.mIndex = bullet->GetBulletNumber();
	GClientManager->BroadcastPacket(nullptr,&outPacket, ownerPlayer->GetGameId());
}


BTypeAttack::~BTypeAttack(void)
{
}

void BTypeAttack::Update(float dTime)
{
	mLifeTime -= dTime;
}
bool BTypeAttack::IsLive()
{
	if(mLifeTime < 0)
	{
		return false;
	}
	return true;
}