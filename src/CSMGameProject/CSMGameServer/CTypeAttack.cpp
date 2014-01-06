#include "stdafx.h"
#include "CTypeAttack.h"
#include "Bullet.h"
#include "SkillManager.h"
#include "ClientManager.h"
#include "CTypeAttackBullet.h"

CTypeAttack::CTypeAttack(float angle, Point startPosition, Player* ownerPlayer):mOwnerPlayer(ownerPlayer),mLifeTime(0.f),mAngle(angle),mStartPosition(startPosition),mExploseRadius(50)
{
	GSkillManager->AddSkill(this);
	CTypeAttackBullet* bullet = new CTypeAttackBullet(mOwnerPlayer,mStartPosition,mAngle);
	CTypeAttackShootResult outPacket = CTypeAttackShootResult();
	outPacket.mAngle = mAngle;
	outPacket.mIndex = bullet->GetBulletNumber();
	outPacket.mStartPosition = mStartPosition;
	GClientManager->BroadcastPacket(nullptr,&outPacket,mOwnerPlayer->GetGameId());
}


CTypeAttack::~CTypeAttack(void)
{
}

void CTypeAttack::Update(float dTime)
{
	mLifeTime -= dTime;
}
bool CTypeAttack::IsLive()
{
	if(mLifeTime < 0)
	{
		return false;
	}
	return true;
}