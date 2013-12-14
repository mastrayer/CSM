#include "AttackEffect.h"

AttackEffect::AttackEffect(CPlayer* follower)
{
	mAnimation = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 7; i++)
	{
		wsprintf(temp, L"Sprite/FireSkill/%d.png", i);

		mAnimation->AddFrameNode(temp);
	}

	mAnimation->SetFrameTimeInSection(0.02f, 0, 6);

	mFollower = follower;
	mDirection = mFollower->GetPlayerRotation();
	mLifeTime = mAnimation->GetPlayTime();

	SetPosition(mFollower->GetPlayerPosition());
	mAnimation->SetCenter(65.f, 65.f);

	AddChild(mAnimation);
}
AttackEffect::~AttackEffect()
{
}

void AttackEffect::Render()
{
	IEffect::Render();
}
void AttackEffect::Update( float dTime )
{
	IEffect::Update( dTime );

	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}