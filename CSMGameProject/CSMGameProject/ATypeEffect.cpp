#include "ATypeEffect.h"

ATypeEffect::ATypeEffect(float angle, NNPoint startPosition)
{
	for (int i = 0; i < 3;++i)
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
	SetCenter(65.f,65.f);
	mNextExplosionPoint.SetPoint(mDistance * std::cosf(mDirection), mDistance * std::sinf(mDirection));

	mExplosion[0]->SetPosition(mNextExplosionPoint.GetX(), mNextExplosionPoint.GetY());
	for (int i = 0; i < 3; ++i)
	{
		mExplosion[i]->SetLoop(false);
		mExplosion[i]->SetVisible(false);

		if (i>0)
			mExplosion[i]->SetPosition(mExplosion[i-1]->GetPositionX() + mNextExplosionPoint.GetX(), mExplosion[i-1]->GetPositionY() + mNextExplosionPoint.GetY());

		AddChild(mExplosion[i]);
	}


	mExplosion[mIndex]->SetVisible(true);

// 	mTypeEffect = NNParticleSystem::Create(L"Sprite/FlashEffect.png");
// 
// 	mTypeEffect->SetMinStartSpeed(100.f);
// 	mTypeEffect->SetMaxStartSpeed(110.f);
// 	mTypeEffect->SetMinEndSpeed(120.f);
// 	mTypeEffect->SetMaxEndSpeed(130.f);
// 
// 	mTypeEffect->SetCreateParticlePerSecond(60);
// 	mTypeEffect->SetSpreadDegree(360.f);
// 	mTypeEffect->SetMinLifeTime(0.5f);
// 	mTypeEffect->SetMaxLifeTime(0.5f);
// 
// 	mTypeEffect->SetMinStartRodiusX( 50.f );
// 	mTypeEffect->SetMinStartRodiusY( 50.f );
// 	mTypeEffect->SetMaxStartRodiusX( 60.f );
// 	mTypeEffect->SetMaxStartRodiusY( 60.f );
// 
// 	AddChild(mTypeEffect);
}
ATypeEffect::~ATypeEffect()
{
}

void ATypeEffect::Render()
{
	IEffect::Render();
}
void ATypeEffect::Update( float dTime )
{
	IEffect::Update( dTime );

	mTimeCount += dTime;

	if (mIndex < 2 && mTimeCount >= mExplosionTerm)
	{
		mTimeCount -= mExplosionTerm;
		mExplosion[++mIndex]->SetVisible(true);
	}
	if (mLifeTime < mNowLifeTime)
	{	
		mIsEnd = true;
// 		mTypeEffect->SetCreate(false);
// 
// 		if (mTypeEffect->GetCount() == 0)
// 			
	}
}