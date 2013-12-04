#include "EffectManager.h"

EffectManager::EffectManager()
{

}
EffectManager::~EffectManager()
{
	for (auto& iter=m_EffectList.begin(); iter!=m_EffectList.end(); iter++ )
	{
		SafeDelete( *iter );
	}
	m_EffectList.clear();
}

void EffectManager::Render()
{
	NNObject::Render();
}
void EffectManager::Update( float dTime )
{
	NNObject::Update( dTime );
	for (auto& iter=m_EffectList.begin(); iter!=m_EffectList.end(); iter++ )
	{
		if ( (*iter)->m_LifeTime < (*iter)->m_NowLifeTime )
		{
			//SafeDelete( *iter );
			RemoveChild( *iter );
			iter = m_EffectList.erase( iter );
			if ( iter == m_EffectList.end() )
			{
				break;
			}
		}
	}
}

void EffectManager::AddEffect( IEffect* effect )
{
	m_EffectList.push_back( effect );
	AddChild( effect );
}