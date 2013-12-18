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
		wsprintf(temp, L"Resource/Sprite/SkillEffect/UserSkill/Flash/%d.png", i);

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

Heal::Heal(CPlayer* follower)
{
	mAnimation = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 25; i++)
	{
		wsprintf(temp, L"Resource/Sprite/SkillEffect/UserSkill/Heal/%d.png", i);

		mAnimation->AddFrameNode(temp);
	}
	mAnimation->SetFrameTimeInSection(0.05f, 0, 24);

	mFollower = follower;
	mLifeTime = mAnimation->GetPlayTime();
	SetPosition(mFollower->GetPlayerPosition());

	mAnimation->SetPosition(-65.f, -65.f);

	AddChild(mAnimation);
}
Heal::~Heal()
{
}
void Heal::Render()
{
	IEffect::Render();
}
void Heal::Update(float dTime)
{
	IEffect::Update(dTime);
	SetPosition(mFollower->GetPlayerPosition());

	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}

Immolation::Immolation(CPlayer* follower)
{
	mFollower = follower;
	mLifeTime = 0.7f;

	SetPosition(follower->GetPlayerPosition());

	mPaticleEffect = NNParticleSystem::Create(L"Resource/Sprite/SkillEffect/UserSkill/Immolation/0.png");
	mPaticleEffect->SetMinStartSpeed(10.f);
	mPaticleEffect->SetMaxStartSpeed(10.f);
	mPaticleEffect->SetMinEndSpeed(10.f);
	mPaticleEffect->SetMaxEndSpeed(10.f);

	mPaticleEffect->SetCreateParticlePerSecond(120);

	mPaticleEffect->SetMinStartScaleX(1.f);
	mPaticleEffect->SetMaxStartScaleX(1.f);
	mPaticleEffect->SetMinStartScaleY(1.f);
	mPaticleEffect->SetMaxStartScaleY(1.f);

	mPaticleEffect->SetMinEndScaleX(0.f);
	mPaticleEffect->SetMaxEndScaleX(0.f);
	mPaticleEffect->SetMinEndScaleY(0.f);
	mPaticleEffect->SetMaxEndScaleY(0.f);

	mPaticleEffect->SetMinStartRotationSpeed(0.f);
	mPaticleEffect->SetMaxStartRotationSpeed(0.f);
	mPaticleEffect->SetMinEndRotationSpeed(0.f);
	mPaticleEffect->SetMaxEndRotationSpeed(0.f);

	mPaticleEffect->SetMinLifeTime(0.4f);
	mPaticleEffect->SetMaxLifeTime(0.7f);

	mPaticleEffect->SetMinStartRodiusX(50.f);
	mPaticleEffect->SetMinStartRodiusY(50.f);
	mPaticleEffect->SetMaxStartRodiusX(50.f);
	mPaticleEffect->SetMaxStartRodiusY(50.f);

	mPaticleEffect->SetPosition(0.f, -10.f);
	AddChild(mPaticleEffect);

}
Immolation::~Immolation()
{
}
void Immolation::Render()
{
	IEffect::Render();
}
void Immolation::Update(float dTime)
{
	IEffect::Update(dTime);
	SetPosition(mFollower->GetPlayerPosition());

	if (mLifeTime < mNowLifeTime)
	{
		mPaticleEffect->SetCreate(false);

		if (mPaticleEffect->GetCount() == 0)
			mIsEnd = true;
	}
}