
#pragma once

#include "NNUISet.h"
#include "NNLabel.h"

class GameUISet : public NNUISet
{
public:
	GameUISet();
	virtual ~GameUISet();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(GameUISet);

private:
	NNLabel* m_FPSLabel;
	wchar_t m_FPSLabelBuff[100];
};