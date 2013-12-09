
#pragma once

#include "NNUISet.h"
#include "NNLabel.h"
#include "NNSprite.h"
#include "Player.h"
#include "PlayerManager.h"
#include "EffectManager.h"

class GameUISet : public NNUISet
{
public:
	GameUISet();
	virtual ~GameUISet();

	void Render();
	void Update(float dTime);

	void ControlSkillUI(PlayerState skillType, float dTime);

	float GetUserSkillCooltime() { return m_UserSkillCooltime; }
	float GetTypeSkillCooltime() { return m_TypeSkillCooltime; }

	void SetUserSkillCooltime(float value) { m_UserSkillCooltime = value; }
	void SetTypeSkillCooltime(float value) { m_TypeSkillCooltime = value; }

	NNCREATE_FUNC(GameUISet);

private:
	NNLabel* m_FPSLabel;

	NNSprite *m_SkillUI[SKILL_COUNT];
	NNSprite *m_SkillBarEffect[SKILL_COUNT];
	NNLabel *m_SkillTimer[SKILL_COUNT];
	float m_SkillCooltime[SKILL_COUNT];

	NNSprite *m_UserSkillUI;
	NNSprite *m_TypeSkillUI;
	//NNSprite *m_UserSkillBarEffect;
	//NNSprite *m_TypeSkillBarEffect;
	NNSprite *m_CharacterUIFrame;
	NNSprite *m_SkillUIFrame;
	NNSprite *m_CharacterFace;
	NNSprite *m_HpBar;
	NNSprite *m_HpBarBackground;
	NNLabel *m_UserSkillTimer;
	NNLabel *m_TypeSkillTimer;

	int m_Hp;
	CPlayer *m_MyPlayer;
	wchar_t m_FPSLabelBuff[100];
	//int m_KillCount;
	float m_UserSkillCooltime;
	float m_TypeSkillCooltime;

	friend class Player;
};