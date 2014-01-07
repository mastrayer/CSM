
#include "TypeC.h"
#include "NNAudioSystem.h"
#include "NNResourceManager.h"

CTypeSkillEffect::CTypeSkillEffect(NNPoint startPosition, float angle)
{

	mDirection = angle;
	SetPosition(startPosition);
	SetCenter(65.f, 80.f);

	mAnimation = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 30; i++)
	{
		wsprintf(temp, L"Resource/Sprite/SkillEffect/C/TypeSkill/%d.png", i);

		mAnimation->AddFrameNode(temp);
	}
	mAnimation->SetFrameTimeInSection(0.03f, 0, 29);

	mMoveSpeed = 0.0f;
	mLifeTime = mAnimation->GetPlayTime();

	AddChild(mAnimation);

	NNAudioSystem::GetInstance()->Play(NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/wind_skill.wav"));
}
CTypeSkillEffect::~CTypeSkillEffect()
{
}
void CTypeSkillEffect::Render()
{
	IEffect::Render();
}
void CTypeSkillEffect::Update(float dTime)
{
	IEffect::Update(dTime);

	mMoveSpeed += 800.f * dTime;
	this->SetPosition(this->GetPositionX() + mMoveSpeed * std::cosf(mDirection) * dTime, this->GetPositionY() + mMoveSpeed * std::sinf(mDirection) * dTime);
	
	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}

CTypeAttackEffect::CTypeAttackEffect(float angle, NNPoint startPosition, int index):mIndex(index)
{
	mBullet = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 11; i++)
	{
		wsprintf(temp, L"Resource/Sprite/SkillEffect/C/Attack/Bullet/%d.png", i);
		mBullet->AddFrameNode(temp);
	}
	mBullet->SetFrameTimeInSection(0.03f, 0, 10);

	mIsCrash = false;
	mAngle = angle;
	mSpeed = 1000.f;
	mLifeTime = mBullet->GetPlayTime() - 0.03;

	SetPosition(startPosition);
	SetRotation(angle);
	SetCenter(32.f, 32.f);

	AddChild(mBullet);

	NNAudioSystem::GetInstance()->Play(NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/wind_attack.wav"));
}
CTypeAttackEffect::~CTypeAttackEffect()
{
}
void CTypeAttackEffect::Render()
{
	IEffect::Render();
}
void CTypeAttackEffect::Update(float dTime)
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
void CTypeAttackEffect::Explose()
{
	mBullet->SetVisible(false);
	mExplosion = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		wsprintf(temp, L"Resource/Sprite/SkillEffect/C/Attack/Explosion/%d.png", i);

		mExplosion->AddFrameNode(temp);
	}
	mExplosion->SetFrameTimeInSection(0.03f, 0, 9);

	AddChild(mExplosion);

	mNowLifeTime = 0.f;
	mLifeTime = mExplosion->GetPlayTime();

	mIsCrash = true;
}