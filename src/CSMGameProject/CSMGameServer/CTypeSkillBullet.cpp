#include "stdafx.h"
#include "CTypeSkillBullet.h"
#include "ClientManager.h"

CTypeSkillBullet::CTypeSkillBullet(Player* ownerPlayer, Point position, float angle):Bullet(ownerPlayer)
{
	mIsTeamKill = false;
	mVelocity = 0;
	SetPosition(position);
	SetAngle(angle);
	SetShape(CIRCLE);
	SetRadius(24);
	SetDamage(12);
	mDidExplosed = false;
	SetLifeTime(0.9);
	mAcceleraction = 800.f;
}


CTypeSkillBullet::~CTypeSkillBullet(void)
{
}

void CTypeSkillBullet::Update(float dTime)
{
	mLifeTime -= dTime;

	
	mPosition = mPosition + Point( cos(mAngle) * mVelocity , sin(mAngle) * mVelocity ) * dTime;
	
	mVelocity = mVelocity + mAcceleraction * dTime;
}

bool CTypeSkillBullet::isLive()
{
	return mLifeTime >= 0;
}

void CTypeSkillBullet::Hit(Player* victimPlayer, Player* attackerPlayer)
{
	if(std::find(mHitPlayer.begin(), mHitPlayer.end(), victimPlayer->GetPlayerInfo().mPlayerId) == mHitPlayer.end() )
	{
		mHitPlayer.push_back(victimPlayer->GetPlayerInfo().mPlayerId);
		victimPlayer->Damaged(mDamage, attackerPlayer);
	}
}