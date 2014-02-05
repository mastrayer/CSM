
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

struct StatusElement
{
	StatusElement() 
	{
		ZeroMemory(mNicknameBuf, sizeof(mNicknameBuf));
		ZeroMemory(mKillBuf, sizeof(mKillBuf));
		mKillLabel = nullptr;
		mNicknameLabel = nullptr;
	}
	wchar_t mNicknameBuf[20];
	wchar_t mKillBuf[20];
	NNLabel *mNicknameLabel;
	NNLabel *mKillLabel;
};
class CStatusWindow : public NNObject
{
public:
	CStatusWindow();
	virtual ~CStatusWindow();
	void Init();

	void Render();
	void Update(float dTime);

	void UpdateScore();
	void SortByKillScore(int *result);


	NNCREATE_FUNC(CStatusWindow);
private:
// 	wchar_t mLabelBuf[MAX_PLAYER_LEN][256];
// 	NNLabel *mPlayerLabelList[MAX_PLAYER_LEN];
// 	wchar_t mKillScoreBuf[MAX_PLAYER_LEN][10];
// 	NNLabel *mPlayerKillScoreList[MAX_PLAYER_LEN];
	StatusElement mElement[MAX_PLAYER_LEN];
	
	wchar_t mTeamKillScoreBuf[3][10];
	NNLabel *mTeamKillScore[3];

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

	//NNLabel* mFPSLabel;

	NNSprite *mTypeSkillUI[5];
	NNSprite *mUserSkillUI;

	NNLabel *mTypeSKillTimer;
	NNLabel *mUserSkillTimer;
	float mSkillCooltime[PlayerType::TYPE_D + 1]; // +1 for userskill
	float mNowSkillCooltime[SKILL_COUNT];
	wchar_t mSkillCooltimeBuff[2][5];
	bool mIsCooldown[SKILL_COUNT];

	NNSprite *mCharacterUIFrame;
	NNSprite *mSkillUIFrame;
	NNSprite *mTypeFace[5];
	/*NNSprite *mHpBar;
	NNSprite *mHpBarBackground;*/
	NNSprite *mKillBar[2];
	wchar_t mKillBuf[2][10];

	NNSprite *mCrown;

	NNSprite *mHelp;
	NNSprite *mHelpPanel;

	NNLabel *mKillPoint[2];
	//NNLabel *mType;

	CPlayer *mMyPlayer;
	//wchar_t mFPSLabelBuff[100];

	CStatusWindow *mStatusWindow;

	friend class Player;
};