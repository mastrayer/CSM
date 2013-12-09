
#include "Player.h"

#include "NNAudioSystem.h"
#include "NNNetworkSystem.h"
#include "NNParticleSystem.h"
#include "NNInputSystem.h"
#include "NNApplication.h"
#include "NNAnimation.h"

#include "EffectManager.h"
#include "ATypeEffect.h"
#include "AUserEffect.h"
#include "BTypeEffect.h"
#include "BUserEffect.h"
#include "CTypeEffect.h"
#include "CUserEffect.h"

CPlayer::CPlayer( void )
	: m_PlayerSprite(NULL),m_MoveDirection(NNPoint(0,0)),
	m_Hp(100),m_RebirthDelayTime(10), m_Team(0)
{
	TransState(PlayerState::IDLE);

	m_PlayerUI = PlayerUI::Create();
	AddChild( m_PlayerUI );

	memset(m_SkillCount, 0, sizeof(m_SkillCount));
	memset(m_SkillCooldown, 0, sizeof(m_SkillCooldown));
}

CPlayer::~CPlayer( void )
{
}

void CPlayer::CreateSkillEffect(PlayerType type, PlayerState skillType)
{
	switch (type)
	{
	case TYPE_A :
		if (skillType == TYPE_ACTIVE_SKILL) EffectManager::GetInstance()->AddEffect(new ATypeEffect(this));
		if (skillType == USER_ACTIVE_SKILL) EffectManager::GetInstance()->AddEffect(new AUserEffect(this));
		break;

	case TYPE_B :
		if (skillType == TYPE_ACTIVE_SKILL) EffectManager::GetInstance()->AddEffect(new BTypeEffect(this));
		if (skillType == USER_ACTIVE_SKILL) EffectManager::GetInstance()->AddEffect(new BTypeEffect(this));
		break;

	case TYPE_C :
		if (skillType == TYPE_ACTIVE_SKILL) EffectManager::GetInstance()->AddEffect(new CTypeEffect(this));
		if (skillType == USER_ACTIVE_SKILL) EffectManager::GetInstance()->AddEffect(new CTypeEffect(this));
		break;
	}
}
void CPlayer::TransState( PlayerState state )
{
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();
	float rotation = m_Rotation;

	m_PlayerState = state;

	if (m_PlayerSprite != NULL)
	{
		RemoveChild(m_PlayerSprite);
	}

	std::wstring imagePath = L"";

	switch (state)
	{
	case IDLE:
		imagePath = L"Sprite/idle_0.png";
		break;

	case WALK:
		imagePath = L"Sprite/walk_0.png";
		break;

	case ATTAACK:
		imagePath = L"Sprite/attack_0.png";

		//RemoveChild(m_BuffEffect);

		//m_BuffEffect = NNParticleSystem::Create()
		break;

	case DIE:
		imagePath = L"Sprite/die.png";
		m_RebirthTimer = NNLabel::Create(L"으앙~ 쥬금~ X초 우리 좀 잘 해봅시다", L"맑은 고딕", 40.f);
		m_RebirthTimer->SetCenter(width / 2, height / 2 - 200);
		break;

	case TYPE_ACTIVE_SKILL:
		imagePath = L"Sprite/skill_1.png";
		if (GetSkillCooldown(TYPE_ACTIVE_SKILL) == false)
		{
			SetSkillCooldown(true, TYPE_ACTIVE_SKILL);
			CreateSkillEffect(m_PlayerType, TYPE_ACTIVE_SKILL);
		}
		break;

	case USER_ACTIVE_SKILL:
		imagePath = L"Sprite/skill_0.png";
		if (GetSkillCooldown(USER_ACTIVE_SKILL) == false)
		{
			SetSkillCooldown(true, USER_ACTIVE_SKILL);
			CreateSkillEffect(m_PlayerType, USER_ACTIVE_SKILL);
		}
		break;

	default:
		break;
	}

	/* Player Sprite Setting */
	m_PlayerSprite = NNSprite::Create( imagePath );
	AddChild( m_PlayerSprite );

	m_PlayerSprite->SetCenter( m_PlayerSprite->GetImageWidth()/2.f, m_PlayerSprite->GetImageHeight()/2.f );
	//Sprite를 바꾸면 Rotation이 자동으로 0되니까 예전값으로 다시 대입
	m_PlayerSprite->SetRotation(rotation);
	/* // */
}

void CPlayer::Update( float dTime )
{
	NNObject::Update( dTime );

	m_PlayerUI->SetHP( m_Hp );

	switch (m_PlayerState)
	{
	case IDLE:
		{
		}
		break;
	case WALK:
		{
			//Move myPlayer with Game Key States.
			//Check Moving Input, and set Position to d
			SetPosition( GetPosition() + m_MoveDirection * dTime * m_Speed );
			break;
		}
	case ATTAACK:
		{
		}
		break;
	case DIE:
		{
		}
		break;
	case USER_ACTIVE_SKILL:
		{

		}
		break;
	case TYPE_ACTIVE_SKILL:
		{

		}
		break;
	default:
		break;
	}
}

void CPlayer::Render()
{
	NNObject::Render();
}

void CPlayer::InitWithType()
{
	switch (m_PlayerType)
	{
	case TYPE_A:
		{
			m_Speed = 100;
		}break;
	case TYPE_B:
		{
			m_Speed = 110;
		}break;
	case TYPE_C:
		{
			m_Speed = 120;
		}break;
	default:
		break;
	}
}