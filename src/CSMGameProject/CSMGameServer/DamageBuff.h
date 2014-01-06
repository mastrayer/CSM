#pragma once
#include "Item.h"
class DamageBuff :
	public Item
{
public:
	DamageBuff(int id, Point position);
	~DamageBuff(void);
	//void RemoveEffect();
	//void ConsumeBy(int playerId);
};

