#pragma once
#include "NNObject.h"
class CCharacter :
	public NNObject
{
public:
	CCharacter(void);
	virtual ~CCharacter(void);
	
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CCharacter);
};

