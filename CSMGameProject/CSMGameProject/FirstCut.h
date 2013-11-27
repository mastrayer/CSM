
#pragma once

#include "StoryCut.h"
#include "NNSprite.h"
#include "NNLabel.h"

class FirstCut : public StoryCut
{
public:
	FirstCut();
	virtual ~FirstCut();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(FirstCut);
private:
	NNSprite* m_Background;
	NNSprite *m_StoryTextBox;
	NNLabel* m_Text;
};