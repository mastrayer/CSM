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
class CPlayer :
	public NNObject
{
private:
	NNSprite* m_PlayerSprite;
	PlayerState m_PlayerState;
	std::map<PlayerState,AnimationImageInfo> m_AnimationImageInfo; 
	float m_AnimationFrameTime; // init when Animation Type Change.
	int m_NowFrame;
	GameKeyStates m_GameKeyStates;

public:
	CPlayer(void);
	virtual ~CPlayer(void);
	NNCREATE_FUNC(CPlayer);
	void TransState(PlayerState state);
	NNSprite* GetPlayerSprite() { return m_PlayerSprite; }
	void SetPlayerGameKeyStates(GameKeyStates _gameKeySates) { m_GameKeyStates = _gameKeySates; };
	void UpdatePlayerPosition(NNPoint position) { SetPosition(position); };
	NNPoint GetPlayerPosition() { return GetPosition(); };
private:
	void Render();
	void Update( float dTime );
};

