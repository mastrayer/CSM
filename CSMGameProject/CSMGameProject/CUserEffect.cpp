
#include "CUserEffect.h"

CUserEffect::CUserEffect(CPlayer* follower)
{
	mSrcAnimation = NNAnimation::Create(25, 0.03f,
		L"Sprite/FlashSkill/light_004_001.png",
		L"Sprite/FlashSkill/light_004_002.png",
		L"Sprite/FlashSkill/light_004_003.png",
		L"Sprite/FlashSkill/light_004_004.png",
		L"Sprite/FlashSkill/light_004_005.png",
		L"Sprite/FlashSkill/light_004_006.png",
		L"Sprite/FlashSkill/light_004_007.png",
		L"Sprite/FlashSkill/light_004_008.png",
		L"Sprite/FlashSkill/light_004_009.png",
		L"Sprite/FlashSkill/light_004_010.png",
		L"Sprite/FlashSkill/light_004_011.png",
		L"Sprite/FlashSkill/light_004_012.png",
		L"Sprite/FlashSkill/light_004_013.png",
		L"Sprite/FlashSkill/light_004_014.png",
		L"Sprite/FlashSkill/light_004_015.png",
		L"Sprite/FlashSkill/light_004_016.png",
		L"Sprite/FlashSkill/light_004_017.png",
		L"Sprite/FlashSkill/light_004_018.png",
		L"Sprite/FlashSkill/light_004_019.png",
		L"Sprite/FlashSkill/light_004_020.png",
		L"Sprite/FlashSkill/light_004_021.png",
		L"Sprite/FlashSkill/light_004_022.png",
		L"Sprite/FlashSkill/light_004_023.png",
		L"Sprite/FlashSkill/light_004_024.png",
		L"Sprite/FlashSkill/light_004_025.png");

	mDstAnimation = NNAnimation::Create(25, 0.03f,
		L"Sprite/FlashSkill/light_004_001.png",
		L"Sprite/FlashSkill/light_004_002.png",
		L"Sprite/FlashSkill/light_004_003.png",
		L"Sprite/FlashSkill/light_004_004.png",
		L"Sprite/FlashSkill/light_004_005.png",
		L"Sprite/FlashSkill/light_004_006.png",
		L"Sprite/FlashSkill/light_004_007.png",
		L"Sprite/FlashSkill/light_004_008.png",
		L"Sprite/FlashSkill/light_004_009.png",
		L"Sprite/FlashSkill/light_004_010.png",
		L"Sprite/FlashSkill/light_004_011.png",
		L"Sprite/FlashSkill/light_004_012.png",
		L"Sprite/FlashSkill/light_004_013.png",
		L"Sprite/FlashSkill/light_004_014.png",
		L"Sprite/FlashSkill/light_004_015.png",
		L"Sprite/FlashSkill/light_004_016.png",
		L"Sprite/FlashSkill/light_004_017.png",
		L"Sprite/FlashSkill/light_004_018.png",
		L"Sprite/FlashSkill/light_004_019.png",
		L"Sprite/FlashSkill/light_004_020.png",
		L"Sprite/FlashSkill/light_004_021.png",
		L"Sprite/FlashSkill/light_004_022.png",
		L"Sprite/FlashSkill/light_004_023.png",
		L"Sprite/FlashSkill/light_004_024.png",
		L"Sprite/FlashSkill/light_004_025.png");

	mFollower = follower;
	mLifeTime = mSrcAnimation->GetPlayTime() * 1.3f;
	mDirection = mFollower->GetPlayerRotation();
	mDistance = 100.f;
	mDstAnimationStart = false;
	mDstAnimation->SetVisible(false);
	mSrcAnimation->SetLoop(false);

	SetPosition(mFollower->GetPlayerPosition().GetX() - 65.f, mFollower->GetPlayerPosition().GetY() - 65.f);
	mDstPoint.SetPoint(mFollower->GetPlayerPosition().GetX() + mDistance * std::cosf(mDirection), mFollower->GetPlayerPosition().GetY() + mDirection * std::sinf(mDirection));

	AddChild(mSrcAnimation);
	AddChild(mDstAnimation);
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
	//SetPosition(mFollower->GetPlayerPosition());

	if (!mDstAnimationStart && mNowLifeTime >= mLifeTime / 3)
	{
		mDstAnimationStart = true;
		mDstAnimation->SetPosition(mDstPoint);
		mDstAnimation->SetVisible(true);
	}
	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}