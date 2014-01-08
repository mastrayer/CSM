#include "stdafx.h"
#include "DeathMatch88.h"


DeathMatch88::DeathMatch88(int gameId):Game(gameId)
{
	mDamageBuffPosition = Point( 30.5 * 64, 33.5 * 64 );
	mDamageBuffLeftTime = 150.f;
	mDamageBuffCycleTime = 60.f;
	mHPBuffPosition = Point( 33.5 * 64, 30.5 * 64 );
	mHPBuffCycleTime = 60.f;
	mHPBuffLeftTime = 120.f;
}


DeathMatch88::~DeathMatch88(void)
{
}
