
#include "Player.h"

#include "NNAudioSystem.h"
#include "NNNetworkSystem.h"
#include "NNParticleSystem.h"
#include "NNInputSystem.h"
#include "NNApplication.h"

#include "EffectManager.h"
#include "TypeEffect.h"
#include "UserEffect.h"

CPlayer::CPlayer( void )
	: m_PlayerSprite(NULL),m_MoveDirection(NNPoint(0,0)),
	m_Hp(100),m_RebirthDelayTime(10)
{
	TransState(PlayerState::IDLE);

	m_PlayerUI = PlayerUI::Create();
	AddChild( m_PlayerUI );
}

CPlayer::~CPlayer( void )
{
}

void CPlayer::TransState( PlayerState state )
{
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();
	float rotation = m_Rotation;

	m_PlayerState = state;

	if ( m_PlayerSprite != NULL )
	{
		RemoveChild( m_PlayerSprite );
	}

	std::wstring imagePath = L"";

	switch (state)
	{
	case IDLE:
		{
			imagePath = L"Sprite/idle_0.png";
		}
		break;
	case WALK:
		{
			imagePath = L"Sprite/walk_0.png";
		}
		break;
	case ATTAACK:
		{
			imagePath = L"Sprite/attack_0.png";

			//RemoveChild(m_BuffEffect);

			//m_BuffEffect = NNParticleSystem::Create()
		}
		break;
	case DIE:
		{
			imagePath = L"Sprite/die.png";
			m_RebirthTimer = NNLabel::Create(L"으앙~ 쥬금~ X초 우리 좀 잘 해봅시다", L"맑은 고딕", 40.f);
			m_RebirthTimer->SetCenter( width/2, height/2 - 200 );
		}
		break;
	case USER_ACTIVE_SKILL:
		{
			imagePath = L"Sprite/skill_0.png";
			EffectManager::GetInstance()->AddEffect(new UserEffect(this));
		}
		break;
	case TYPE_ACTIVE_SKILL:
		{
			imagePath = L"Sprite/skill_1.png";
			if( m_Check == true)
				break;

			EffectManager::GetInstance()->AddEffect(new TypeEffect(this));
			m_Count = 0.f;
			m_Check = true;
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
	//printf(" ############## %d \n",m_GameKeyStates.typeActiveSkillKey);

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
			SetPosition( GetPosition() + m_MoveDirection * dTime * 100.f );
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
		// 스킬 발동 키 추가 by mooneegee
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

	/*
	for (const auto& node : m_ChildList )
	{
		NNParticleSystem* temp = dynamic_cast<NNParticleSystem*>(node);

		if ( temp != NULL ) {

		}
	}
	fof;lkJSIf;lug 0v
	;'dlfjalfjwoefuaoiwnbSv r( */
	/*
	m_ParticleSystemList.push_back(* );
	Ad-*+++++++
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	jdkdkdkdfjfdiensk,cxnxcj,zwlhfisjfsdjsdl dkldjfeineifjdkfkjdlfjflvkd6ltjsguqdls2h5g2o2d295dl95didl6di1g9h8dl18d1l8tj8sdk1wale34hg8alwerjfl;askdji;woer fjoaisjkdlfhs;adjjjjjjjjjjjjjjj m dChild(* );
	
	for (auto& iter=m_ParticleSystemList.begin(); iter!=m_ParticleSystemList.end(); iter++ )
	{
		if ((*iter)->IsAlive() == false)
		{
			RemoveChild( *iter );
			iter = m_ParticleSystemList.erase( iter );
			if ( iter == m_ParticleSystemList.end() )
			{
				break;
			}
		}
	}*/
}



void CPlayer::Render()
{
	NNObject::Render();
}