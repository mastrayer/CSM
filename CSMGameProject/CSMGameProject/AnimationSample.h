
#ifdef _DEBUG

#pragma once

#include "NNObject.h"
#include "NNAnimation.h"

class AnimationSample : NNObject
{
public:
	AnimationSample();
	virtual ~AnimationSample();

	void Render();
	void Update( float eTime );

	NNCREATE_FUNC(AnimationSample);
};

#endif