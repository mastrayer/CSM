
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

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(IntroScene);

private:
	NNSprite * m_IntroSceneImage;
	NNSprite * m_IntroNextSellcetionImage;
	NNLabel *m_IntroSceneMenu[2];

	unsigned int m_IntroSceneIndex;
	
};