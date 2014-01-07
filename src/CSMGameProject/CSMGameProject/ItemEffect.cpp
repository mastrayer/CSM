#include "ItemEffect.h"
#include "PlayerManager.h"
using namespace ITEM_EFFECT;

Item::Item(NNPoint startPosition, int itemId):mStartPosition(startPosition),mItemId(itemId),mOwner(nullptr)
{
	SetPosition(mStartPosition);
}


Item::~Item(void)
{

}
void Item::Update(float dTime)
{
	IEffect::Update(dTime);
	mLifeTime -= dTime;
	if(mOwner != nullptr)
	{
		SetPosition(mOwner->GetPosition() - mOwner->GetCenter());
	}
}

void Item::Follow(int playerId)
{
	mOwner = CPlayerManager::GetInstance()->FindPlayerByID(playerId);
	SetPosition(mOwner->GetPosition() - mOwner->GetCenter());
}
		
void Item::Remove()
{

}
void Item::BackToStartPosition()
{
	SetPosition(mStartPosition);
	mOwner = nullptr;
}

DamageBuff::DamageBuff(NNPoint startPosition, int itemId, float lifeTime):Item(startPosition,itemId)
{	
	mLifeTime = lifeTime;
	mBeforeConsumeAnimation = NNAnimation::Create();
	mAfterConsumeAnimation = NNAnimation::Create();

	//TODO
	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 25; i++)
	{
		wsprintf(temp, L"Resource/Sprite/Object/Red/%d.png", i);
		mBeforeConsumeAnimation->AddFrameNode(temp);
	}
	for (int i = 0; i < 15; i++)
	{
		wsprintf(temp, L"Resource/Sprite/Buff/AttackBuff/%d.png", i);
		mAfterConsumeAnimation->AddFrameNode(temp);
	}
	mBeforeConsumeAnimation->SetFrameTimeInSection(0.02f, 0, 24);
	mAfterConsumeAnimation->SetFrameTimeInSection(0.02f, 0, 14);


	mBeforeConsumeAnimation->SetLoop(true);
	mAfterConsumeAnimation->SetLoop(true);
	
	//TODO
	mBeforeConsumeAnimation->SetCenter(NNPoint(32.f,32.f));
	mBeforeConsumeAnimation->SetVisible(true);
	mAfterConsumeAnimation->SetCenter(NNPoint(13.f,-9.f));
	mAfterConsumeAnimation->SetVisible(false);


	AddChild(mBeforeConsumeAnimation);
	AddChild(mAfterConsumeAnimation);
}

void DamageBuff::Follow(int playerId)
{
	mOwner = CPlayerManager::GetInstance()->FindPlayerByID(playerId);
	SetPosition(mOwner->GetPosition() - mOwner->GetCenter());
	mBeforeConsumeAnimation->SetVisible(false);
	mAfterConsumeAnimation->SetVisible(true);
}
DamageBuff::~DamageBuff()
{

}
void DamageBuff::Render()
{
	IEffect::Render();
}
void DamageBuff::Update(float dTime)
{
	Item::Update(dTime);
	if(mLifeTime < 0 ) mIsEnd = true;
}

HPBuff::HPBuff(NNPoint startPosition, int itemId, float lifeTime):Item(startPosition,itemId)
{
	mLifeTime = lifeTime;
	mBeforeConsumeAnimation = NNAnimation::Create();
	mAfterConsumeAnimation = NNAnimation::Create();

	//TODO
	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 15; i++)
	{
		wsprintf(temp, L"Resource/Sprite/Object/blue/%d.png", i);
		mBeforeConsumeAnimation->AddFrameNode(temp);
	}
	for (int i = 0; i < 15; i++)
	{
		wsprintf(temp, L"Resource/Sprite/Buff/DefenceBuff/%d.png", i);
		mAfterConsumeAnimation->AddFrameNode(temp);
	}
	mBeforeConsumeAnimation->SetFrameTimeInSection(0.02f, 0, 14);
	mAfterConsumeAnimation->SetFrameTimeInSection(0.02f, 0, 14);


	mLifeTime = 45.f;
	mBeforeConsumeAnimation->SetVisible(true);
	mBeforeConsumeAnimation->SetLoop(true);
	mBeforeConsumeAnimation->SetCenter(NNPoint(32.f,32.f));
	mAfterConsumeAnimation->SetVisible(false);
	mAfterConsumeAnimation->SetLoop(true);
	mAfterConsumeAnimation->SetCenter(NNPoint(13.f,-9.f));
	

	
	AddChild(mBeforeConsumeAnimation);
	AddChild(mAfterConsumeAnimation);
}

void HPBuff::Follow(int playerId)
{
	mOwner = CPlayerManager::GetInstance()->FindPlayerByID(playerId);
	SetPosition(mOwner->GetPosition() - mOwner->GetCenter());
	mBeforeConsumeAnimation->SetVisible(false);
	mAfterConsumeAnimation->SetVisible(true);
}
HPBuff::~HPBuff()
{

}
void HPBuff::Render()
{
	IEffect::Render();
}
void HPBuff::Update(float dTime)
{
	Item::Update(dTime);
	if(mLifeTime < 0 ) mIsEnd = true;
}
Flag::Flag(NNPoint startPosition, int itemId):Item(startPosition,itemId)
{	mAnimation = NNAnimation::Create();

	//TODO
	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 0; i++)
	{
		//wsprintf(temp, L"Resource/Sprite/Item/Flag/%d.png", i);
		mAnimation->AddFrameNode(temp);
	}
	//mAnimation->SetFrameTimeInSection(0.00f, 0, 0);


	//¹«ÇÑ. //mLifeTime = ;
	mAnimation->SetVisible(false);
	mAnimation->SetLoop(false);
	
	//TODO
	mAnimation->SetCenter(NNPoint());


	AddChild(mAnimation);
}

Flag::~Flag()
{

}
void Flag::Render()
{
	IEffect::Render();
}
void Flag::Update(float dTime)
{
	Item::Update(dTime);
}