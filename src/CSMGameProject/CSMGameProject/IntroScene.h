
#pragma once

#include "NNLabel.h"
#include "NNScene.h"
#include "NNSprite.h"

enum MENU_LIST
{
	MENU_SKIP,
	MENU_INTRO_EXIT,
};

class IntroScene : public NNScene
{
public:
	IntroScene();
	virtual ~IntroScene();

	void Init(){}
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(IntroScene);

private:
	NNSprite * mIntroSceneImage;
	NNSprite * mIntroNextSellcetionImage;
	NNLabel * mIntroSceneMenu[2];

	unsigned int mIntroSceneIndex;
	
};