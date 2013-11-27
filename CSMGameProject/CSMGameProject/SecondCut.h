
#pragma once

#include "StoryCut.h"
#include "NNSprite.h"
#include "NNLabel.h"

class SecondCut : public StoryCut
{
public:
	SecondCut();
	virtual ~SecondCut();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(SecondCut);
private:
	NNSprite* m_Background;
	NNSprite *m_StoryTextBox;

	NNLabel* m_Text;
};