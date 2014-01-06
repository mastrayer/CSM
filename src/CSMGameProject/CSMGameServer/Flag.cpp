#include "stdafx.h"
#include "Flag.h"
#include "PlayerManager.h"


Flag::Flag(int id, Point position)
{
	mItemType = FLAG;
	mRadius = 32;
	mIsPermanent = true;
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