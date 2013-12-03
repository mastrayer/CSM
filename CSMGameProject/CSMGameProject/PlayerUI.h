
#pragma once

#include "NNObject.h"
#include "NNSprite.h"
#include "NNLabel.h"

class PlayerUI : public NNObject
{
public:
	PlayerUI();
	virtual ~PlayerUI();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(PlayerUI);
private:
	NNSprite* m_HpBar;
	NNSprite* m_HpBarFrame;
	NNSprite *m_UserSkillUI;
	NNSprite *m_TypeSkillUI;
	NNLabel *m_UserSkillTimer;
	NNLabel *m_TypeSkillTimer;

	int m_Hp;
	float m_UserSkillCooltime;
	float m_TypeSkillCooltime;
	
};