#include "stdafx.h"
#include "HPBuff.h"
#include "PlayerManager.h"


HPBuff::HPBuff(int itemId,int gameId, Point position):Item(HPBUFF,itemId,gameId,position)
{
	mRadius = 32;
	mIsPermanent = false;
	mLifeTime = 45.f;
	mIsConsumed = false;
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