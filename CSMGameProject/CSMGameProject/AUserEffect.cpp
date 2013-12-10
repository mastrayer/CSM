#include "AUserEffect.h"

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
void AUserEffect::Update( float dTime )
{
	IEffect::Update( dTime );
	SetPosition(mFollower->GetPlayerPosition());

	if (mLifeTime < mNowLifeTime)
	{
		mPaticleEffect->SetCreate(false);
		
		if (mPaticleEffect->GetCount() == 0)
			mIsEnd = true;
	}
}