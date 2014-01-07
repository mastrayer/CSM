#include "stdafx.h"
#include "DamageBuff.h"
#include "PlayerManager.h"

DamageBuff::DamageBuff(int itemId,int gameId, Point position)
{
	mItemType = DAMAGEBUFF;
	mRadius = 32;
	mIsPermanent = false;
	mLifeTime = 45.f;
}


DamageBuff::~DamageBuff(void)
{
}

/*
void DamageBuff::RemoveEffect()
{
	GPlayerManager->GetPlayer(mOwnerId)->DropItem(this);
}

void DamageBuff::ConsumeBy(int playerId)
{
	GPlayerManager->GetPlayer(playerId)->ConsumeItem(this);
	mOwnerId = playerId;
}*/