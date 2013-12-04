
#pragma once

#include "NNUISet.h"
#include "NNLabel.h"
#include "NNSprite.h"
#include "Player.h"
#include "PlayerManager.h"

class GameUISet : public NNUISet
{
public:
	GameUISet();
	virtual ~GameUISet();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(GameUISet);

private:
	NNLabel* m_FPSLabel;
	NNSprite *m_UserSkillUI;
	NNSprite *m_TypeSkillUI;
	NNSprite *m_UserSkillBarEffect;
	NNSprite *m_TypeSkillBarEffect;
	NNSprite *m_CharacterFace;
	NNSprite *m_HpBar;
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