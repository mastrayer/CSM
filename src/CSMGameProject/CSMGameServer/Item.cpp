#include "stdafx.h"
#include "Item.h"
#include "ClientManager.h"
#include "PlayerManager.h"

Item::Item()
{

}
Item::Item(int itemType, float lifeTime, int itemId,int gameId, Point position)
{
	mLifeTime = lifeTime;
	mItemType = itemType;
	mItemId = itemId;
	mGameId = gameId;
	mPosition = position;
	ItemComeResult outPacket = ItemComeResult();
	outPacket.mItemType = GetItemType();
	outPacket.mPosition = GetPosition();
	outPacket.mItemId = mItemId;
	outPacket.mLifeTime = mLifeTime;
	GClientManager->BroadcastPacket(nullptr,&outPacket, gameId);
}
Item::Item(int itemType, int itemId,int gameId, Point position):mOwnerId(-1)
{
	mItemType = itemType;
	mItemId = itemId;
	mGameId = gameId;
	mPosition = position;
	ItemComeResult outPacket = ItemComeResult();
	outPacket.mItemType = GetItemType();
	outPacket.mPosition = GetPosition();
	outPacket.mItemId = mItemId;
	outPacket.mLifeTime = mLifeTime;
	GClientManager->BroadcastPacket(nullptr,&outPacket, gameId);
}


Item::~Item(void)
{
}
void Item::ConsumeBy(int playerId)
{ 
	mIsConsumed = true; 
	mOwnerId = playerId; 
	GPlayerManager->GetPlayer(playerId)->ConsumeItem(this);
}

void Item::RemoveEffect()
{
	if(mOwnerId != -1 && GPlayerManager->GetPlayer(mOwnerId) != nullptr)
		GPlayerManager->GetPlayer(mOwnerId)->DropItem(this);
}