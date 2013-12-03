
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

	void SetHP(int hp) { m_Hp = hp; }

	NNCREATE_FUNC(PlayerUI);
private:
	NNSprite* m_HpBar;
	NNSprite* m_HpBarFrame;
	int m_Hp;
};