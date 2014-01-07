#include "stdafx.h"
#include "DamageBuff.h"
#include "PlayerManager.h"

DamageBuff::DamageBuff(int itemId,int gameId, Point position):Item(DAMAGEBUFF,45.f,itemId,gameId,position)
{
	mRadius = 32;
	mIsPermanent = false;
	mIsConsumed = false;
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