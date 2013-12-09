
#pragma once

#include "NNObject.h"

class IEffect : public NNObject
{
public:
	IEffect();
	virtual ~IEffect();
	void Init() {};

	void Render();
	void Update( float dTime );

protected:
	float m_LifeTime;
	float m_NowLifeTime;
	bool m_IsEnd;

	friend class EffectManager;
};