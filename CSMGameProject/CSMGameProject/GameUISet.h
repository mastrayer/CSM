
#pragma once

#include "NNUISet.h"
#include "NNLabel.h"
#include "NNSprite.h"

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
	NNLabel *m_UserSkillTimer;
	NNLabel *m_TypeSkillTimer;

	wchar_t m_FPSLabelBuff[100];
	int m_KillCount;
	float m_UserSkillCooltime;
	float m_TypeSkillCooltime;

};