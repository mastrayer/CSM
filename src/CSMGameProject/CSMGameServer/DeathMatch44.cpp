#include "stdafx.h"
#include "DeathMatch44.h"


DeathMatch44::DeathMatch44(int gameId):Game(gameId)
{
	//Todo
	mDamageBuffPosition = Point(20.5*64,11.5*64);
	mDamageBuffLeftTime = 150.f;
	mDamageBuffCycleTime = 60.f;
	mHPBuffPosition = Point(20.5*64,11.5*64);
	mHPBuffCycleTime = 60.f;
	mHPBuffLeftTime = 120.f;
}


DeathMatch44::~DeathMatch44(void)
{
}
