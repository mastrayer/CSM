
#pragma once

#include "NNObject.h"
#include "NNSprite.h"
#include "NNLabel.h"

class PlayerUI : public NNObject
{
public:
	PlayerUI();
	virtual ~PlayerUI();

	void Init(){}
	void Render();
	void Update( float dTime );

	void SetHP(int hp) { mHp = hp; }

	NNCREATE_FUNC(PlayerUI);
private:
	NNSprite* mHpBar;
	NNSprite* mHpBarFrame;
	int mHp;
};