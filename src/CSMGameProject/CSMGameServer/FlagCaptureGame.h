#pragma once
#include "Game.h"
class FlagCaptureGame : public Game
{
public:
	FlagCaptureGame(int gameId);
	~FlagCaptureGame(void);
	virtual void Update(float dTime);
	virtual void RegenItem();
private:
	Point mFlagPosition[2];
	float mFirstFlagAppearTime;
	bool mIsFlagAppear;
};

