
#pragma once

#include "StoryCut.h"
#include "NNSprite.h"
#include "NNLabel.h"

class FifthCut : public StoryCut
{
public:
	FifthCut();
	virtual ~FifthCut();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(FifthCut);
private:
	NNSprite* m_Background;
	NNSprite *m_StoryTextBox;

	NNLabel* m_Text;
};