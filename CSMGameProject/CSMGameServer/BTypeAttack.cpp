#include "stdafx.h"
#include "BTypeAttack.h"
#include "Bullet.h"
#include "SkillManager.h"
#include "ClientManager.h"

BTypeAttack::BTypeAttack(float angle, Point startPosition, Player* ownerPlayer):mOwnerPlayer(ownerPlayer),mLifeTime(0.9f),mAngle(angle),mStartPosition(startPosition),mExploseRadius(50),mDamage(10),mExploseDistance(80)
{
	GSkillManager->AddSkill(this);
	BTypeAttackShootResult outPacket = BTypeAttackShootResult();
	outPacket.mAngle = mAngle;
	outPacket.mStartPosition = mStartPosition;
	GClientManager->BroadcastPacket(nullptr,&outPacket);
}


BTypeAttack::~BTypeAttack(void)
{
}

void BTypeAttack::Update(float dTime)
{
	mLifeTime -= dTime;
	Bullet* boom = new Bullet(mOwnerPlayer);
	boom->SetPosition(mStartPosition + Point(cos(mAngle),sin(mAngle)) * mExploseDistance);
	boom->SetShape(CIRCLE);
	boom->SetRadius(mExploseRadius);
	boom->SetDamage(mDamage);
}
bool BTypeAttack::IsLive()
{
	if(mLifeTime < 0)
	{
		return false;
	}
	return true;
}