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
	if(mOwner != nullptr)
	{
		if(NNPoint().GetDistance(mOwner->GetPosition() - mOwner->GetCenter() - GetPosition()) > 50.f)
		{
			SetPosition( (mOwner->GetPosition() - mOwner->GetCenter() - GetPosition() )/ NNPoint().GetDistance(mOwner->GetPosition() - mOwner->GetCenter() - GetPosition()) * 50.f );
		}
		else
			SetPosition(mOwner->GetPosition() - mOwner->GetCenter() - (  mOwner->GetPosition() - mOwner->GetCenter() - GetPosition() ) / 2);
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

DamageBuff::DamageBuff(NNPoint startPosition, int itemId):Item(startPosition,itemId)
{	
	mAnimation = NNAnimation::Create();

	//TODO
	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 0; i++)
	{
		//wsprintf(temp, L"Resource/Sprite/Item/DamageBuff/%d.png", i);
		mAnimation->AddFrameNode(temp);
	}
	//mAnimation->SetFrameTimeInSection(0.00f, 0, 0);


	mLifeTime = 60.f;
	mAnimation->SetVisible(false);
	mAnimation->SetLoop(false);
	
	//TODO
	mAnimation->SetCenter(NNPoint());


	AddChild(mAnimation);
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
}

HPBuff::HPBuff(NNPoint startPosition, int itemId):Item(startPosition,itemId)
{
	mAnimation = NNAnimation::Create();

	//TODO
	wchar_t temp[256] = { 0 };
	for (int i = 0; i < 0; i++)
	{
		//wsprintf(temp, L"Resource/Sprite/Item/HPBuff/%d.png", i);
		mAnimation->AddFrameNode(temp);
	}
	//mAnimation->SetFrameTimeInSection(0.00f, 0, 0);


	mLifeTime = 60.f;
	mAnimation->SetVisible(false);
	mAnimation->SetLoop(false);
	
	//TODO
	mAnimation->SetCenter(NNPoint());


	AddChild(mAnimation);
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