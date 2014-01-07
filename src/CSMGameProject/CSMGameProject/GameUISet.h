
#pragma once

#include "NNUISet.h"
#include "NNLabel.h"
#include "NNSprite.h"
#include "Player.h"
#include "PlayerManager.h"
#include "EffectManager.h"
#include "NNInputSystem.h"
#include "config.h"

#define SKILL_COUNT 2

class CStatusWindow : public NNObject
{
public:
	CStatusWindow();
	virtual ~CStatusWindow();
	void Init();

	void Render();
	void Update(float dTime);

	void GetAllPlayerInfo();

	
	NNCREATE_FUNC(CStatusWindow);
private:
	wchar_t mLabelBuf[MAX_PLAYER_LEN][256];
	NNLabel *mPlayerLabelList[MAX_PLAYER_LEN];
	wchar_t mKillScoreBuf[MAX_PLAYER_LEN][10];
	NNLabel *mPlayerKillScoreList[MAX_PLAYER_LEN];
	NNSprite *mPanel;
};

class GameUISet : public NNUISet
{
public:
	static GameUISet* GetInstance();
	static void ReleaseInstance();

	GameUISet();
	virtual ~GameUISet();
	void Init();

	void Render();
	void Update(float dTime);

	void SetSkillCooldown(PlayerState type) { mIsCooldown[type - TYPE_ACTIVE_SKILL] = true; }

	void ControlSkillTimer(float dTime);

private:
	static GameUISet* mInstance;

	NNLabel* mFPSLabel;

	NNSprite *mTypeSkillUI[5];
	NNSprite *mUserSkillUI;

	NNLabel *mTypeSKillTimer;
	NNLabel *mUserSkillTimer;
	float mSkillCooltime[PlayerType::TYPE_D + 1]; // +1 for userskill
	float mNowSkillCooltime[SKILL_COUNT];
	wchar_t mSkillCooltimeBuff[2][10];
	bool mIsCooldown[SKILL_COUNT];

	NNSprite *mCharacterUIFrame;
	NNSprite *mSkillUIFrame;
	NNSprite *mTypeFace[5];
	NNSprite *mHpBar;
	NNSprite *mHpBarBackground;
	NNSprite *mKillBar[2];
	wchar_t mKillBuf[2][10];
	
	NNSprite *mCrown;

	NNLabel *mKillPoint[2];
	NNLabel *mType;
	
	CPlayer *mMyPlayer;
	wchar_t mFPSLabelBuff[100];

	CStatusWindow *mStatusWindow;
	
	friend class Player;
};