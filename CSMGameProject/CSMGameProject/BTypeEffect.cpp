
#include "BTypeEffect.h"

BTypeEffect::BTypeEffect(CPlayer* follower)
{
	mFollower = follower;
	mDirection = mFollower->GetPlayerRotation() * 3.14f / 180.f;
	SetCenter(mFollower->GetCenter());
	SetPosition(mFollower->GetPlayerPosition().GetX() - 65.f, mFollower->GetPlayerPosition().GetY() - 80.f);

	mAnimation = NNAnimation::Create(30, 0.03f, 
		L"Sprite/WindSkill/wind_003_001.png",
		L"Sprite/WindSkill/wind_003_002.png",
		L"Sprite/WindSkill/wind_003_003.png", 
		L"Sprite/WindSkill/wind_003_004.png", 
		L"Sprite/WindSkill/wind_003_005.png", 
		L"Sprite/WindSkill/wind_003_006.png", 
		L"Sprite/WindSkill/wind_003_007.png", 
		L"Sprite/WindSkill/wind_003_008.png", 
		L"Sprite/WindSkill/wind_003_009.png", 
		L"Sprite/WindSkill/wind_003_010.png", 
		L"Sprite/WindSkill/wind_003_011.png", 
		L"Sprite/WindSkill/wind_003_012.png", 
		L"Sprite/WindSkill/wind_003_013.png", 
		L"Sprite/WindSkill/wind_003_014.png", 
		L"Sprite/WindSkill/wind_003_015.png", 
		L"Sprite/WindSkill/wind_003_016.png", 
		L"Sprite/WindSkill/wind_003_017.png", 
		L"Sprite/WindSkill/wind_003_018.png", 
		L"Sprite/WindSkill/wind_003_019.png", 
		L"Sprite/WindSkill/wind_003_020.png", 
		L"Sprite/WindSkill/wind_003_021.png", 
		L"Sprite/WindSkill/wind_003_022.png", 
		L"Sprite/WindSkill/wind_003_023.png", 
		L"Sprite/WindSkill/wind_003_024.png", 
		L"Sprite/WindSkill/wind_003_025.png", 
		L"Sprite/WindSkill/wind_003_026.png", 
		L"Sprite/WindSkill/wind_003_027.png", 
		L"Sprite/WindSkill/wind_003_028.png", 
		L"Sprite/WindSkill/wind_003_029.png", 
		L"Sprite/WindSkill/wind_003_030.png" );

// 	mAnimation = NNAnimation::Create(30, 0.03f, 
// 		L"Sprite/WaterSkill/water_005_001.png",
// 		L"Sprite/WaterSkill/water_005_002.png",
// 		L"Sprite/WaterSkill/water_005_003.png", 
// 		L"Sprite/WaterSkill/water_005_004.png", 
// 		L"Sprite/WaterSkill/water_005_005.png", 
// 		L"Sprite/WaterSkill/water_005_006.png", 
// 		L"Sprite/WaterSkill/water_005_007.png", 
// 		L"Sprite/WaterSkill/water_005_008.png", 
// 		L"Sprite/WaterSkill/water_005_009.png", 
// 		L"Sprite/WaterSkill/water_005_010.png", 
// 		L"Sprite/WaterSkill/water_005_011.png", 
// 		L"Sprite/WaterSkill/water_005_012.png", 
// 		L"Sprite/WaterSkill/water_005_013.png", 
// 		L"Sprite/WaterSkill/water_005_014.png", 
// 		L"Sprite/WaterSkill/water_005_015.png", 
// 		L"Sprite/WaterSkill/water_005_016.png", 
// 		L"Sprite/WaterSkill/water_005_017.png", 
// 		L"Sprite/WaterSkill/water_005_018.png", 
// 		L"Sprite/WaterSkill/water_005_019.png", 
// 		L"Sprite/WaterSkill/water_005_020.png", 
// 		L"Sprite/WaterSkill/water_005_021.png", 
// 		L"Sprite/WaterSkill/water_005_022.png", 
// 		L"Sprite/WaterSkill/water_005_023.png", 
// 		L"Sprite/WaterSkill/water_005_024.png", 
// 		L"Sprite/WaterSkill/water_005_025.png", 
// 		L"Sprite/WaterSkill/water_005_026.png", 
// 		L"Sprite/WaterSkill/water_005_027.png", 
// 		L"Sprite/WaterSkill/water_005_028.png", 
// 		L"Sprite/WaterSkill/water_005_029.png", 
// 		L"Sprite/WaterSkill/water_005_030.png" );
	
	mTime = 0.f;
	mMoveTerm = 0.03f;
	mMoveSpeedX = 5000.0f;
	mMoveSpeedY = 5000.0f;
	mLifeTime = mAnimation->GetPlayTime();

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

	mTime += dTime;
	if (mTime >= mMoveTerm)
	{
		mTime -= mMoveTerm;
		this->SetPosition(this->GetPositionX() + mMoveSpeedX * std::cosf(mDirection) * dTime, this->GetPositionY() + mMoveSpeedY * std::sinf(mDirection) * dTime);
	}
	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}