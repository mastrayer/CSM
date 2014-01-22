
#pragma once

#include "NNLabel.h"
#include "NNScene.h"
#include "NNSprite.h"
#include "NNSound.h"

class LoadScene : public NNScene
{
public:
	LoadScene(std::wstring path, int roomNum, int playerID);
	virtual ~LoadScene();
	void Init() {};


	void Render();
	void Update(float dTime);

	static LoadScene* Create(std::wstring path, int roomNum, int playerID)
	{
		LoadScene* pInstance = new LoadScene(path, roomNum, playerID);
		pInstance->Init();
		return pInstance;
	}

private:
	float mCount;
	NNSprite *mBackgroundImage;
	NNSprite *mIntro;
	std::wstring mPath;
};