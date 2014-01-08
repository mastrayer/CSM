
#pragma once

#include "NNLabel.h"
#include "NNScene.h"
#include "NNSprite.h"
#include "NNSound.h"

class CGameEnd : public NNScene
{
public:
	CGameEnd(bool IsWin);
	virtual ~CGameEnd();
	void Init() {};


	void Render();
	void Update(float dTime);

 	static CGameEnd* Create(bool IsWin)
 	{
		CGameEnd* pInstance = new CGameEnd(IsWin);
 		pInstance->Init();
 		return pInstance;
 	}

private:
	NNSprite *mBackgroundImage;
};