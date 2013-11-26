
#pragma once

#include "NNObject.h"
#include "NNSprite.h"

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
};