
#include "ATypeEffect.h"

ATypeEffect::ATypeEffect(CPlayer* follower)
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
	SetPosition(m_Follower->GetPlayerPosition());

	if (m_LifeTime < m_NowLifeTime)
	{	
		m_TypeEffect->SetCreate(false);

		if (m_TypeEffect->GetCount() == 0)
			m_IsEnd = true;
	}
}