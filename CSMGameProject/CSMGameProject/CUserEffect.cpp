
#include "CUserEffect.h"

CUserEffect::CUserEffect(CPlayer* follower)
{
	mFollower = follower;
	mLifeTime = 1.f;
	SetPosition(mFollower->GetPlayerPosition());
}
CUserEffect::~CUserEffect()
{
}

void CUserEffect::Render()
{
	IEffect::Render();
}
void CUserEffect::Update(float dTime)
{
	IEffect::Update(dTime);
	SetPosition(mFollower->GetPlayerPosition());

	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}