
#pragma once

#include "StoryCut.h"
#include "NNSprite.h"
#include "NNLabel.h"

class ThirdCut : public StoryCut
{
public:
	ThirdCut();
	virtual ~ThirdCut();

	void Init(){}
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(ThirdCut);
private:
	NNSprite* mBackground;
	NNSprite *mStoryTextBox;

	NNLabel* mText;
};