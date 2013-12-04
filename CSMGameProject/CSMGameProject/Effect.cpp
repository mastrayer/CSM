
#include "Effect.h"

IEffect::IEffect()
	: m_LifeTime(0.f), m_NowLifeTime(0.f), m_IsEnd(false)
{
}
IEffect::~IEffect()
{
}

void IEffect::Render()
{
	NNObject::Render();
}
void IEffect::Update( float dTime )
{
	NNObject::Update( dTime );

	m_NowLifeTime += dTime;
}