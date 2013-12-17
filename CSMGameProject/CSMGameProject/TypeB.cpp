
#include "TypeB.h"

BTypeSkillEffect::BTypeSkillEffect(NNPoint startPosition)
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
	//mDirection = std::atan2f(targetPosition.GetY() - startPosition.GetX(), targetPosition.GetX() - startPosition.GetX());
	mMoveSpeed = 100.f;
	mIsCrash = false;

	mFlyAnimation->SetRotation(mDirection);

	AddChild(mFlyAnimation);
}
BTypeSkillEffect::~BTypeSkillEffect()
{
}
void BTypeSkillEffect::Render()
{
	IEffect::Render();
}
void BTypeSkillEffect::Update(float dTime)
{
	IEffect::Update(dTime);

	this->SetPosition(this->GetPositionX() + mMoveSpeed * std::cosf(mDirection) * dTime, this->GetPositionY() + mMoveSpeed * std::sinf(mDirection) * dTime);

	if (!mIsCrash && mLifeTime < mNowLifeTime)
		Explose();
	if (mIsCrash && mLifeTime < mNowLifeTime)
		mIsEnd = true;
}
void BTypeSkillEffect::Explose()
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

BTypeAttackEffect::BTypeAttackEffect(float angle, NNPoint startPosition, int index):mIndex(index)
{
	mBullet = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 8; i++)
	{
		wsprintf(temp, L"Sprite/SkillEffect/B/Attack/Bullet/%d.png", i);
		mBullet->AddFrameNode(temp);
	}
	mBullet->SetFrameTimeInSection(0.02f, 0, 5);

	mIsCrash = false;
	mAngle = angle;
	mSpeed = 500.f;
	mLifeTime = 1.0f;

	SetPosition(startPosition);
	SetRotation(angle);
	SetCenter(65.f, 65.f);

	AddChild(mBullet);
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

	if (mIsCrash == false)
		this->SetPosition(this->GetPositionX() + mSpeed * std::cosf(mAngle) * dTime, this->GetPositionY() + mSpeed * std::sinf(mAngle) * dTime);

	if (mLifeTime < mNowLifeTime)
	{
		if (mIsCrash == false)
			Explose();
		else
			mIsEnd = true;
	}

}
void BTypeAttackEffect::Explose()
{
	mBullet->SetVisible(false);
	mExplosion = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 41; i++)
	{
		wsprintf(temp, L"Sprite/SkillEffect/B/Attack/Explosion/%d.png", i);

		mExplosion->AddFrameNode(temp);
	}
	mExplosion->SetFrameTimeInSection(0.02f, 0, 40);

	AddChild(mExplosion);

	SetCenter(15.f, 15.f);
	mNowLifeTime = 0.f;
	mLifeTime = mExplosion->GetPlayTime();

	mIsCrash = true;
}