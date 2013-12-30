#include "stdafx.h"
#include "BTypeSkill.h"
#include "SkillManager.h"
#include "ClientManager.h"
#include "BTypeSkillBullet.h"

BTypeSkill::BTypeSkill(Player* ownerPlayer):mOwnerPlayer(ownerPlayer),mLifeTime(0.f),mStartPosition(ownerPlayer->GetPosition()),mHealRadius(50),mHeal(20)
{
	GSkillManager->AddSkill(this);
	BTypeSkillBullet* bullet = new BTypeSkillBullet(ownerPlayer,mStartPosition);
	BTypeSkillShootResult outPacket = BTypeSkillShootResult();
	outPacket.mStartPosition = mStartPosition;
	GClientManager->BroadcastPacket(nullptr,&outPacket);
}


BTypeSkill::~BTypeSkill(void)
{
}

void BTypeSkill::Update(float dTime)
{
	mLifeTime -= dTime;
}
bool BTypeSkill::IsLive()
{
	if(mLifeTime < 0)
	{
		return false;
	}
	return true;
}