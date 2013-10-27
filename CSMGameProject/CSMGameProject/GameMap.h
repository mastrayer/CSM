#pragma once
#include "NNObject.h"
#include "NNSprite.h"
class CGameMap :
	public NNObject
{
public:
	NNSprite* m_MapSprite;

public:
	CGameMap(void);
	virtual ~CGameMap(void);
	
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CGameMap);
};

