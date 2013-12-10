
#include "CTypeEffect.h"

CTypeEffect::CTypeEffect(CPlayer* follower)
{
	mFollower = follower;
	mDirection = mFollower->GetPlayerRotation();
	SetCenter(mFollower->GetCenter());
	SetPosition(mFollower->GetPlayerPosition().GetX() - 65.f, mFollower->GetPlayerPosition().GetY() - 80.f);

	mAnimation = NNAnimation::Create(30, 0.03f,
		L"Sprite/WindSkill/wind_003_001.png",
		L"Sprite/WindSkill/wind_003_002.png",
		L"Sprite/WindSkill/wind_003_003.png",
		L"Sprite/WindSkill/wind_003_004.png",
		L"Sprite/WindSkill/wind_003_005.png",
		L"Sprite/WindSkill/wind_003_006.png",
		L"Sprite/WindSkill/wind_003_007.png",
		L"Sprite/WindSkill/wind_003_008.png",
		L"Sprite/WindSkill/wind_003_009.png",
		L"Sprite/WindSkill/wind_003_010.png",
		L"Sprite/WindSkill/wind_003_011.png",
		L"Sprite/WindSkill/wind_003_012.png",
		L"Sprite/WindSkill/wind_003_013.png",
		L"Sprite/WindSkill/wind_003_014.png",
		L"Sprite/WindSkill/wind_003_015.png",
		L"Sprite/WindSkill/wind_003_016.png",
		L"Sprite/WindSkill/wind_003_017.png",
		L"Sprite/WindSkill/wind_003_018.png",
		L"Sprite/WindSkill/wind_003_019.png",
		L"Sprite/WindSkill/wind_003_020.png",
		L"Sprite/WindSkill/wind_003_021.png",
		L"Sprite/WindSkill/wind_003_022.png",
		L"Sprite/WindSkill/wind_003_023.png",
		L"Sprite/WindSkill/wind_003_024.png",
		L"Sprite/WindSkill/wind_003_025.png",
		L"Sprite/WindSkill/wind_003_026.png",
		L"Sprite/WindSkill/wind_003_027.png",
		L"Sprite/WindSkill/wind_003_028.png",
		L"Sprite/WindSkill/wind_003_029.png",
		L"Sprite/WindSkill/wind_003_030.png");

	mMoveSpeed = 00.0f;
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
	SetPosition(mFollower->GetPlayerPosition());

	mMoveSpeed += 600.f * dTime;
	this->SetPosition(this->GetPositionX() + mMoveSpeed * std::cosf(mDirection) * dTime, this->GetPositionY() + mMoveSpeed * std::sinf(mDirection) * dTime);

	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}