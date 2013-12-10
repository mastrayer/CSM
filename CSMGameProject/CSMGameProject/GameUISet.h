
#pragma once

#include "NNUISet.h"
#include "NNLabel.h"
#include "NNSprite.h"
#include "Player.h"
#include "PlayerManager.h"
#include "EffectManager.h"

/*
enum KILLPOINT
{
	BLUE = 0,
	RED = 1,
};
*/


class GameUISet : public NNUISet
{
public:
	GameUISet();
	virtual ~GameUISet();
	void Init() {};

	void Render();
	void Update(float dTime);

	void ControlSkillUI(PlayerState skillType, float dTime);

	float GetTypeSkillCooltime() { return mSkillCooltime[0]; }
 	float GetUserSkillCooltime() { return mSkillCooltime[1]; }
 
	void SetTypeSkillCooltime(float value) { mSkillCooltime[0] = value; }
	void SetUserSkillCooltime(float value) { mSkillCooltime[1] = value; }

	NNCREATE_FUNC(GameUISet);

private:
	NNLabel* mFPSLabel;

	NNSprite *mSkillUI[SKILL_COUNT];
	NNSprite *mSkillBarEffect[SKILL_COUNT];
	NNLabel *mSkillTimer[SKILL_COUNT];
	float mSkillCooltime[SKILL_COUNT];

	NNSprite *mCharacterUIFrame;
	NNSprite *mSkillUIFrame;
	NNSprite *mCharacterFace;
	NNSprite *mHpBar;
	NNSprite *mHpBarBackground;
	NNSprite *mKillBar[2];
	
	NNSprite *mCrown;

	NNLabel *mKillPoint[2];
	
	CPlayer *mMyPlayer;
	wchar_t mFPSLabelBuff[100];
	wchar_t mSkillCooltimeBuff[2][5];
	
	friend class Player;
};