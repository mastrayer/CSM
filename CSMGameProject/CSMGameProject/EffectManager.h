
#pragma once

#include "Effect.h"
#include <list>

class EffectManager : public NNObject
{
public:
	void Render();
	void Update( float dTime );

	void AddEffect( IEffect* effect );

	static EffectManager* GetInstance()
	{
		static EffectManager* pInstance = new EffectManager();
		return pInstance;
	}
private:
	std::list<IEffect*> m_EffectList;

private:
	EffectManager();
	virtual ~EffectManager();
};