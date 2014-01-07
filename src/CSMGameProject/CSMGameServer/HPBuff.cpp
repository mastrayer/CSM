#include "stdafx.h"
#include "HPBuff.h"
#include "PlayerManager.h"


HPBuff::HPBuff(int itemId,int gameId, Point position)
{
	mItemType = HPBUFF;
	mRadius = 32;
	mIsPermanent = false;
	mLifeTime = 45.f;
}


HPBuff::~HPBuff(void)
{
}

/*
void HPBuff::RemoveEffect()
{
	GPlayerManager->GetPlayer(mOwnerId)->DropItem(this);
}
void HPBuff::ConsumeBy(int playerId)
{
	GPlayerManager->GetPlayer(playerId)->ConsumeItem(this);
	mOwnerId = playerId;
}*/