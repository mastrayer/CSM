#include "stdafx.h"
#include "CTypeSkill.h"
#include "Bullet.h"
#include "SkillManager.h"
#include "ClientManager.h"

CTypeSkill::CTypeSkill(float angle, Point startPosition, Player* ownerPlayer):mOwnerPlayer(ownerPlayer),mLifeTime(0.f),mAngle(angle),mStartPosition(startPosition)
{
	GSkillManager->AddSkill(this);

	Bullet* bullet = new Bullet(mOwnerPlayer);
	bullet->SetPosition(mStartPosition);
	bullet->SetShape(CIRCLE);
	bullet->SetRadius(7);
	bullet->SetDamage(9);
	bullet->SetAcceleration(800);
	bullet->SetLifeTime(0.9);

	CTypeSkillShootResult outPacket = CTypeSkillShootResult();
	outPacket.mAngle = mAngle;
	outPacket.mStartPosition = mStartPosition;
	GClientManager->BroadcastPacket(nullptr,&outPacket);
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