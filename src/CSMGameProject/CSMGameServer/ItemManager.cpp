#include "stdafx.h"
#include "ItemManager.h"
#include "PlayerManager.h"
#include "GameManager.h"

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
			if( itemIt != mItems.end() ) itemIt++;
			break;
		}
		if( (*itemIt)->IsConsumed() == false )
		{
			std::map<int,Player*> players;
			GPlayerManager->GetPlayers((*itemIt)->GetGameId(),&players);
			for( auto playerIt = players.begin(); playerIt != players.end(); playerIt++ )
			{
				if( Point().Distance( (*itemIt)->GetPosition() , playerIt->second->GetPosition() ) <= (*itemIt)->GetRadius() + playerIt->second->GetRadius() )
				{
					(*itemIt)->ConsumeBy(playerIt->second->GetPlayerInfo().mPlayerId);

				}
			}
		}
		if((*itemIt)->GetItemType() == FLAG && (*itemIt)->IsConsumed() == true && Point().Distance( GPlayerManager->GetPlayer((*itemIt)->GetOwnerId())->GetPosition(), Point() ) < 48 )
		{
			GGameManager->AddScore((*itemIt)->GetGameId(),GPlayerManager->GetPlayer((*itemIt)->GetOwnerId())->GetTeam(),100);
			GPlayerManager->GetPlayer((*itemIt)->GetOwnerId())->DropItem((*itemIt));
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