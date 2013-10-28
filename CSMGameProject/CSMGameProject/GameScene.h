#pragma once
#include "NNScene.h"
#include "GameMap.h"
#include "Character.h"
class CGameScene :
	public NNScene
{
private:
	CGameMap* m_GameMap;
	CCharacter* m_Character;
public:
	CGameScene(void);
	virtual ~CGameScene(void);

	
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CGameScene);
};

