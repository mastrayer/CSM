#include "stdafx.h"
#include "CTypeSkillBullet.h"
#include "ClientManager.h"

CTypeSkillBullet::CTypeSkillBullet(Player* ownerPlayer, Point position, float angle):Bullet(ownerPlayer)
{
	mIsTeamKill = true;
	mVelocity = 0;
	SetPosition(position);
	SetAngle(angle);
	SetShape(CIRCLE);
	SetRadius(7);
	SetDamage(9);
	mDidExplosed = false;
	SetLifeTime(0.9);
	mAcceleraction = 800.f;
}


CTypeSkillBullet::~CTypeSkillBullet(void)
{
}

void CTypeSkillBullet::Update(float dTime)
{
	Bullet::Update(dTime);
}

bool CTypeSkillBullet::isLive()
{
	return mLifeTime < 0;
}

void CTypeSkillBullet::Hit(Player* victimPlayer, Player* attackerPlayer)
{
	if(std::find(mHitPlayer.begin(), mHitPlayer.end(), victimPlayer->GetPlayerInfo().mPlayerId) == mHitPlayer.end() )
	{
		mHitPlayer.push_back(victimPlayer->GetPlayerInfo().mPlayerId);
		victimPlayer->Damaged(mDamage, attackerPlayer);
		mDidExplosed = false;
		CTypeAttackEndResult outPacket = CTypeAttackEndResult();
		outPacket.mIndex = GetBulletNumber();
		GClientManager->BroadcastPacket(nullptr,&outPacket);
	}
}