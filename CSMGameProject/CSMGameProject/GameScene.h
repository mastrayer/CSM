#pragma once
#include "NNScene.h"
#include "GameMap.h"
class CGameScene :
	public NNScene
{
private:
	CGameMap* m_GameMap;
public:
	CGameScene(void);
	virtual ~CGameScene(void);

	
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CGameScene);
};

