
#include "UserEffect.h"

UserEffect::UserEffect(CPlayer* follower)
{
	m_Follower = follower;
	m_LifeTime = 1.f;
	SetPosition(follower->GetPlayerPosition());

	m_UserEffect = NNParticleSystem::Create(L"Sprite/fire.jpg");
	m_UserEffect->SetMinStartSpeed(300.f);
	m_UserEffect->SetMaxStartSpeed(400.f);
	m_UserEffect->SetMinEndSpeed(400.f);
	m_UserEffect->SetMaxEndSpeed(500.f);

	m_UserEffect->SetCreateParticlePerSecond(60);
	m_UserEffect->SetSpreadDegree(15.f);
	m_UserEffect->SetMinLifeTime(0.5f);
	m_UserEffect->SetMaxLifeTime(0.5f);
	m_UserEffect->SetDirection(m_Follower->GetPlayerRotation());

	m_UserEffect->SetMinStartRodiusX( 50.f );
	m_UserEffect->SetMinStartRodiusY( 50.f );
	m_UserEffect->SetMaxStartRodiusX( 100.f );
	m_UserEffect->SetMaxStartRodiusY( 100.f );
	
	AddChild(m_UserEffect);
	
}
UserEffect::~UserEffect()
{
}

void UserEffect::Render()
{
	IEffect::Render();
}
void UserEffect::Update( float dTime )
{
	IEffect::Update( dTime );
	SetPosition(m_Follower->GetPlayerPosition());
}