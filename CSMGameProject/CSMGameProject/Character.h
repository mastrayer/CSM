#pragma once
#include "NNObject.h"
#include "NNSprite.h"
#include "NNInputSystem.h"
class CCharacter :
	public NNObject
{
private:
	NNSprite* m_CharacterSprite;
public:
	CCharacter(void);
	virtual ~CCharacter(void);
	
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CCharacter);
};

