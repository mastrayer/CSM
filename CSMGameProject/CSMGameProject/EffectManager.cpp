#include "EffectManager.h"

EffectManager::EffectManager()
{

}
EffectManager::~EffectManager()
{
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
BTypeSkillEffect* EffectManager::GetTypeBEffect(int index)
{
	for(auto& iter=mEffectList.begin(); iter!=mEffectList.end(); iter++ )
	{
		BTypeSkillEffect* bTypeEffect = dynamic_cast<BTypeSkillEffect*>(*iter);
		if(bTypeEffect != nullptr && bTypeEffect->GetIndex() == index)
		{
			return bTypeEffect;
		}
	}
	return nullptr;
}