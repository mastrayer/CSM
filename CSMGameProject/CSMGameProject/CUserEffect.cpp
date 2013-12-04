
#include "CUserEffect.h"

CUserEffect::CUserEffect(CPlayer* follower)
{
	m_Follower = follower;
	m_LifeTime = 1.f;
	SetPosition(m_Follower->GetPlayerPosition());
}
CUserEffect::~CUserEffect()
{
}

void CUserEffect::Render()
{
	IEffect::Render();
}
void CUserEffect::Update(float dTime)
{
	IEffect::Update(dTime);
	SetPosition(m_Follower->GetPlayerPosition());

	if (m_LifeTime < m_NowLifeTime)
		m_IsEnd = true;
}