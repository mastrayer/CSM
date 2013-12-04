
#include "BUserEffect.h"

BUserEffect::BUserEffect(CPlayer* follower)
{
	m_Follower = follower;
	m_LifeTime = 1.f;
	SetPosition(m_Follower->GetPlayerPosition());
}
BUserEffect::~BUserEffect()
{
}

void BUserEffect::Render()
{
	IEffect::Render();
}
void BUserEffect::Update(float dTime)
{
	IEffect::Update(dTime);
	SetPosition(m_Follower->GetPlayerPosition());

	if (m_LifeTime < m_NowLifeTime)
		m_IsEnd = true;
}