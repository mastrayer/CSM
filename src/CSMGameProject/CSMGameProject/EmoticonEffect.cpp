#include "EmoticonEffect.h"
#include "PlayerManager.h"
#include "NNAudioSystem.h"
#include "NNResourceManager.h"

bool CEmoticonEffect::mIsRunning = false;

CEmoticonEffect::CEmoticonEffect(int PlayerID, EmoticonType type)
{
	if (mIsRunning == true)
		mLifeTime = 0.f;
	else
	{
		std::wstring iconPath[4] = { L"Resource/Sprite/UI/Emoticon/Smile.png",
			L"Resource/Sprite/UI/Emoticon/Sad.png",
			L"Resource/Sprite/UI/Emoticon/Angry.png",
			L"Resource/Sprite/UI/Emoticon/Help.png" };

		mIcon = NNSprite::Create(iconPath[type]);

		mFollower = CPlayerManager::GetInstance()->FindPlayerByID(PlayerID);
		mLifeTime = 1.f;

		SetCenter(45.f, 40.f);
		SetPosition(mFollower->GetPlayerPosition());

		AddChild(mIcon);

		//NNAudioSystem::GetInstance()->Play(NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/earth_attack.wav"));
		mIsRunning = true;
	}
}
CEmoticonEffect::~CEmoticonEffect()
{
}
void CEmoticonEffect::Render()
{
	IEffect::Render();
}
void CEmoticonEffect::Update(float dTime)
{
	if (mLifeTime == 0.f)
	{
		mIsEnd = true;
		return;
	}

	IEffect::Update(dTime);
	SetPosition(mFollower->GetPlayerPosition());
	mIcon->SetOpacity(mIcon->GetOpacity() - 0.01f);
	
	if (mLifeTime < mNowLifeTime)
	{
		mIsEnd = true;
		mIsRunning = false;
	}
}