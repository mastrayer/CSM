#include "stdafx.h"
#include "Bullet.h"
#include "BulletManager.h"

Bullet::Bullet(void):mShape(CIRCLE),mVelocity(0),mAcceleraction(0),mAngle(0),mLifeTime(-1),mRotation(0),mPosition(Point()),mOnwerPlayer(nullptr),mDamage(0),mRadius(0),mXRadius(0),mYRadius(0),mWidth(0),mHeight(0),mCenter(Point()),mNumber(-1)
{
	GBulletManager->AddBullet(this);
}


Bullet::~Bullet(void)
{
}

void Bullet::Update(float dTime)
{
	mLifeTime -= dTime;

	mPosition = mPosition + Point( cos(mAngle) * mVelocity , sin(mAngle) * mVelocity ) * dTime;

	mVelocity = mVelocity + mAcceleraction * dTime;
}

void Bullet::JudgeCollision(Player* player)
{
	if(player->GetTeam() != mOnwerPlayer->GetTeam())
	{
		player->Damaged(mDamage);
		mLifeTime = -1;
	}
}
bool Bullet::isLive()
{
	if(mLifeTime < 0) return true;
	return false;
}