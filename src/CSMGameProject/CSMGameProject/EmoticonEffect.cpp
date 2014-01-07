#include "EmoticonEffect.h"
#include "PlayerManager.h"
#include "NNAudioSystem.h"
#include "NNResourceManager.h"

CEmoticonEffect::CEmoticonEffect(int PlayerID, EmoticonType type)
{
	mFollower = CPlayerManager::GetInstance()->FindPlayerByID(PlayerID);

	std::wstring iconPath[4] = { L"Resource/Sprite/UI/Emoticon/Smile.png",
		L"Resource/Sprite/UI/Emoticon/Sad.png",
		L"Resource/Sprite/UI/Emoticon/Angry.png",
		L"Resource/Sprite/UI/Emoticon/Help.png" };
		mIcon = NNSprite::Create(iconPath[type]);

	mLifeTime = 2.f;
	SetCenter(45.f, 40.f);
	SetPosition(mFollower->GetPlayerPosition());
	AddChild(mIcon);
	//NNAudioSystem::GetInstance()->Play(NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/earth_attack.wav"));
	mFollower->SetEmoticonRunning(true);
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
	IEffect::Update(dTime);
	SetPosition(mFollower->GetPlayerPosition());

	if (mNowLifeTime >= 0.5f)
		mIcon->SetOpacity(mIcon->GetOpacity() - 0.01f);
	
	if (mLifeTime < mNowLifeTime)
	{
		mFollower->SetEmoticonRunning(false);
		mIsEnd = true;
	}
}