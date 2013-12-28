
#pragma once

#include "StoryCut.h"
#include "NNSprite.h"
#include "NNLabel.h"

class FirstCut : public StoryCut
{
public:
	FirstCut();
	virtual ~FirstCut();

	void Init(){}
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(FirstCut);
private:
	NNSprite* mBackground;
	NNSprite *mStoryTextBox;
	NNLabel* mText;
};