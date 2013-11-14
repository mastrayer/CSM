#pragma once
#include "NNScene.h"
#include "GameMap.h"
#include "Character.h"
#include "NNLabel.h"
#include "NNInputSystem.h"
#include "Packet.h"

class CGameScene :
	public NNScene
{
private:
	int m_MyPlayerId;
	CGameMap* m_GameMap;
	NNLabel* m_FPSLbael;
	wchar_t m_FPSLabelBuff[100];
	GameKeyStates m_PreGameKeyStates;
	std::map<int,CCharacter*>m_Characters;
	CCharacter* m_MyCharacter;

public:
	CGameScene(void);
	virtual ~CGameScene(void);

	
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CGameScene);

	void SetMyPlayerId(int id);
	CCharacter* NewCharacter(int id);
	void DeleteCharacter(int id);

private:
	
	GameKeyStates GetNowGameKeyStates();
	bool isChangedGameKeyStates();
};

