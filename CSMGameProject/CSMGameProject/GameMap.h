
#pragma once

#include "NNObject.h"
#include "NNSprite.h"

class CGameMap : public NNObject
{
public:
	CGameMap(void);
	virtual ~CGameMap(void);
	
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(CGameMap);

private:
	NNSprite* m_MapSprite;
};