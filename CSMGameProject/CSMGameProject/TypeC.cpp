
#include "TypeC.h"

CTypeEffect::CTypeEffect(CPlayer* follower)
{
	mFollower = follower;
	mDirection = mFollower->GetPlayerRotation();
	SetPosition(mFollower->GetPlayerPosition().GetX() - 65.f, mFollower->GetPlayerPosition().GetY() - 80.f);

	mAnimation = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 30; i++)
	{
		wsprintf(temp, L"Sprite/WindSkill/%d.png", i);

		mAnimation->AddFrameNode(temp);
	}
	mAnimation->SetFrameTimeInSection(0.03f, 0, 29);

	mMoveSpeed = 0.0f;
	mLifeTime = mAnimation->GetPlayTime();

	AddChild(mAnimation);
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

	mMoveSpeed += 600.f * dTime;
	this->SetPosition(this->GetPositionX() + mMoveSpeed * std::cosf(mDirection) * dTime, this->GetPositionY() + mMoveSpeed * std::sinf(mDirection) * dTime);

	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}