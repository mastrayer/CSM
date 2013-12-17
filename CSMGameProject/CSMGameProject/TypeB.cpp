
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
	mIsCrash = false;

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

	if (!mIsCrash && mLifeTime < mNowLifeTime)
		Explose();
	if (mIsCrash && mLifeTime < mNowLifeTime)
		mIsEnd = true;
}
void BTypeEffect::Explose()
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

	mIsCrash = true;
}

BTypeAttackEffect::BTypeAttackEffect(float angle, NNPoint startPosition)
{
	mSprite = NNSprite::Create(L"sprite/SkillEffect/B/Attack/0.png");

	SetRotation(angle);
	SetPosition(startPosition);

	mAngle = angle;
	mSpeed = 500.f;
	mLifeTime = 0.3f;
	//SetCenter(-30.f, 20.f);

	AddChild(mSprite);
}
BTypeAttackEffect::~BTypeAttackEffect()
{
}

void BTypeAttackEffect::Render()
{
	IEffect::Render();
}
void BTypeAttackEffect::Update(float dTime)
{
	IEffect::Update(dTime);

	this->SetPosition(this->GetPositionX() + mSpeed * std::cosf(mAngle) * dTime, this->GetPositionY() + mSpeed * std::sinf(mAngle) * dTime);

	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}
