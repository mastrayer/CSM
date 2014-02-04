#include "stdafx.h"
#include "CTypeSkill.h"
#include "Bullet.h"
#include "SkillManager.h"
#include "ClientManager.h"
#include "CTypeSkillBullet.h"
CTypeSkill::CTypeSkill(float angle, Point startPosition, Player* ownerPlayer):Skill(ownerPlayer),mLifeTime(0.f),mAngle(angle),mStartPosition(startPosition)
{
	GSkillManager->AddSkill(this);

	CTypeSkillBullet* bullet = new CTypeSkillBullet(ownerPlayer,startPosition,angle);

	CTypeSkillShootResult outPacket = CTypeSkillShootResult();
	outPacket.mAngle = mAngle;
	outPacket.mStartPosition = mStartPosition;
	GClientManager->BroadcastPacket(nullptr,&outPacket, mOwnerPlayer->GetGameId());
}


CTypeSkill::~CTypeSkill(void)
{
}

void CTypeSkill::Update(float dTime)
{
	mLifeTime -= dTime;
}
bool CTypeSkill::IsLive()
{
	if(mLifeTime < 0)
	{
		return false;
	}
	return true;
}