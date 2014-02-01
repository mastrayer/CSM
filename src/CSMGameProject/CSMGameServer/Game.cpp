#include "stdafx.h"
#include "Game.h"


Game::Game(int gameId):mPlayTime(0), mGameId(gameId)
{
}


Game::~Game(void)
{
}

void Game::RegenItem()
{
	/*if(mDamageBuffLeftTime < 0)
	{
		GItemManager->GenerateDamageBuff(mGameId,mDamageBuffPosition);
		mDamageBuffLeftTime += mDamageBuffCycleTime;
	}
	
	if(mHPBuffLeftTime < 0)
	{
		GItemManager->GenerateHPBuff(mGameId,mDamageBuffPosition);
		mHPBuffLeftTime += mDamageBuffCycleTime;
	}*/
}