
#pragma once

#include "NNObject.h"

class StoryCut : public NNObject
{
public:
	StoryCut(){}
	virtual ~StoryCut(){}

	void Update( float dTime )
	{
		if ( mVisible == false )
			return;

		NNObject::Update( dTime );
	}

	void Render()
	{
		if ( mVisible == false )
			return;

		NNObject::Render();
	}
};