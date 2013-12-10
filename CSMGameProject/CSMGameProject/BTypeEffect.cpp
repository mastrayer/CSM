
#include "BTypeEffect.h"

BTypeEffect::BTypeEffect(CPlayer* follower)
{
	mFollower = follower;
	SetPosition(mFollower->GetPlayerPosition());

	mFlyAnimation = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 8; i++)
	{
		wsprintf(temp, L"Sprite/WaterMissile/Fly/%d.png", i);

		mFlyAnimation->AddFrameNode(temp);
	}
	mFlyAnimation->SetFrameTimeInSection(0.03f, 0, 7);

	mSource.SetPoint(mFollower->GetPosition());
	mLifeTime = mFlyAnimation->GetPlayTime() * 5;
	mFlyAnimation->SetCenter(30.f, 65.f);
	mDestination.SetPoint(FindTarget());
	mDirection = std::atan2f(mDestination.GetY() - mFollower->GetPositionY(), mDestination.GetX() - mFollower->GetPositionX());
	mMoveSpeed = 100.f;

	mFlyAnimation->SetRotation(mDirection);
	mIsCrash = false;

	AddChild(mFlyAnimation);
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

	//mMoveSpeed += 100.f * dTime;
	this->SetPosition(this->GetPositionX() + mMoveSpeed * std::cosf(mDirection) * dTime, this->GetPositionY() + mMoveSpeed * std::sinf(mDirection) * dTime);

	if (!mIsCrash && mLifeTime < mNowLifeTime)
		Explosion();
	if (mIsCrash && mLifeTime < mNowLifeTime)
		mIsEnd = true;
}
NNPoint BTypeEffect::FindTarget()
{
	std::map<int, CPlayer*> list;
	NNPoint target;
	float distance = 999999.f;

	target.SetPoint(mSource);
	list = CPlayerManager::GetInstance()->GetPlayerList();
	for (std::map<int, CPlayer*>::iterator iter = list.begin(); iter != list.end(); ++iter)
	{
		if (iter->first == CPlayerManager::GetInstance()->GetMyPlayerId()) 
			continue;

		NNPoint targetPosition = iter->second->GetPlayerPosition();
		float result = std::abs(std::sqrtf(std::powf(targetPosition.GetX() - mSource.GetX(), 2.f) + std::powf(targetPosition.GetY() - mSource.GetY(), 2.f) ) );

		if (result <= distance)
		{
			distance = result;
			target = targetPosition;
		}
	}

	return target;
}

void BTypeEffect::Explosion()
{
	mFlyAnimation->SetVisible(false);
	mExplosionAnimation = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 41; i++)
	{
		wsprintf(temp, L"Sprite/WaterMissile/Explosion/%d.png", i);

		mExplosionAnimation->AddFrameNode(temp);
	}
	mExplosionAnimation->SetFrameTimeInSection(0.02f, 0, 40);
	mExplosionAnimation->SetCenter(30.f, 65.f);
	mExplosionAnimation->SetRotation(mDirection);

	AddChild(mExplosionAnimation);

	mNowLifeTime = 0.f;
	mLifeTime = mExplosionAnimation->GetPlayTime();
	mIsCrash = true;
}
