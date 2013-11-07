
#pragma once

#include "NNObject.h"

class NNSpriteAtlas : public NNObject
{
public:
	NNSpriteAtlas();
	virtual ~NNSpriteAtlas();

	void Render();
	void Update( float dTime );

	static NNSpriteAtlas* Create( wchar_t* path );

private:
};