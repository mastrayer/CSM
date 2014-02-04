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
	EndOfGameHandler* mEndOfGameHandler;
	ATypeSkillShootHandler* mATypeSkillShootHandler;
	ATypeAttackEndHandler* mATypeAttackEndHandler;
	ATypeAttackShootHandler* mATypeAttackShootHandler;
	UserSkillFlashHandler* mUserSkillFlashHandler;

	BTypeAttackEndHandler* mBTypeAttackEndHandler;
	BTypeAttackShootHandler* mBTypeAttackShootHandler;
	BTypeSkillShootHandler* mBTypeSkillShootHandler;

	
	CTypeAttackEndHandler* mCTypeAttackEndHandler;
	CTypeAttackShootHandler* mCTypeAttackShootHandler;
	CTypeSkillShootHandler* mCTypeSkillShootHandler;

	
	DTypeAttackShootHandler* mDTypeAttackShootHandler;
	DTypeSkillShootHandler* mDTypeSkillShootHandler;
	DTypeSkillEndHandler* mDTypeSkillEndHandler;

	EmoticonHandler* mEmoticonHandler;

	float mAngle;
	DWORD mLastAngleChangedTime;
	bool misInit;

public:
	CGameScene(std::wstring path, int roomNum, int playerID);
	virtual ~CGameScene(void);
	void Init();

	void GameSet();
	bool IsEnd() { return mGameEnd; }
	void Render();
	void Update( float dTime );

	static CGameScene* Create(std::wstring path , int roomNum, int playerID)
	{
		CGameScene* pInstance = new CGameScene(path, roomNum, playerID);
		pInstance->Init();
		return pInstance;
	}
private:
	NNSprite *mBackgroundImage;
	NNSprite *mIntro1, *mIntro2;
	NNSprite *mVictory, *mDefeat;
	NNSprite *mResultBackground, *mPressEnterKey;
	bool mGameEnd;
	bool mLoadingComplete;
	bool mIsKeyDown;

	GameKeyStates GetNowGameKeyStates();
	bool isChangedGameKeyStates();
	float GetNowAngle();
	bool isChangedAngle();
	CPlayer *mMyPlayer;
	
	int mRoomNumber , mPlyaerId;

	void InitNetworkSetting();
};