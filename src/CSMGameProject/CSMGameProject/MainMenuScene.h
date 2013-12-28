
#pragma once

#include "NNLabel.h"
#include "NNScene.h"
#include "NNSprite.h"
#include "NNSound.h"

enum MenuList
{
	MENU_PLAY,
	MENU_STORY,
	MENU_EXIT,
};

class MainMenuScene : public NNScene
{
public:
	MainMenuScene();
	virtual ~MainMenuScene();
	void Init() {};


	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(MainMenuScene);

private:
	NNSprite * mMainMenuImage;
	NNSprite * mMainMenuSellcetionBar;
	NNLabel *mMainMenuLable[3];
	NNSound *mBGM;

	unsigned int mMenuSellction;
	//NNLabel * mStartLabel;
	//NNLabel * mExitLabel;
};