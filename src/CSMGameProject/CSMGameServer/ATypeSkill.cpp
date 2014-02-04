#include "stdafx.h"
#include "ATypeSkill.h"
#include "Bullet.h"
#include "SkillManager.h"
#include "ClientManager.h"

ATypeSkill::ATypeSkill(float angle, Point startPosition, Player* ownerPlayer):Skill(ownerPlayer),mLifeTime(0.9f),mAngle(angle),mStartPosition(startPosition),mExploseRadius(50),mDamage(18),mExploseDistance(80),mbulletTimeDistance(0.3f),didFirstbulletFinish(false),didSecondbulletFinish(false),didThirdbulletFinish(false)
{
	GSkillManager->AddSkill(this);
	ATypeSkillShootResult outPacket = ATypeSkillShootResult();
	outPacket.mAngle = mAngle;
	outPacket.mStartPosition = mStartPosition;
	GClientManager->BroadcastPacket(nullptr,&outPacket, mOwnerPlayer->GetGameId());
}


ATypeSkill::~ATypeSkill(void)
{
}

void ATypeSkill::Update(float dTime)
{
	mLifeTime -= dTime;

	if(didFirstbulletFinish == false && mLifeTime <= 0.85f)
	{
		Bullet* bullet = new Bullet(mOwnerPlayer);
		bullet->SetPosition(mStartPosition + Point(cos(mAngle),sin(mAngle)) * mExploseDistance);
		bullet->SetShape(CIRCLE);
		bullet->SetRadius(mExploseRadius);
		bullet->SetDamage(18);
		bullet->SetLifeTime(0);
		didFirstbulletFinish = true;
	}
	if(didSecondbulletFinish == false && mLifeTime <= 0.55f)
	{
		Bullet* bullet = new Bullet(mOwnerPlayer);
		bullet->SetPosition(mStartPosition + Point(cos(mAngle),sin(mAngle)) * mExploseDistance * 2);
		bullet->SetShape(CIRCLE);
		bullet->SetRadius(mExploseRadius);
		bullet->SetDamage(18);
		bullet->SetLifeTime(0);
		didSecondbulletFinish = true;
	}
	if(didThirdbulletFinish == false && mLifeTime <= 0.25f)
	{
		Bullet* bullet = new Bullet(mOwnerPlayer);
		bullet->SetPosition(mStartPosition + Point(cos(mAngle),sin(mAngle)) * mExploseDistance * 3);
		bullet->SetShape(CIRCLE);
		bullet->SetRadius(mExploseRadius);
		bullet->SetDamage(18);
		bullet->SetLifeTime(0);
		didThirdbulletFinish = true;
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