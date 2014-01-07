
#pragma once

#include "Effect.h"
#include "NNAnimation.h"
#include "Player.h"
#include "PlayerManager.h"
#include "config.h"

class CEmoticonEffect : public IEffect
{
public:
	CEmoticonEffect(int PlayerID, EmoticonType type);
	virtual ~CEmoticonEffect();

	void Render();
	void Update(float dTime);

private:
	NNSprite *mIcon;
	CPlayer *mFollower;
};