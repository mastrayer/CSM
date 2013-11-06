
#ifdef _DEBUG

#pragma once

#include "NNScene.h"

class XMLSample : public NNScene
{
public:
	XMLSample();
	virtual ~XMLSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(XMLSample);
};

#endif