
#pragma once

#include "NNScene.h"
#include "StoryCut.h"

class StoryScene : public NNScene
{
public:
	StoryScene();
	virtual ~StoryScene();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(StoryScene);

private:
	StoryCut* m_StoryCut[2];

	int m_CutState;
};