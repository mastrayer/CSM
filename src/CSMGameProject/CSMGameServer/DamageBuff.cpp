#include "stdafx.h"
#include "DamageBuff.h"
#include "PlayerManager.h"

DamageBuff::DamageBuff(int id, Point position)
{
	mItemType = DAMAGEBUFF;
	mRadius = 32;
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