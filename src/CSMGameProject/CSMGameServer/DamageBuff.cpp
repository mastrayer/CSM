#include "stdafx.h"
#include "DamageBuff.h"
#include "PlayerManager.h"

DamageBuff::DamageBuff(int itemId,int gameId, Point position):Item(DAMAGEBUFF,itemId,gameId,position)
{
	mRadius = 32;
	mIsPermanent = false;
	mLifeTime = 45.f;
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