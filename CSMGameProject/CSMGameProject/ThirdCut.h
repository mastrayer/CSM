
#pragma once

#include "StoryCut.h"
#include "NNSprite.h"
#include "NNLabel.h"

class ThirdCut : public StoryCut
{
public:
	ThirdCut();
	virtual ~ThirdCut();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(ThirdCut);
private:
	NNSprite* m_Background;
	NNSprite *m_StoryTextBox;

	NNLabel* m_Text;
};