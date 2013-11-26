
#pragma once

#include "NNObject.h"
#include "NNSprite.h"
#include "NNLabel.h"
#include "PacketType.h"

#include "PlayerUI.h"

enum PlayerState
{
	IDLE = 0,
	WALK = 1,
	ATTAACK = 2,
	DIE = 3,
};

class CPlayer : public NNObject
{
public:
	CPlayer(void);
	virtual ~CPlayer(void);

	void TransState( PlayerState state );
	NNSprite* GetPlayerSprite() { return m_PlayerSprite; }
	void SetPlayerGameKeyStates( GameKeyStates gameKeySates) { m_GameKeyStates = gameKeySates; }
	void SetPlayerPosition( NNPoint position ) { SetPosition(position); }
	void SetPlayerRotation( float angle ) { m_PlayerSprite->SetRotation(angle); }
	NNPoint GetPlayerPosition() { return GetPosition(); }
	void SetPlayerHP(int hp);
	NNCREATE_FUNC(CPlayer);

private:
	void Render();
	void Update( float dTime );

private:
	NNSprite* m_PlayerSprite;

	PlayerUI* m_PlayerUI;
	PlayerState m_PlayerState;
	GameKeyStates m_GameKeyStates;

	friend class PlayerManager;
};

