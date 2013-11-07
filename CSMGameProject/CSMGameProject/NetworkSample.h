
#ifdef _DEBUG

#pragma once

#include "NNScene.h"

class NetworkSample : public NNScene
{
public:
	NetworkSample();
	virtual ~NetworkSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(NetworkSample);

private:
};

#endif