#include "LoadScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "NNApplication.h"
#include "NNAudioSystem.h"
#include "NNResourceManager.h"

#include "GameMap.h"

#include "GameScene.h"

LoadScene::LoadScene(std::wstring path, int roomNum, int playerID):mRoomNumber(roomNum), mPlyaerId(playerID), mCount(0.f)
{
	mPath = path;
	NNZip *temp = NNResourceManager::GetInstance()->UnzipFileToMemory(path, L"title");
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
		NNSceneDirector::GetInstance()->ChangeScene(CGameScene::Create(mPath, mRoomNumber,mPlyaerId));
		
}