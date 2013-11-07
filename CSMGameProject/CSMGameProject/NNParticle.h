
#pragma once

#include "NNObject.h"

class NNParticle : public NNObject
{
public:
	NNParticle();
	virtual ~NNParticle();

	void Render();
	void Update( float dTime );

private:
};