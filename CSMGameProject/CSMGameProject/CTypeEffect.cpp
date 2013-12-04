
#include "CTypeEffect.h"

CTypeEffect::CTypeEffect(CPlayer* follower)
{
	m_Follower = follower;
	m_LifeTime = 1.f;
	SetPosition(m_Follower->GetPlayerPosition());
}
CTypeEffect::~CTypeEffect()
{
}

void CTypeEffect::Render()
{
	IEffect::Render();
}
void CTypeEffect::Update(float dTime)
{
	IEffect::Update(dTime);
	SetPosition(m_Follower->GetPlayerPosition());

	if (m_LifeTime < m_NowLifeTime)
		m_IsEnd = true;
}