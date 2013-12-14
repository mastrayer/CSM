#include "TypeA.h"

//////////////////////////////////////////////////////////////////////////

ATypeEffect::ATypeEffect(float angle, NNPoint startPosition)
{
	for (int i = 0; i < 3; ++i)
		mExplosion[i] = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 40; i++)
	{
		wsprintf(temp, L"Sprite/FireSkill/%d.png", i);

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
ATypeEffect::~ATypeEffect()
{
}
void ATypeEffect::Render()
{
	IEffect::Render();
}
void ATypeEffect::Update(float dTime)
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

AUserEffect::AUserEffect(CPlayer* follower)
{
	mFollower = follower;
	mLifeTime = 0.7f;

	SetPosition(follower->GetPlayerPosition());

	mPaticleEffect = NNParticleSystem::Create(L"Sprite/fire.jpg");
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
AUserEffect::~AUserEffect()
{
}
void AUserEffect::Render()
{
	IEffect::Render();
}
void AUserEffect::Update(float dTime)
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