
#include "BUserEffect.h"

BUserEffect::BUserEffect(CPlayer* follower)
{
	mAnimation = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 25; i++)
	{
		wsprintf(temp, L"Sprite/HealSkill/%d.png", i);

		mAnimation->AddFrameNode(temp);
	}
	mAnimation->SetFrameTimeInSection(0.05f, 0, 24);

	mFollower = follower;
	mLifeTime = mAnimation->GetPlayTime();
	SetPosition(mFollower->GetPlayerPosition());

	mAnimation->SetPosition(-65.f, -65.f);

	AddChild(mAnimation);
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