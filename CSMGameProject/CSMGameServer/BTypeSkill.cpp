#include "stdafx.h"
#include "BTypeSkill.h"
#include "BTypeSkillBullet.h"
#include "SkillManager.h"
#include "ClientManager.h"

BTypeSkill::BTypeSkill(float angle, Point startPosition, Player* ownerPlayer):mOwnerPlayer(ownerPlayer),mLifeTime(0.9f),mAngle(angle),mStartPosition(startPosition),mExploseRadius(50),mDamage(18),mExploseDistance(80),mBoomTimeDistance(0.3f)
{
	GSkillManager->AddSkill(this);
	BTypeSkillShootResult outPacket = BTypeSkillShootResult();
	outPacket.mAngle = mAngle;
	outPacket.mStartPosition = mStartPosition;
	GClientManager->BroadcastPacket(nullptr,&outPacket);
}


BTypeSkill::~BTypeSkill(void)
{
}

void BTypeSkill::Update(float dTime)
{
	mLifeTime -= dTime;

	BTypeSkillBullet* boom = new BTypeSkillBullet(mOwnerPlayer,
		mStartPosition + Point(cos(mAngle),sin(mAngle)) * mExploseDistance,
		mAngle);
}
bool BTypeSkill::IsLive()
{
	if(mLifeTime < 0)
	{
		return false;
	}
	return true;
}