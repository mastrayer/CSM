
#pragma once

#include "Effect.h"
#include <list>
#include "TypeB.h"

class EffectManager : public NNObject
{
public:
	void Render();
	void Update( float dTime );

	void AddEffect( IEffect* effect , int zIndex=0);

	static EffectManager* GetInstance()
	{
		static EffectManager* pInstance = new EffectManager();
		return pInstance;
	}
	BTypeSkillEffect* GetTypeBEffect(int index);
private:
	std::list<IEffect*> mEffectList;

private:
	EffectManager();
	virtual ~EffectManager();
	void Init() {};
};