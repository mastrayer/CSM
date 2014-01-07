#include "stdafx.h"
#include "Flag.h"
#include "PlayerManager.h"


Flag::Flag(int itemId,int gameId, Point position):Item(FLAG,itemId,gameId,position)
{
	mRadius = 32;
	mIsPermanent = true;
	mIsConsumed = false;
}


Flag::~Flag(void)
{
}
/*
void Flag::RemoveEffect()
{
	GPlayerManager->GetPlayer(mOwnerId)->DropItem(this);
}

void Flag::ConsumeBy(int playerId)
{
	GPlayerManager->GetPlayer(playerId)->ConsumeItem(this);
	mOwnerId = playerId;
}*/