
#include "ATypeEffect.h"

ATypeEffect::ATypeEffect(CPlayer* follower)
{
	mFollower = follower;
	mLifeTime = 1.f;
	SetPosition(mFollower->GetPlayerPosition());

	mTypeEffect = NNParticleSystem::Create(L"Sprite/FlashEffect.png");

	mTypeEffect->SetMinStartSpeed(100.f);
	mTypeEffect->SetMaxStartSpeed(110.f);
	mTypeEffect->SetMinEndSpeed(120.f);
	mTypeEffect->SetMaxEndSpeed(130.f);

	mTypeEffect->SetCreateParticlePerSecond(60);
	mTypeEffect->SetSpreadDegree(360.f);
	mTypeEffect->SetMinLifeTime(0.5f);
	mTypeEffect->SetMaxLifeTime(0.5f);

	mTypeEffect->SetMinStartRodiusX( 50.f );
	mTypeEffect->SetMinStartRodiusY( 50.f );
	mTypeEffect->SetMaxStartRodiusX( 60.f );
	mTypeEffect->SetMaxStartRodiusY( 60.f );

	AddChild(mTypeEffect);
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
	SetPosition(mFollower->GetPlayerPosition());

	if (mLifeTime < mNowLifeTime)
	{	
		mTypeEffect->SetCreate(false);

		if (mTypeEffect->GetCount() == 0)
			mIsEnd = true;
	}
}