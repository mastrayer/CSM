
#include "BTypeEffect.h"

BTypeEffect::BTypeEffect(CPlayer* follower)
{
	mFollower = follower;
	mLifeTime = 6.f;
	SetPosition(mFollower->GetPlayerPosition());

	mAnimation = NNAnimation::Create(30, 0.1f, L"Sprite/WaterSkill/water_005_001.png", 
		L"Sprite/WaterSkill/water_005_002.png", 
		L"Sprite/WaterSkill/water_005_003.png", 
		L"Sprite/WaterSkill/water_005_004.png", 
		L"Sprite/WaterSkill/water_005_005.png", 
		L"Sprite/WaterSkill/water_005_006.png", 
		L"Sprite/WaterSkill/water_005_007.png", 
		L"Sprite/WaterSkill/water_005_008.png", 
		L"Sprite/WaterSkill/water_005_009.png", 
		L"Sprite/WaterSkill/water_005_010.png", 
		L"Sprite/WaterSkill/water_005_011.png", 
		L"Sprite/WaterSkill/water_005_012.png", 
		L"Sprite/WaterSkill/water_005_013.png", 
		L"Sprite/WaterSkill/water_005_014.png", 
		L"Sprite/WaterSkill/water_005_015.png", 
		L"Sprite/WaterSkill/water_005_016.png", 
		L"Sprite/WaterSkill/water_005_017.png", 
		L"Sprite/WaterSkill/water_005_018.png", 
		L"Sprite/WaterSkill/water_005_019.png", 
		L"Sprite/WaterSkill/water_005_020.png", 
		L"Sprite/WaterSkill/water_005_021.png", 
		L"Sprite/WaterSkill/water_005_022.png", 
		L"Sprite/WaterSkill/water_005_023.png", 
		L"Sprite/WaterSkill/water_005_024.png", 
		L"Sprite/WaterSkill/water_005_025.png", 
		L"Sprite/WaterSkill/water_005_026.png", 
		L"Sprite/WaterSkill/water_005_027.png", 
		L"Sprite/WaterSkill/water_005_028.png", 
		L"Sprite/WaterSkill/water_005_029.png", 
		L"Sprite/WaterSkill/water_005_030.png" );

		AddChild(mAnimation);
}
BTypeEffect::~BTypeEffect()
{
}

void BTypeEffect::Render()
{
	IEffect::Render();
}
void BTypeEffect::Update(float dTime)
{
	IEffect::Update(dTime);
	SetPosition(mFollower->GetPlayerPosition());

	if (mLifeTime < mNowLifeTime)
		
		mIsEnd = true;
}