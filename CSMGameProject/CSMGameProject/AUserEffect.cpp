#include "AUserEffect.h"

AUserEffect::AUserEffect(CPlayer* follower)
{
	mFollower = follower;
	mLifeTime = 0.5f;
	mSpeed = 500.f;
	mDirection = mFollower->GetPlayerRotation()*3.14 / 180.f;

	SetPosition(follower->GetPlayerPosition());

	NNSprite *image = NNSprite::Create(L"Sprite/arrow.png");
	image->SetRotation(mFollower->GetPlayerRotation());
	AddChild(image);

// 	mUserEffect = NNParticleSystem::Create(L"Sprite/fire.jpg");
// 	mUserEffect->SetMinStartSpeed(300.f);
// 	mUserEffect->SetMaxStartSpeed(400.f);
// 	mUserEffect->SetMinEndSpeed(400.f);
// 	mUserEffect->SetMaxEndSpeed(500.f);
// 
// 	mUserEffect->SetCreateParticlePerSecond(60);
// 	mUserEffect->SetSpreadDegree(15.f);
// 	mUserEffect->SetMinLifeTime(0.5f);
// 	mUserEffect->SetMaxLifeTime(0.5f);
// 	mUserEffect->SetDirection(mFollower->GetPlayerRotation());
// 
// 	mUserEffect->SetMinStartRodiusX( 50.f );
// 	mUserEffect->SetMinStartRodiusY( 50.f );
// 	mUserEffect->SetMaxStartRodiusX( 100.f );
// 	mUserEffect->SetMaxStartRodiusY( 100.f );
	
//	AddChild(mUserEffect);
	
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
	//SetPosition(mFollower->GetPlayerPosition());

	if (mLifeTime < mNowLifeTime)
	{
		mIsEnd = true;
		SetVisible(false);
	}
	//mspeed * std::cosf(mangle) * dTime

	this->SetPosition(this->GetPositionX() + mSpeed * std::cosf(mDirection) * dTime, this->GetPositionY() + mSpeed * std::sinf(mDirection) * dTime);
}