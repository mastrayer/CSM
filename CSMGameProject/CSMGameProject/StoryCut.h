
#pragma once

#include "NNObject.h"

class StoryCut : public NNObject
{
public:
	StoryCut(){}
	virtual ~StoryCut(){}

	void Update( float dTime )
	{
		if ( m_Visible == false )
			return;

		NNObject::Update( dTime );
	}

	void Render()
	{
		if ( m_Visible == false )
			return;

		NNObject::Render();
	}
};