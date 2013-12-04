
#pragma once

#include "NNObject.h"

class IEffect : public NNObject
{
public:
	IEffect();
	virtual ~IEffect();

	void Render();
	void Update( float dTime );

protected:
	float m_LifeTime;
	float m_NowLifeTime;

	friend class EffectManager;
};