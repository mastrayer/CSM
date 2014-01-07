#include "LoadScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "NNApplication.h"
#include "NNAudioSystem.h"
#include "NNResourceManager.h"

#include "GameMap.h"

#include "GameScene.h"

LoadScene::LoadScene(int roomNum, int playerID)
: mCount(0.f)
{

	NNZip *temp = NNResourceManager::GetInstance()->UnzipFileToMemory(L"resource/map/44.csm", L"title");
	mBackgroundImage = NNSprite::Create(temp);

	mIntro = NNSprite::Create(L"Resource/Sprite/UI/Loading/intro.png");

	AddChild(mBackgroundImage);

	NNAudioSystem::GetInstance()->Play(NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/Loading.mp3"));

	AddChild(mIntro);
}

LoadScene::~LoadScene()
{
	NNAudioSystem::GetInstance()->Stop(NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/Loading.mp3"));
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
		NNSceneDirector::GetInstance()->ChangeScene(CGameScene::Create());
		
}