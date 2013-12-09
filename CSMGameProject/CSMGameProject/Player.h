
#pragma once

#include "NNObject.h"
#include "NNSprite.h"
#include "NNLabel.h"
#include "PacketType.h"
#include "NNParticleSystem.h"

#include "PlayerUI.h"

#define SKILL_COUNT 2

enum PlayerState
{
	IDLE = 0,
	WALK = 1,
	ATTAACK = 2,
	DIE = 3,
	TYPE_ACTIVE_SKILL = 4,
	USER_ACTIVE_SKILL = 5,	
};
enum PlayerType
{
	TYPE_A = 0,
	TYPE_B = 1,
	TYPE_C = 2,
};
class CPlayer : public NNObject
{
public:
	CPlayer(void);
	virtual ~CPlayer(void);

	void TransState( PlayerState state );
	
	void SetPlayerPosition( NNPoint position ) { SetPosition(position); }
	void SetPlayerRotation( float angle ) { m_Angle = angle; m_PlayerSprite->SetRotation(angle); }
	void SetPlayerMoveDirection( NNPoint direction) { m_MoveDirection = direction; }
	void SetPlayerHP(int hp) { m_Hp = hp; }
	void SetSkillCount(float value, PlayerState skillType) { m_SkillCount[skillType - TYPE_ACTIVE_SKILL] = value; }
	void SetSkillCooldown(bool value, PlayerState skillType) { m_SkillCooldown[skillType - TYPE_ACTIVE_SKILL] = value; }

	NNPoint GetPlayerPosition() { return GetPosition(); }
	float GetPlayerRotation( ) { return m_Angle; }
	int GetPlayerHP() { return m_Hp; }
	NNSprite* GetPlayerSprite() { return m_PlayerSprite; }
	float GetSkillCount(PlayerState skillType) { return m_SkillCount[skillType - TYPE_ACTIVE_SKILL]; }
	bool GetSkillCooldown(PlayerState skillType) { return m_SkillCooldown[skillType - TYPE_ACTIVE_SKILL]; }

	void CreateSkillEffect(PlayerType type, PlayerState skillType);

	NNCREATE_FUNC(CPlayer);

private:
	void Render();
	void Update( float dTime );

private:
	std::list<NNParticleSystem*> m_ParticleSystemList;
	NNSprite* m_PlayerSprite;
	PlayerUI* m_PlayerUI;
	PlayerState m_PlayerState;
	
	NNParticleSystem *m_UserEffect;
	// NNParticleSystem *m_BuffEffect;
	NNPoint m_MoveDirection;
	NNLabel *m_RebirthTimer;
	
	float m_RebirthDelayTime;
	float m_Angle;
	int m_Hp;

	float m_SkillCount[SKILL_COUNT];
	bool m_SkillCooldown[SKILL_COUNT];

	PlayerType m_PlayerType;

	friend class PlayerManager;
	friend class GameUISet;
};