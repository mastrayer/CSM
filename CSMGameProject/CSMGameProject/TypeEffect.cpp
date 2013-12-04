
#include "TypeEffect.h"

TypeEffect::TypeEffect(CPlayer* follower)
{
	m_Follower = follower;
	m_LifeTime = 1.f;
	SetPosition(m_Follower->GetPlayerPosition());

	m_TypeEffect = NNParticleSystem::Create(L"Sprite/FlashEffect.png");

	m_TypeEffect->SetMinStartSpeed(100.f);
	m_TypeEffect->SetMaxStartSpeed(110.f);
	m_TypeEffect->SetMinEndSpeed(120.f);
	m_TypeEffect->SetMaxEndSpeed(130.f);

	m_TypeEffect->SetCreateParticlePerSecond(60);
	m_TypeEffect->SetSpreadDegree(360.f);
	m_TypeEffect->SetMinLifeTime(0.5f);
	m_TypeEffect->SetMaxLifeTime(0.5f);

	m_TypeEffect->SetMinStartRodiusX( 50.f );
	m_TypeEffect->SetMinStartRodiusY( 50.f );
	m_TypeEffect->SetMaxStartRodiusX( 60.f );
	m_TypeEffect->SetMaxStartRodiusY( 60.f );

	AddChild(m_TypeEffect);
}
TypeEffect::~TypeEffect()
{
}

void TypeEffect::Render()
{
	IEffect::Render();
}
void TypeEffect::Update( float dTime )
{
	IEffect::Update( dTime );
	SetPosition(m_Follower->GetPlayerPosition());
}