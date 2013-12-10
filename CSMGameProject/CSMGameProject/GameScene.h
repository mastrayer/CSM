#pragma once

#include "NNScene.h"
#include "GameMap.h"
#include "Player.h"
#include "NNLabel.h"
#include "NNInputSystem.h"
#include "PacketType.h"
#include "PlayerManager.h"
#include "PacketHandler.h"
#include "EffectManager.h"

#include "GameUISet.h"

class CGameScene : public NNScene
{
private:
	CGameMap* mGameMap;
	GameKeyStates mNowGameKeyStates;
	GameKeyStatesUpdateHandler* mGameKeyStatesUpdateHandler;
	LoginHandler* mLoginHandler;
	LoginBroadcastHandler* mLoginBroadcastHandler;
	LogoutHandler* mLogoutHandler;
	MouseAngleUpdateHandler* mMouseAngleUpdateHandler;
	HPUpdateHandler* mHPUpdateHandler;
	KillScoreHandler* mKillScoreHandler;
	float mAngle;
	DWORD mLastAngleChangedTime;
	bool misInit;

public:
	CGameScene(void);
	virtual ~CGameScene(void);
	void Init();

	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(CGameScene);
private:
	GameKeyStates GetNowGameKeyStates();
	bool isChangedGameKeyStates();
	float GetNowAngle();
	bool isChangedAngle();

	void InitNetworkSetting();
};