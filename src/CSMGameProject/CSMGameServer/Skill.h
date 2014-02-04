#pragma once
#include "Player.h"
class Skill
{
public:
	Skill(Player* ownerPlayer) {mOwnerPlayer = ownerPlayer;}
	virtual ~Skill(void) = 0 {};

	Player* mOwnerPlayer;
	
	virtual bool IsLive() = 0;
	virtual void Update(float dTime) = 0;
};

