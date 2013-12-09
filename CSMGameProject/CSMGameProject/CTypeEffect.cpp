
#include "CTypeEffect.h"

CTypeEffect::CTypeEffect(CPlayer* follower)
{
	mFollower = follower;
	mLifeTime = 1.f;
	SetPosition(mFollower->GetPlayerPosition());
}
CTypeEffect::~CTypeEffect()
{
}

void CTypeEffect::Render()
{
	IEffect::Render();
}
void CTypeEffect::Update(float dTime)
{
	IEffect::Update(dTime);
	SetPosition(mFollower->GetPlayerPosition());

	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}