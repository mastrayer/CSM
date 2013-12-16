
#include "TypeB.h"

BTypeEffect::BTypeEffect(NNPoint startPosition, NNPoint targetPosition,int index):mIndex(index)
{
	SetPosition(startPosition);

	mFlyAnimation = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 8; i++)
	{
		wsprintf(temp, L"Sprite/SkillEffect/B/TypeSkill/Fly/%d.png", i);

		mFlyAnimation->AddFrameNode(temp);
	}
	mFlyAnimation->SetFrameTimeInSection(0.03f, 0, 7);

	mLifeTime = 1024*1024;
	mFlyAnimation->SetCenter(30.f, 65.f);
	mDirection = std::atan2f(targetPosition.GetY() - startPosition.GetX(), targetPosition.GetX() - startPosition.GetX());
	mMoveSpeed = 100.f;

	mFlyAnimation->SetRotation(mDirection);

	AddChild(mFlyAnimation);
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

	this->SetPosition(this->GetPositionX() + mMoveSpeed * std::cosf(mDirection) * dTime, this->GetPositionY() + mMoveSpeed * std::sinf(mDirection) * dTime);
}
void BTypeEffect::Explosion()
{
	mFlyAnimation->SetVisible(false);
	mExplosionAnimation = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 41; i++)
	{
		wsprintf(temp, L"Sprite/SkillEffect/B/TypeSkill/Explosion/%d.png", i);

		mExplosionAnimation->AddFrameNode(temp);
	}
	mExplosionAnimation->SetFrameTimeInSection(0.02f, 0, 40);
	mExplosionAnimation->SetCenter(30.f, 65.f);
	mExplosionAnimation->SetRotation(mDirection);

	AddChild(mExplosionAnimation);

	mNowLifeTime = 0.f;
	mLifeTime = mExplosionAnimation->GetPlayTime();

	mIsEnd = true;
}

