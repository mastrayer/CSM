#include "stdafx.h"
#include "Flag.h"
#include "PlayerManager.h"


Flag::Flag(int id, Point position)
{
	mItemType = FLAG;
	mRadius = 32;
	라이프타임 넣으세요 플래그는 무한, 다른건 2분씩 이라던지	
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