
#pragma once

#include "NNObject.h"
#include "NNSprite.h"
#include "NNLabel.h"
#include "NNAudioSystem.h"
#include "PacketType.h"
#include "NNNetworkSystem.h"

enum PlayerState
{
	IDLE,
	WALK,
	ATTACK,
	DIE,
};

class CPlayer : public NNObject
{
public:
	CPlayer(void);
	virtual ~CPlayer(void);

	void TransState( PlayerState state );
	NNSprite* GetPlayerSprite() { return m_PlayerSprite; }
	void SetPlayerGameKeyStates( GameKeyStates gameKeySates) { m_GameKeyStates = gameKeySates; }
	void UpdatePlayerPosition( NNPoint position ) { SetPosition(position); }
	NNPoint GetPlayerPosition() { return GetPosition(); }

	NNCREATE_FUNC(CPlayer);

private:
	void Render();
	void Update( float dTime );

private:
	NNSprite* m_PlayerSprite;
	NNSprite* m_HpBar;
	NNSprite* m_HpBarFrame;

	PlayerState m_PlayerState;
	GameKeyStates m_GameKeyStates;
};

