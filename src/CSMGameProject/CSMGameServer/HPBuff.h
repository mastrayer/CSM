#pragma once
#include "Item.h"
class HPBuff :
	public Item
{
public:
	HPBuff(int itemId,int gameId, Point position);
	~HPBuff(void);
	//void RemoveEffect();
	//void ConsumeBy(int playerId);
};

