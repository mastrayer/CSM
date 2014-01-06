#pragma once
#include "Item.h"
class HPBuff :
	public Item
{
public:
	HPBuff(int id, Point position);
	~HPBuff(void);
	//void RemoveEffect();
	//void ConsumeBy(int playerId);
};

