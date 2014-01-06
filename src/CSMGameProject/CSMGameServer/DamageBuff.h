#pragma once
#include "Item.h"
class DamageBuff :
	public Item
{
public:
	DamageBuff(int itemId,int gameId, Point position);
	~DamageBuff(void);
	//void RemoveEffect();
	//void ConsumeBy(int playerId);
};

