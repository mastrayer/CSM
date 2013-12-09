
#include "BUserEffect.h"

BUserEffect::BUserEffect(CPlayer* follower)
{
	mFollower = follower;
	mLifeTime = 1.f;
	SetPosition(mFollower->GetPlayerPosition());
}
BUserEffect::~BUserEffect()
{
}

void BUserEffect::Render()
{
	IEffect::Render();
}
void BUserEffect::Update(float dTime)
{
	IEffect::Update(dTime);
	SetPosition(mFollower->GetPlayerPosition());

	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}