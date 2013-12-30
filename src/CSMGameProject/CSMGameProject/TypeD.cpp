#include "TypeD.h"
#include "PlayerManager.h"
//////////////////////////////////////////////////////////////////////////

DTypeSkillEffect::DTypeSkillEffect(float angle, NNPoint startPosition, int playerId):mPlayerId(playerId)
{
	mDashEffect = NNAnimation::Create();
	mExplosionEffect = NNAnimation::Create();
	mPlayer = CPlayerManager::GetInstance()->GetPlayerList().find(mPlayerId)->second;
		
	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 16; i++)
	{
		wsprintf(temp, L"Resource/Sprite/SkillEffect/D/TypeSkill/Dash/%d.png", i);
		mDashEffect->AddFrameNode(temp);
	}
	for (int i = 0; i < 16; i++)
	{
		wsprintf(temp, L"Resource/Sprite/SkillEffect/D/TypeSkill/Explosion/%d.png", i);
		mExplosionEffect->AddFrameNode(temp);
	}

	mDashEffect->SetFrameTimeInSection(0.02f, 0, 15);
	mExplosionEffect->SetFrameTimeInSection(0.02f, 0, 15);
	
	mDustTimeCount = 0.f;
	mDustCreateTerm = mDashEffect->GetPlayTime()/10.f;
	mDustPoint = NNPoint::NNPoint(0.f, 0.f);
	mIsCrash = false;
	mAngle = angle;
	mDistance = 250.f;
	mSpeed = mDistance * 2.8f;
	mLifeTime = mExplosionEffect->GetPlayTime() + 0.3f;

	SetPosition(startPosition);

	SetCenter(30.f, 30.f);
	
	AddChild(mDashEffect);
	AddChild(mExplosionEffect);

	mExplosionEffect->SetVisible(false);
	mDashEffect->SetLoop(false);
}
DTypeSkillEffect::~DTypeSkillEffect()
{
}
void DTypeSkillEffect::Render()
{
	IEffect::Render();
}
void DTypeSkillEffect::Update(float dTime)
{
	IEffect::Update(dTime);

	mDustTimeCount += dTime;

	if (mIsCrash == false)
	{
		mDustPoint.SetX(mDustPoint.GetX() + mSpeed * std::cosf(mAngle) * dTime);
		mDustPoint.SetY(mDustPoint.GetY() + mSpeed * std::sinf(mAngle) * dTime);
		mPlayer->SetPosition(mPlayer->GetPosition() + NNPoint(std::cosf(mAngle),std::sinf(mAngle)) * mSpeed * dTime);
		if (mDustTimeCount >= mDustCreateTerm)
		{
			mDustTimeCount -= mDustCreateTerm;
			CreateDustEffect();
		}

		if (mNowLifeTime > 0.3f)
			Crash();
	}

	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;	
}
void DTypeSkillEffect::CreateDustEffect()
{
	NNAnimation *Dust = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 16; i++)
	{
		wsprintf(temp, L"Resource/Sprite/SkillEffect/D/TypeSkill/Dash/%d.png", i);
		Dust->AddFrameNode(temp);
	}
	Dust->SetFrameTimeInSection(0.02f, 0, 15);
	Dust->SetLoop(false);
	Dust->SetPosition(mDustPoint+NNPoint(30.f,30.f));
	Dust->SetRotation(mAngle);
	Dust->SetCenter(30.f, 30.f);

	AddChild(Dust);
}

void DTypeSkillEffect::Crash()
{
	mIsCrash = true;
	mExplosionEffect->SetVisible(true);
	mExplosionEffect->SetPosition(mDustPoint);

	mNowLifeTime = 0.f;
	mLifeTime = mExplosionEffect->GetPlayTime();
}


DTypeAttackEffect::DTypeAttackEffect(int PlayerID)
{
	mSlash = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 5; i++)
	{
		wsprintf(temp, L"Resource/Sprite/SkillEffect/D/Attack/%d.png", i);
		mSlash->AddFrameNode(temp);
	}
	mSlash->SetFrameTimeInSection(0.05f, 0, 4);

	//mAngle = angle;
	mFollower = CPlayerManager::GetInstance()->FindPlayerByID(PlayerID);
	mLifeTime = mSlash->GetPlayTime();
	
	SetCenter(40.f, 30.f);
	SetRotation(mFollower->GetPlayerRotation());
	SetPosition(mFollower->GetPlayerPosition());

	AddChild(mSlash);
}
DTypeAttackEffect::~DTypeAttackEffect()
{
}
void DTypeAttackEffect::Render()
{
	IEffect::Render();
}
void DTypeAttackEffect::Update(float dTime)
{
	IEffect::Update(dTime);
	SetPosition(mFollower->GetPlayerPosition());
	SetRotation(mFollower->GetPlayerRotation());
	
	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
		
}