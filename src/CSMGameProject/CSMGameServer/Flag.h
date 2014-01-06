#pragma once
#include "Item.h"
class Flag : public Item
{
public:
	Flag(int itemId,int gameId, Point position);
	~Flag(void);
	//void RemoveEffect();
	//void ConsumeBy(int playerId);
	void SetConsumeStatus(bool isConsumed){ mIsConsumed = isConsumed; }
};

