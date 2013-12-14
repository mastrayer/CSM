#include "UserSkillEffect.h"
using namespace USER_SKILL;

Flash::Flash(CPlayer* follower)
{
	////////////////////// Set Animation ///////////////////////
	mSrcAnimation = NNAnimation::Create();
	mDstAnimation = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 25; i++)
	{
		wsprintf(temp, L"Sprite/FlashSkill/%d.png", i);

		mSrcAnimation->AddFrameNode(temp);
		mDstAnimation->AddFrameNode(temp);
	}
	mSrcAnimation->SetFrameTimeInSection(0.02f, 0, 24);
	mDstAnimation->SetFrameTimeInSection(0.02f, 0, 24);


	////////////////////// Set Settings ///////////////////////
	mFollower = follower;
	mLifeTime = mSrcAnimation->GetPlayTime() * 1.3f;
	mDirection = mFollower->GetPlayerRotation();
	mDistance = 200.f;
	mDstAnimationStart = false;
	mDstAnimation->SetVisible(false);
	mSrcAnimation->SetLoop(false);

	SetPosition(mFollower->GetPlayerPosition().GetX() - 65.f, mFollower->GetPlayerPosition().GetY() - 65.f);
	mDstPoint.SetPoint(mDistance * std::cosf(mDirection), mDistance * std::sinf(mDirection));

	AddChild(mSrcAnimation);
	AddChild(mDstAnimation);
}
Flash::~Flash()
{
}
void Flash::Render()
{
	IEffect::Render();
}
void Flash::Update(float dTime)
{
	IEffect::Update(dTime);

	if (!mDstAnimationStart && mNowLifeTime >= mLifeTime / 3)
	{
		mDstAnimationStart = true;
		mDstAnimation->SetPosition(mDstPoint);
		mDstAnimation->SetVisible(true);
	}
	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}


Dash::Dash(CPlayer* follower)
{
	mFollower = follower;
	mLifeTime = 1.f;
	mDirection = mFollower->GetPlayerRotation();
	mDistance = 200.f;

	NNSprite *temp = NNSprite::Create(L"Sprite/blur.png");
	temp->SetOpacity(0.05f);
	temp->SetCenter(20.f, 30.f);

	AddChild(temp);
	//mFollower->
	////////////////////// Set Animation ///////////////////////

// 	wchar_t temp[256] = { 0 };
// 	for (int i = 0; i < 25; i++)
// 	{
// 		wsprintf(temp, L"Sprite/FlashSkill/%d.png", i);
// 
// 		mSrcAnimation->AddFrameNode(temp);
// 		mDstAnimation->AddFrameNode(temp);
// 	}
// 	mSrcAnimation->SetFrameTimeInSection(0.02f, 0, 24);
// 	mDstAnimation->SetFrameTimeInSection(0.02f, 0, 24);
// 
// 
// 	////////////////////// Set Settings ///////////////////////
// 	mFollower = follower;
// 	mLifeTime = mSrcAnimation->GetPlayTime() * 1.3f;
// 	mDirection = mFollower->GetPlayerRotation();
// 	mDistance = 200.f;
// 	mDstAnimationStart = false;
// 	mDstAnimation->SetVisible(false);
// 	mSrcAnimation->SetLoop(false);
// 
// 	SetPosition(mFollower->GetPlayerPosition().GetX() - 65.f, mFollower->GetPlayerPosition().GetY() - 65.f);
// 	mDstPoint.SetPoint(mDistance * std::cosf(mDirection), mDistance * std::sinf(mDirection));
// 
// 	AddChild(mSrcAnimation);
// 	AddChild(mDstAnimation);
}
Dash::~Dash()
{
}
void Dash::Render()
{
	IEffect::Render();
}
void Dash::Update(float dTime)
{
	IEffect::Update(dTime);

	SetPosition(mFollower->GetPlayerPosition());
	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}