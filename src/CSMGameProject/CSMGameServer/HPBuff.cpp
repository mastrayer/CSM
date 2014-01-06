#include "stdafx.h"
#include "HPBuff.h"
#include "PlayerManager.h"


HPBuff::HPBuff(int id, Point position)
{
	mItemType = HPBUFF;
	mRadius = 32;
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