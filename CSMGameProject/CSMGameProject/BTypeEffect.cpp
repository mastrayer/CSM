
#include "BTypeEffect.h"

BTypeEffect::BTypeEffect(CPlayer* follower)
{
	mFollower = follower;
	mDirection = mFollower->GetPlayerRotation();
	SetPosition(mFollower->GetPlayerPosition());

	mAnimation = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 30; i++)
	{
		wsprintf(temp, L"Sprite/WaterSkill/%d.png", i);

		mAnimation->AddFrameNode(temp);
	}
	mAnimation->SetFrameTimeInSection(0.03f, 0, 29);
	
	mLifeTime = mAnimation->GetPlayTime();

	AddChild(mAnimation);
}
BTypeEffect::~BTypeEffect()
{
}

void BTypeEffect::Render()
{
	IEffect::Render();
}
void BTypeEffect::Update(float dTime)
{
	IEffect::Update(dTime);

	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}