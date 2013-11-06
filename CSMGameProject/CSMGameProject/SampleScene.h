
#pragma once

#ifdef _DEBUG

#include "NNObject.h"

class SampleScene : public NNObject
{
public:
	SampleScene();
	virtual ~SampleScene();

	void Render();
	void Update( float eTime );

	NNCREATE_FUNC(SampleScene);
};

#endif