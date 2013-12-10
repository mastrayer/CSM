
#include "BUserEffect.h"

BUserEffect::BUserEffect(CPlayer* follower)
{
	mAnimation = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 40; i++)
	{
		wsprintf(temp, L"Sprite/FireSkill/%d.png", i);

		mAnimation->AddFrameNode(temp);
	}
	mAnimation->SetFrameTimeInSection(0.05f, 0, 39);
	mAnimation->SetFrameTimeInSection(0.1f, 0, 20);

	mFollower = follower;
	mLifeTime = mAnimation->GetPlayTime();
	SetPosition(mFollower->GetPlayerPosition());

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

	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}