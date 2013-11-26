#pragma once
#include "NNScene.h"
#include "GameMap.h"
#include "Player.h"
#include "NNLabel.h"
#include "NNInputSystem.h"
#include "PacketType.h"
#include "PlayerManager.h"
#include "PacketHandler.h"

class CGameScene :
	public NNScene
{
private:
	CGameMap* m_GameMap;
	NNLabel* m_FPSLabel;
	wchar_t m_FPSLabelBuff[100];
	GameKeyStates m_NowGameKeyStates;
	GameKeyStatesUpdateHandler* m_GameKeyStatesUpdateHandler;
	LoginHandler* m_LoginHandler;
	LoginBroadcastHandler* m_LoginBroadcastHandler;
	LogoutHandler* m_LogoutHandler;
	MouseAngleUpdateHandler* m_MouseAngleUpdateHandler;
	float m_Angle;
	DWORD m_LastAngleChangedTime;

public:
	CGameScene(void);
	virtual ~CGameScene(void);
	
	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CGameScene);

private:
	GameKeyStates GetNowGameKeyStates();
	bool isChangedGameKeyStates();
	float GetNowAngle();
	bool isChangedAngle();
};

