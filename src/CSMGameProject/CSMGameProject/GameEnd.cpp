#include "LoadScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "NNApplication.h"
#include "NNAudioSystem.h"
#include "NNResourceManager.h"

#include "GameMap.h"

#include "GameEnd.h"

CGameEnd::CGameEnd(bool IsWin)
{
	if (IsWin == true) mBackgroundImage = NNSprite::Create(L"Resource/Sprite/GameOver/Victory.png");
	else mBackgroundImage = NNSprite::Create(L"Resource/Sprite/GameOver/Defeat.png");

	AddChild(mBackgroundImage);
	mBackgroundImage->SetPosition(125.f, 185.f);
}

CGameEnd::~CGameEnd()
{
	//NNAudioSystem::GetInstance()->Stop(NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/Loading.mp3"));
}

void CGameEnd::Render()
{
	NNScene::Render();
}

void CGameEnd::Update(float dTime)
{
	NNScene::Update(dTime);

}