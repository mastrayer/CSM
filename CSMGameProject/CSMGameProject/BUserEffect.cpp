
#include "BUserEffect.h"

BUserEffect::BUserEffect(CPlayer* follower)
{
	mAnimation = NNAnimation::Create(40, 0.05f,
		L"Sprite/FireSkill/fire_003_001.png",
		L"Sprite/FireSkill/fire_003_002.png",
		L"Sprite/FireSkill/fire_003_003.png",
		L"Sprite/FireSkill/fire_003_004.png",
		L"Sprite/FireSkill/fire_003_005.png",
		L"Sprite/FireSkill/fire_003_006.png",
		L"Sprite/FireSkill/fire_003_007.png",
		L"Sprite/FireSkill/fire_003_008.png",
		L"Sprite/FireSkill/fire_003_009.png",
		L"Sprite/FireSkill/fire_003_010.png",
		L"Sprite/FireSkill/fire_003_011.png",
		L"Sprite/FireSkill/fire_003_012.png",
		L"Sprite/FireSkill/fire_003_013.png",
		L"Sprite/FireSkill/fire_003_014.png",
		L"Sprite/FireSkill/fire_003_015.png",
		L"Sprite/FireSkill/fire_003_016.png",
		L"Sprite/FireSkill/fire_003_017.png",
		L"Sprite/FireSkill/fire_003_018.png",
		L"Sprite/FireSkill/fire_003_019.png",
		L"Sprite/FireSkill/fire_003_020.png",
		L"Sprite/FireSkill/fire_003_021.png",
		L"Sprite/FireSkill/fire_003_022.png",
		L"Sprite/FireSkill/fire_003_023.png",
		L"Sprite/FireSkill/fire_003_024.png",
		L"Sprite/FireSkill/fire_003_025.png",
		L"Sprite/FireSkill/fire_003_026.png",
		L"Sprite/FireSkill/fire_003_027.png",
		L"Sprite/FireSkill/fire_003_028.png",
		L"Sprite/FireSkill/fire_003_029.png",
		L"Sprite/FireSkill/fire_003_030.png",
		L"Sprite/FireSkill/fire_003_031.png",
		L"Sprite/FireSkill/fire_003_032.png",
		L"Sprite/FireSkill/fire_003_033.png",
		L"Sprite/FireSkill/fire_003_034.png",
		L"Sprite/FireSkill/fire_003_035.png",
		L"Sprite/FireSkill/fire_003_036.png",
		L"Sprite/FireSkill/fire_003_037.png",
		L"Sprite/FireSkill/fire_003_038.png",
		L"Sprite/FireSkill/fire_003_039.png",
		L"Sprite/FireSkill/fire_003_040.png");

	mFollower = follower;
	mLifeTime = mAnimation->GetPlayTime();
	SetPosition(mFollower->GetPlayerPosition());

	AddChild(mAnimation);
}
BUserEffect::~BUserEffect()
{
}

void BUserEffect::Render()
{
	IEffect::Render();
}
void BUserEffect::Update(float dTime)
{
	IEffect::Update(dTime);

	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}