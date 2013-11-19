
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

struct AnimationImageInfo
{
	int totalFrameCount;
	std::wstring imagePrefix;
	float frameDelay[1024];
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
	std::map<PlayerState,AnimationImageInfo> m_AnimationImageInfo; 
	float m_AnimationFrameTime; // init when Animation Type Change.
	int m_NowFrame;
	GameKeyStates m_GameKeyStates;
};

