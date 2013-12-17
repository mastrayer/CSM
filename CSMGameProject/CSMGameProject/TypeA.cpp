#include "TypeA.h"

//////////////////////////////////////////////////////////////////////////

ATypeSkillEffect::ATypeSkillEffect(float angle, NNPoint startPosition)
{
	for (int i = 0; i < 3; ++i)
		mExplosion[i] = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 40; i++)
	{
		wsprintf(temp, L"Sprite/SkillEffect/A/TypeSkill/%d.png", i);

		for (int j = 0; j < 3; ++j)
			mExplosion[j]->AddFrameNode(temp);
	}

	for (int i = 0; i < 3; ++i)
		mExplosion[i]->SetFrameTimeInSection(0.02f, 0, 39);

	mDirection = angle;
	mDistance = 80.f;
	mIndex = 0;
	mExplosionTerm = 0.3f;
	mTimeCount = 0.f;
	mLifeTime = mExplosion[0]->GetPlayTime() + mExplosionTerm * 3;

	SetPosition(startPosition);
	SetCenter(65.f, 65.f);
	mNextExplosionPoint.SetPoint(mDistance * std::cosf(mDirection), mDistance * std::sinf(mDirection));

	mExplosion[0]->SetPosition(mNextExplosionPoint.GetX(), mNextExplosionPoint.GetY());
	for (int i = 0; i < 3; ++i)
	{
		mExplosion[i]->SetLoop(false);
		mExplosion[i]->SetVisible(false);

		if (i>0)
			mExplosion[i]->SetPosition(mExplosion[i - 1]->GetPositionX() + mNextExplosionPoint.GetX(), mExplosion[i - 1]->GetPositionY() + mNextExplosionPoint.GetY());

		AddChild(mExplosion[i]);
	}


	mExplosion[mIndex]->SetVisible(true);
}
ATypeSkillEffect::~ATypeSkillEffect()
{
}
void ATypeSkillEffect::Render()
{
	IEffect::Render();
}
void ATypeSkillEffect::Update(float dTime)
{
	IEffect::Update(dTime);

	mTimeCount += dTime;

	if (mIndex < 2 && mTimeCount >= mExplosionTerm)
	{
		mTimeCount -= mExplosionTerm;
		mExplosion[++mIndex]->SetVisible(true);
	}
	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;	
}


ATypeAttackEffect::ATypeAttackEffect(float angle, NNPoint startPosition)
{
	mBullet = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 6; i++)
	{
		wsprintf(temp, L"Sprite/SkillEffect/A/Attack/Bullet/%d.png", i);
		mBullet->AddFrameNode(temp);
	}
	mBullet->SetFrameTimeInSection(0.02f, 0, 5);

	mIsCrash = false;
	mAngle = angle;
	mSpeed = 500.f;
	mLifeTime = 0.8f;

	SetPosition(startPosition);
	SetRotation(angle);
	SetCenter(65.f, 65.f);
	
	AddChild(mBullet);
}
ATypeAttackEffect::~ATypeAttackEffect()
{
}
void ATypeAttackEffect::Render()
{
	IEffect::Render();
}
void ATypeAttackEffect::Update(float dTime)
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
void ATypeAttackEffect::Explose()
{
	mBullet->SetVisible(false);
	mExplosion = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 18; i++)
	{
		wsprintf(temp, L"Sprite/SkillEffect/A/Attack/Explosion/%d.png", i);

		mExplosion->AddFrameNode(temp);
	}
	mExplosion->SetFrameTimeInSection(0.02f, 0, 17);

	AddChild(mExplosion);

	mNowLifeTime = 0.f;
	mLifeTime = mExplosion->GetPlayTime();

	mIsCrash = true;
}