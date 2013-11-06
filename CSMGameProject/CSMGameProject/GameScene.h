#pragma once
#include "NNScene.h"
#include "GameMap.h"
#include "Character.h"
#include "NNLabel.h"
class CGameScene :
	public NNScene
{
private:
	CGameMap* m_GameMap;
	CCharacter* m_Character;
	NNLabel* m_FPSLbael;
	wchar_t m_FPSLabelBuff[100];
public:
	CGameScene(void);
	virtual ~CGameScene(void);

	
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CGameScene);
};

