#include "stdafx.h"
#include "FlagCaptureGame.h"
#include "ItemManager.h"


FlagCaptureGame::FlagCaptureGame(int gameId):Game(gameId)
{
	mDamageBuffPosition = Point( 30.5 * 64, 33.5 * 64 );
	mDamageBuffLeftTime = 150.f;
	mDamageBuffCycleTime = 60.f;
	mHPBuffPosition = Point( 33.5 * 64, 30.5 * 64 );
	mHPBuffCycleTime = 60.f;
	mHPBuffLeftTime = 120.f;

	mFlagPosition[0] = Point(12.5 * 64, 30.5 * 64);
	mFlagPosition[1] = Point(30.5 * 64 , 11.5 * 64);
	mFirstFlagAppearTime = 60.f;
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