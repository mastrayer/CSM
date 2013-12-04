
#pragma once

#include "NNObject.h"
#include "NNSprite.h"
#include "NNLabel.h"
#include "PacketType.h"
#include "NNParticleSystem.h"

#include "PlayerUI.h"

enum PlayerState
{
	IDLE = 0,
	WALK = 1,
	ATTAACK = 2,
	DIE = 3,
	TYPE_ACTIVE_SKILL = 4,
	USER_ACTIVE_SKILL = 5,	
};

class CPlayer : public NNObject
{
public:
	CPlayer(void);
	virtual ~CPlayer(void);

	void TransState( PlayerState state );
	NNSprite* GetPlayerSprite() { return m_PlayerSprite; }
	void SetPlayerPosition( NNPoint position ) { SetPosition(position); }
	void SetPlayerRotation( float angle ) { m_Angle = angle; m_PlayerSprite->SetRotation(angle); }
	void SetPlayerMoveDirection( NNPoint direction) { m_MoveDirection = direction; }
	NNPoint GetPlayerPosition() { return GetPosition(); }
	void SetPlayerHP(int hp) { m_Hp = hp; }
	int GetPlayerHP() { return m_Hp; }
	NNCREATE_FUNC(CPlayer);

private:
	void Render();
	void Update( float dTime );

private:
	std::list<NNParticleSystem*> m_ParticleSystemList;
	NNSprite* m_PlayerSprite;
	PlayerUI* m_PlayerUI;
	PlayerState m_PlayerState;
	NNParticleSystem *m_TypeEffect;
	NNParticleSystem *m_UserEffect;
	// NNParticleSystem *m_BuffEffect;
	NNPoint m_MoveDirection;
	NNLabel *m_RebirthTimer;
	
	float m_RebirthDelayTime;
	float m_Angle;
	int m_Hp;

	float m_Count;
	bool m_Check;

	friend class PlayerManager;
	friend class GameUISet;
};