#pragma once
#include "Item.h"
class Flag : public Item
{
public:
	Flag(int id, Point position);
	~Flag(void);
	//void RemoveEffect();
	//void ConsumeBy(int playerId);
};

