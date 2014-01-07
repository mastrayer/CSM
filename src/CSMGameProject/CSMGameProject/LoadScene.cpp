#include "LoadScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "NNApplication.h"
#include "NNAudioSystem.h"
#include "NNResourceManager.h"

#include "GameMap.h"

#include "GameScene.h"

LoadScene::LoadScene(std::wstring path, int roomNum, int playerID)
: mCount(0.f)
{
	mPath = path;
	NNZip *temp = NNResourceManager::GetInstance()->UnzipFileToMemory(path, L"title");
	mBackgroundImage = NNSprite::Create(temp);

	mIntro = NNSprite::Create(L"Resource/Sprite/UI/Loading/intro.png");

	AddChild(mBackgroundImage);
	AddChild(mIntro);
}

LoadScene::~LoadScene()
{
}

void LoadScene::Render()
{
	NNScene::Render();
}

void LoadScene::Update(float dTime)
{
	NNScene::Update(dTime);
 	mCount += dTime;
// 
 	if (mCount >= 0.1f)
		NNSceneDirector::GetInstance()->ChangeScene(CGameScene::Create(mPath));
		
}