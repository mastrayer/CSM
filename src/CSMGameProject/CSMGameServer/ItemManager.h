#pragma once
#include "Item.h"
#include "DamageBuff.h"
#include "HPBuff.h"
#include "Flag.h"

#include "Player.h"

#include "List"
#include "Map"

class ItemManager
{
private:
	std::list<Item*> mItems;
	std::list<int> mItemIds;
public:
	ItemManager(void);
	~ItemManager(void);

	void GenerateDamageBuff(Point position){ GenerateItem(new DamageBuff(GenerateItemId(), position)); }
	void GenerateHPBuff(Point position){ GenerateItem(new HPBuff(GenerateItemId(), position)); }
	void GenerateFlag(Point position){ GenerateItem(new Flag(GenerateItemId(), position)); }
	void GenerateItem(Item* item);
	void Update(float dTime); // 캐릭터, 아이템 거리 확인해서 아이템 Get하는것도 여기서. 아이템 사라지는것도 여기서

	void RemoveItem(Item* item);

private:
	int GenerateItemId();
};



extern ItemManager* GItemManager;