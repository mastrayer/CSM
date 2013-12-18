
#pragma once

#include "NNScene.h"
#include "StoryCut.h"

class StoryScene : public NNScene
{
public:
	StoryScene();
	virtual ~StoryScene();

	void Init(){}
	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(StoryScene);

private:
	StoryCut* mStoryCut[5];

	int mCutState;
};