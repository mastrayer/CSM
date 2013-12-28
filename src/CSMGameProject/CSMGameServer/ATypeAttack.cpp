#include "stdafx.h"
#include "ATypeAttack.h"
#include "Bullet.h"
#include "SkillManager.h"
#include "ClientManager.h"
#include "ATypeAttackBullet.h"
#include "BulletManager.h"

ATypeAttack::ATypeAttack(float angle, Point startPosition, Player* ownerPlayer):mOwnerPlayer(ownerPlayer),mLifeTime(0.f),mAngle(angle),mStartPosition(startPosition),mExploseRadius(50),mDamage(10)
{
	GSkillManager->AddSkill(this);
	ATypeAttackBullet* bullet = new ATypeAttackBullet(mOwnerPlayer,mStartPosition,mAngle);
	ATypeAttackShootResult outPacket = ATypeAttackShootResult();
	outPacket.mAngle = mAngle;
	outPacket.mIndex = bullet->GetBulletNumber();
	outPacket.mStartPosition = mStartPosition;
	GClientManager->BroadcastPacket(nullptr,&outPacket);
}


ATypeAttack::~ATypeAttack(void)
{
}

void ATypeAttack::Update(float dTime)
{
	mLifeTime -= dTime;
}
bool ATypeAttack::IsLive()
{
	if(mLifeTime < 0)
	{
		return false;
	}
	return true;
}