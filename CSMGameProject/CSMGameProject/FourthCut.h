
#pragma once

#include "StoryCut.h"
#include "NNSprite.h"
#include "NNLabel.h"

class FourthCut : public StoryCut
{
public:
	FourthCut();
	virtual ~FourthCut();

	void Init(){}
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(FourthCut);
private:
	NNSprite* m_Background;
	NNSprite *m_StoryTextBox;

	NNLabel* m_Text;
};