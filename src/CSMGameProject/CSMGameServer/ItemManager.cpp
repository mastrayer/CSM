#include "stdafx.h"
#include "ItemManager.h"
#include "PlayerManager.h"


ItemManager::ItemManager(void)
{
}


ItemManager::~ItemManager(void)
{
}

void ItemManager::Update(float dTime)
{
	for( auto itemIt = mItems.begin(); itemIt != mItems.end(); itemIt++)
	{
		(*itemIt)->Update(dTime);
		if( (*itemIt)->IsLive() == false)
		{
			RemoveItem((*itemIt));
		}
		if( (*itemIt)->IsConsumed() == false )
		{
			for( auto playerIt = GPlayerManager->GetPlayers().begin(); playerIt != GPlayerManager->GetPlayers().end(); playerIt++ )
			{
				if( Point().Distance( (*itemIt)->GetPosition() , playerIt->second->GetPosition() ) <= (*itemIt)->GetRadius() + playerIt->second->GetRadius() )
				{
					(*itemIt)->ConsumeBy(playerIt->second->GetPlayerInfo().mPlayerId);

				}
			}
		}
	}
}

void ItemManager::RemoveItem(Item* item)
{
	item->RemoveEffect();
	mItems.remove(item);
	delete item;
}

int ItemManager::GenerateItemId()
{
	while(1)
	{
		int randId = rand();
		for( auto It = mItemIds.begin(); It != mItemIds.end(); It++ )
		{
			if(randId == (*It)) continue;
		}
		mItemIds.push_back(randId);
		return randId;
	}
}
void ItemManager::GenerateItem(Item* item)
{
	mItems.push_back(item);
}
ItemManager* GItemManager = nullptr;