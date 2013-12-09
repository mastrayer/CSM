
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
	void Init() {};

	void Render();
	void Update(float dTime);

	void ControlSkillUI(PlayerState skillType, float dTime);

	float GetTypeSkillCooltime() { return m_SkillCooltime[0]; }
 	float GetUserSkillCooltime() { return m_SkillCooltime[1]; }
 
	void SetTypeSkillCooltime(float value) { m_SkillCooltime[0] = value; }
	void SetUserSkillCooltime(float value) { m_SkillCooltime[1] = value; }

	NNCREATE_FUNC(GameUISet);

private:
	NNLabel* m_FPSLabel;

	NNSprite *m_SkillUI[SKILL_COUNT];
	NNSprite *m_SkillBarEffect[SKILL_COUNT];
	NNLabel *m_SkillTimer[SKILL_COUNT];
	float m_SkillCooltime[SKILL_COUNT];

	NNSprite *m_CharacterUIFrame;
	NNSprite *m_SkillUIFrame;
	NNSprite *m_CharacterFace;
	NNSprite *m_HpBar;
	NNSprite *m_HpBarBackground;

	int m_Hp;
	CPlayer *m_MyPlayer;
	wchar_t m_FPSLabelBuff[100];
	wchar_t m_SkillCooltimeBuff[2][5];
	//int m_KillCount;

	friend class Player;
};