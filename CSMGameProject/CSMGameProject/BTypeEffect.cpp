
#include "BTypeEffect.h"

BTypeEffect::BTypeEffect(CPlayer* follower)
{
	m_Follower = follower;
	m_LifeTime = 1.f;
	SetPosition(m_Follower->GetPlayerPosition());
}
BTypeEffect::~BTypeEffect()
{
}

void BTypeEffect::Render()
{
	IEffect::Render();
}
void BTypeEffect::Update(float dTime)
{
	IEffect::Update(dTime);
	SetPosition(m_Follower->GetPlayerPosition());

	if (m_LifeTime < m_NowLifeTime)
		m_IsEnd = true;
}