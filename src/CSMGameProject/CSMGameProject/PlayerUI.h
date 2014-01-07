
#pragma once

#include "NNObject.h"
#include "NNSprite.h"
#include "NNLabel.h"

enum TeamColor
{
	RED = 0,
	BLUE = 1
};
class PlayerUI : public NNObject
{
public:
	PlayerUI(NNObject *follower);
	virtual ~PlayerUI();

	void Init();
	void Render();
	void Update( float dTime );

	void SetHP(int hp) { mHp = hp; }
	void SetTeam(int team) { mTeam = team; }

	//NNCREATE_FUNC(PlayerUI);
	static PlayerUI* Create(NNObject *follower)
	{
		PlayerUI* pInstance = new PlayerUI(follower);
		pInstance->Init();
		return pInstance;
	}

private:
	NNSprite* mHpBar[2];
	NNSprite* mHpBarFrame;
	int mHp;
	int mTeam;

	wchar_t mNicknameBuf[256];
	NNLabel *mNickname;

	NNObject *mFollower;
};