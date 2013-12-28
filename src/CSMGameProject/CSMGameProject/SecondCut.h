
#pragma once

#include "StoryCut.h"
#include "NNSprite.h"
#include "NNLabel.h"

class SecondCut : public StoryCut
{
public:
	SecondCut();
	virtual ~SecondCut();

	void Init(){}
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(SecondCut);
private:
	NNSprite* mBackground;
	NNSprite *mStoryTextBox;

	NNLabel* mText;
};