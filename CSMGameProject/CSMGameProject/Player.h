
#pragma once

#include "NNObject.h"
#include "NNSprite.h"
#include "NNLabel.h"
#include "NNAudioSystem.h"
#include "PacketType.h"
#include "NNNetworkSystem.h"

#define PLAYER_STATE_IDLE 0
#define PLAYER_STATE_WALK 1
#define PLAYER_STATE_ATTACK 2
#define PLAYER_STATE_DIE 3

class CPlayer : public NNObject
{
public:
	CPlayer(void);
	virtual ~CPlayer(void);

	void TransState( short state );
	NNSprite* GetPlayerSprite() { return m_PlayerSprite; }
	void SetPlayerGameKeyStates( GameKeyStates gameKeySates) { m_GameKeyStates = gameKeySates; }
	void UpdatePlayerPosition( NNPoint position ) { SetPosition(position); }
	void UpdatePlayerRotation( float angle ) { m_PlayerSprite->SetRotation(angle); }
	NNPoint GetPlayerPosition() { return GetPosition(); }
	NNCREATE_FUNC(CPlayer);

private:
	void Render();
	void Update( float dTime );

private:
	NNSprite* m_PlayerSprite;
	NNSprite* m_HpBar;
	NNSprite* m_HpBarFrame;

	short m_PlayerState;
	GameKeyStates m_GameKeyStates;
};

