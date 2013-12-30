
#include "TypeC.h"

CTypeSkillEffect::CTypeSkillEffect(NNPoint startPosition, float angle)
{

	mDirection = angle;
	SetPosition(startPosition);
	SetCenter(65.f, 80.f);

	mAnimation = NNAnimation::Create();

	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 30; i++)
	{
		wsprintf(temp, L"Resource/Sprite/SkillEffect/C/TypeSkill/%d.png", i);

		mAnimation->AddFrameNode(temp);
	}
	mAnimation->SetFrameTimeInSection(0.03f, 0, 29);

	mMoveSpeed = 0.0f;
	mLifeTime = mAnimation->GetPlayTime();

	AddChild(mAnimation);
}
CTypeSkillEffect::~CTypeSkillEffect()
{
}
void CTypeSkillEffect::Render()
{
	IEffect::Render();
}
void CTypeSkillEffect::Update(float dTime)
{
	IEffect::Update(dTime);

	mMoveSpeed += 800.f * dTime;
	this->SetPosition(this->GetPositionX() + mMoveSpeed * std::cosf(mDirection) * dTime, this->GetPositionY() + mMoveSpeed * std::sinf(mDirection) * dTime);

	if (mLifeTime < mNowLifeTime)
		mIsEnd = true;
}