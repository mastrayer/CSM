#pragma once

#include "NNScene.h"
#include "GameMap.h"
#include "Player.h"
#include "NNLabel.h"
#include "NNInputSystem.h"
#include "PacketType.h"
#include "PacketHandler.h"

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
	KillScoreHandler* mPlayerKillScoreHandler;
	ATypeSkillShootHandler* mATypeSkillShootHandler;
	BTypeSkillShootHandler* mBTypeSkillShootHandler;
	CTypeSkillShootHandler* mCTypeSkillShootHandler;

	TypeChangeHandler* mTypeChangeAHandler;
	TypeChangeHandler* mTypeChangeBHandler;
	TypeChangeHandler* mTypeChangeCHandler;
	TypeChangeHandler* mTypeChangeDHandler;


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