
#ifdef _DEBUG

#pragma once

#include "NNScene.h"

class SpriteAtlasSample : public NNScene
{
public:
	SpriteAtlasSample();
	virtual ~SpriteAtlasSample();

	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(SpriteAtlasSample);
};

#endif