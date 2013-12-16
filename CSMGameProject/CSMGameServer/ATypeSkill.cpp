#include "stdafx.h"
#include "ATypeSkill.h"
#include "Bullet.h"
#include "SkillManager.h"
#include "ClientManager.h"

ATypeSkill::ATypeSkill(float angle, Point startPosition, Player* ownerPlayer):mOwnerPlayer(ownerPlayer),mLifeTime(0.9f),mAngle(angle),mStartPosition(startPosition),mExploseRadius(50),mDamage(18),mExploseDistance(80),mBoomTimeDistance(0.3f),didFirstBoomFinish(false),didSecondBoomFinish(false),didThirdBoomFinish(false)
{
	GSkillManager->AddSkill(this);
	ATypeSkillShootResult outPacket = ATypeSkillShootResult();
	outPacket.mAngle = mAngle;
	outPacket.mStartPosition = mStartPosition;
	GClientManager->BroadcastPacket(nullptr,&outPacket);
}


ATypeSkill::~ATypeSkill(void)
{
}

void ATypeSkill::Update(float dTime)
{
	mLifeTime -= dTime;

	if(didFirstBoomFinish == false && mLifeTime <= 0.9f)
	{
		Bullet* boom = new Bullet(mOwnerPlayer);
		Point a = Point(cos(mAngle),sin(mAngle)) * mExploseDistance;
		boom->SetPosition(mStartPosition + Point(cos(mAngle),sin(mAngle)) * mExploseDistance);
		boom->SetShape(CIRCLE);
		boom->SetRadius(mExploseRadius);
		boom->SetDamage(18);
		boom->SetLifeTime(0);
		didFirstBoomFinish = true;
	}
	if(didSecondBoomFinish == false && mLifeTime <= 0.6f)
	{
		Bullet* boom = new Bullet(mOwnerPlayer);
		boom->SetPosition(mStartPosition + Point(cos(mAngle),sin(mAngle)) * mExploseDistance * 2);
		boom->SetShape(CIRCLE);
		boom->SetRadius(mExploseRadius);
		boom->SetDamage(18);
		boom->SetLifeTime(0);
		didSecondBoomFinish = true;
	}
	if(didThirdBoomFinish == false && mLifeTime <= 0.3f)
	{
		Bullet* boom = new Bullet(mOwnerPlayer);
		boom->SetPosition(mStartPosition + Point(cos(mAngle),sin(mAngle)) * mExploseDistance * 3);
		boom->SetShape(CIRCLE);
		boom->SetRadius(mExploseRadius);
		boom->SetDamage(18);
		boom->SetLifeTime(0);
		didSecondBoomFinish = true;
	}
}
bool ATypeSkill::IsLive()
{
	if(mLifeTime < 0)
	{
		return false;
	}
	return true;
}