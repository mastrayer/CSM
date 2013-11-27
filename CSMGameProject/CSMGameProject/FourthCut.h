
#pragma once

#include "StoryCut.h"
#include "NNSprite.h"
#include "NNLabel.h"

class FourthCut : public StoryCut
{
public:
	FourthCut();
	virtual ~FourthCut();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(FourthCut);
private:
	NNSprite* m_Background;
	NNLabel* m_Text;
};