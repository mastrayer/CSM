#include "stdafx.h"
#include "ATypeAttack.h"
#include "Bullet.h"
#include "SkillManager.h"
#include "ClientManager.h"

ATypeAttack::ATypeAttack(float angle, Point startPosition, Player* ownerPlayer):mOwnerPlayer(ownerPlayer),mLifeTime(0.9f),mAngle(angle),mStartPosition(startPosition),mExploseRadius(50),mDamage(10),mExploseDistance(80)
{
	GSkillManager->AddSkill(this);
	ATypeAttackShootResult outPacket = ATypeAttackShootResult();
	outPacket.mAngle = mAngle;
	outPacket.mStartPosition = mStartPosition;
	GClientManager->BroadcastPacket(nullptr,&outPacket);
}


ATypeAttack::~ATypeAttack(void)
{
}

void ATypeAttack::Update(float dTime)
{
	mLifeTime -= dTime;
	Bullet* boom = new Bullet(mOwnerPlayer);
	boom->SetPosition(mStartPosition + Point(cos(mAngle),sin(mAngle)) * mExploseDistance);
	boom->SetShape(CIRCLE);
	boom->SetRadius(mExploseRadius);
	boom->SetDamage(mDamage);
}
bool ATypeAttack::IsLive()
{
	if(mLifeTime < 0)
	{
		return false;
	}
	return true;
}