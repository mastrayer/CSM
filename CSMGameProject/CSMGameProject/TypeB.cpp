
#include "TypeB.h"

BTypeEffect::BTypeEffect(NNPoint startPosition, NNPoint targetPosition)
{
	//mFollower = follower;
	//SetPosition(mFollower->GetPlayerPosition());
	SetPosition(startPosition);

	mFlyAnimation = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 8; i++)
	{
		wsprintf(temp, L"Sprite/SkillEffect/B/TypeSkill/Fly/%d.png", i);

		mFlyAnimation->AddFrameNode(temp);
	}
	mFlyAnimation->SetFrameTimeInSection(0.03f, 0, 7);

	//mSource.SetPoint(mFollower->GetPosition());
	mSource.SetPoint(startPosition);
	mLifeTime = mFlyAnimation->GetPlayTime() * 5;
	mFlyAnimation->SetCenter(30.f, 65.f);
	mDestination.SetPoint(FindTarget(mSource));
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
NNPoint BTypeEffect::FindTarget(NNPoint startPosition)
{
	std::map<int, CPlayer*> list;
	NNPoint target = startPosition;
	float distance = 999999.f;

	list = CPlayerManager::GetInstance()->GetPlayerList();
	for (std::map<int, CPlayer*>::iterator iter = list.begin(); iter != list.end(); ++iter)
	{
		if (iter->first == CPlayerManager::GetInstance()->GetMyPlayerId())
			continue;

		NNPoint targetPosition = iter->second->GetPlayerPosition();
		float result = std::abs(std::sqrtf(std::powf(targetPosition.GetX() - startPosition.GetX(), 2.f) + std::powf(targetPosition.GetY() - startPosition.GetY(), 2.f)));

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
		wsprintf(temp, L"Sprite/SkillEffect/B/TypeSkill/Explosion/%d.png", i);

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

