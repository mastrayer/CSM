
#pragma once

#include "NNLabel.h"
#include "NNScene.h"
#include "NNSprite.h"
#include "NNSound.h"

enum MENU_LIST
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
	NNSprite * m_MainMenuImage;
	NNSprite * m_MainMenuSellcetionBar;
	NNLabel *m_MainMenuLable[3];
	NNSound *m_BGM;

	unsigned int m_MenuSellction;
	//NNLabel * m_StartLabel;
	//NNLabel * m_ExitLabel;
};