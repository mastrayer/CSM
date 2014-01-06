#include "stdafx.h"
#include "FlagCaptureGame.h"
#include "ItemManager.h"


FlagCaptureGame::FlagCaptureGame(int gameId):Game(gameId)
{
	//Todo
	mDamageBuffPosition = Point( );
	mHPBuffPosition = Point( );
	mFlagPosition[0] = Point();
	mFlagPosition[1] = Point();
	mFirstFlagAppearTime = 1024;
	mIsFlagAppear = false;
}


FlagCaptureGame::~FlagCaptureGame(void)
{
}

void FlagCaptureGame::Update(float dTime)
{ 
	Game::Update(dTime);
	mFirstFlagAppearTime -= dTime;
}

void FlagCaptureGame::RegenItem()
{
	Game::RegenItem();
	if(mIsFlagAppear == false && mFirstFlagAppearTime < 0)
	{
		GItemManager->GenerateFlag(mGameId,mFlagPosition[0]);
		GItemManager->GenerateFlag(mGameId,mFlagPosition[1]);
	}
}