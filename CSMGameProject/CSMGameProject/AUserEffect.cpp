#include "AUserEffect.h"

AUserEffect::AUserEffect(CPlayer* follower)
{
	m_Follower = follower;
	m_LifeTime = 0.5f;
	m_Speed = 500.f;
	m_Direction = m_Follower->GetPlayerRotation()*3.14 / 180.f;

	SetPosition(follower->GetPlayerPosition());

	NNSprite *image = NNSprite::Create(L"Sprite/arrow.png");
	image->SetRotation(m_Follower->GetPlayerRotation());
	AddChild(image);

// 	m_UserEffect = NNParticleSystem::Create(L"Sprite/fire.jpg");
// 	m_UserEffect->SetMinStartSpeed(300.f);
// 	m_UserEffect->SetMaxStartSpeed(400.f);
// 	m_UserEffect->SetMinEndSpeed(400.f);
// 	m_UserEffect->SetMaxEndSpeed(500.f);
// 
// 	m_UserEffect->SetCreateParticlePerSecond(60);
// 	m_UserEffect->SetSpreadDegree(15.f);
// 	m_UserEffect->SetMinLifeTime(0.5f);
// 	m_UserEffect->SetMaxLifeTime(0.5f);
// 	m_UserEffect->SetDirection(m_Follower->GetPlayerRotation());
// 
// 	m_UserEffect->SetMinStartRodiusX( 50.f );
// 	m_UserEffect->SetMinStartRodiusY( 50.f );
// 	m_UserEffect->SetMaxStartRodiusX( 100.f );
// 	m_UserEffect->SetMaxStartRodiusY( 100.f );
	
//	AddChild(m_UserEffect);
	
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
	//SetPosition(m_Follower->GetPlayerPosition());

	if (m_LifeTime < m_NowLifeTime)
	{
		m_IsEnd = true;
		SetVisible(false);
	}
	//m_speed * std::cosf(m_angle) * dTime

	this->SetPosition(this->GetPositionX() + m_Speed * std::cosf(m_Direction) * dTime, this->GetPositionY() + m_Speed * std::sinf(m_Direction) * dTime);
}