#pragma once
#include "PacketType.h"
class Game
{
public:
	Game(int gameId);
	~Game(void);
	virtual void Update(float dTime){ mPlayTime += dTime, mDamageBuffLeftTime -= dTime, mHPBuffCycleTime -= dTime; RegenItem(); }
	virtual void RegenItem();
protected:
	float mPlayTime;

	float mDamageBuffCycleTime;
	float mDamageBuffLeftTime;
	Point mDamageBuffPosition;
	
	float mHPBuffCycleTime;
	float mHPBuffLeftTime;
	Point mHPBuffPosition;
	
	int mGameId;
};

