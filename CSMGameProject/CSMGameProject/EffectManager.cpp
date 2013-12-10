#include "EffectManager.h"

EffectManager::EffectManager()
{

}
EffectManager::~EffectManager()
{
	for (auto& iter=mEffectList.begin(); iter!=mEffectList.end(); iter++ )
	{
		SafeDelete( *iter );
	}
	mEffectList.clear();
}

void EffectManager::Render()
{
	NNObject::Render();
}
void EffectManager::Update( float dTime )
{
	NNObject::Update( dTime );
	for (auto& iter=mEffectList.begin(); iter!=mEffectList.end(); iter++ )
	{
		if ( (*iter)->mIsEnd == true )
		{
			//SafeDelete( *iter );
			RemoveChild( *iter );
			iter = mEffectList.erase( iter );
			if ( iter == mEffectList.end() )
			{
				break;   
			}
		}
	}
}

void EffectManager::AddEffect( IEffect* effect , int zIndex)
{
	mEffectList.push_back( effect );
	AddChild( effect , zIndex );
}