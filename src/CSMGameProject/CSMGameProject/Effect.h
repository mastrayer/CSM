
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
	float mLifeTime;
	float mNowLifeTime;
	bool mIsEnd;

	friend class EffectManager;
};