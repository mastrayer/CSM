
#include "Player.h"

#include "NNAudioSystem.h"
#include "NNNetworkSystem.h"
#include "NNParticleSystem.h"
#include "NNInputSystem.h"

CPlayer::CPlayer( void )
	: m_PlayerSprite(NULL)
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
		}
		break;
	case DIE:
		{
			imagePath = L"Sprite/die_0.png";
		}
		break;
	case USER_ACTIVE_SKILL:
		{
			imagePath = L"Sprite/skill_0.png";

			RemoveChild(m_UserEffect);
			m_UserEffect = NNParticleSystem::Create(L"Sprite/fire.jpg");
			m_UserEffect->SetMinStartSpeed(300.f);
			m_UserEffect->SetMaxStartSpeed(400.f);
			m_UserEffect->SetMinEndSpeed(400.f);
			m_UserEffect->SetMaxEndSpeed(500.f);

			m_UserEffect->SetCreateParticlePerSecond(60);
			m_UserEffect->SetSpreadDegree(15.f);
			m_UserEffect->SetMinLifeTime(0.5f);
			m_UserEffect->SetMaxLifeTime(0.5f);
			m_UserEffect->SetDirection(m_Angle);
			
			m_UserEffect->SetMinStartRodiusX( 50.f );
			m_UserEffect->SetMinStartRodiusY( 50.f );
			m_UserEffect->SetMaxStartRodiusX( 100.f );
			m_UserEffect->SetMaxStartRodiusY( 100.f );

			//m_UserEffect->SetSystemLifeTime(0.5f);

			AddChild(m_UserEffect);
		}
		break;
	case TYPE_ACTIVE_SKILL:
		{
			imagePath = L"Sprite/skill_1.png";

			RemoveChild(m_TypeEffect);
			
			m_TypeEffect = NNParticleSystem::Create(L"Sprite/FlashEffect.png");
		
		//	m_TypeEffect->SetCenter( m_PlayerSprite->GetCenterX(), m_PlayerSprite->GetCenterY() );

			m_TypeEffect->SetMinStartSpeed(100.f);
			m_TypeEffect->SetMaxStartSpeed(110.f);
			m_TypeEffect->SetMinEndSpeed(120.f);
			m_TypeEffect->SetMaxEndSpeed(130.f);

			m_TypeEffect->SetCreateParticlePerSecond(60);
			m_TypeEffect->SetSpreadDegree(360.f);
			m_TypeEffect->SetMinLifeTime(0.5f);
			m_TypeEffect->SetMaxLifeTime(0.5f);

			m_TypeEffect->SetMinStartRodiusX( 50.f );
			m_TypeEffect->SetMinStartRodiusY( 50.f );
			m_TypeEffect->SetMaxStartRodiusX( 60.f );
			m_TypeEffect->SetMaxStartRodiusY( 60.f );

			AddChild(m_TypeEffect);			
			
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
			if ( m_GameKeyStates.leftDirectKey ==  KEYSTATE_PRESSED )
			{   //Left
				SetPosition( GetPosition() + NNPoint( -1.f, 0.f) * dTime * 100.f );
			}
			if ( m_GameKeyStates.rightDirectKey == KEYSTATE_PRESSED )
			{   //Right
				SetPosition( GetPosition() + NNPoint( 1.f, 0.f) * dTime * 100.f );
			}
			if ( m_GameKeyStates.upDirectKey == KEYSTATE_PRESSED )
			{   //UP
				SetPosition( GetPosition() + NNPoint( 0.f, -1.f) * dTime * 100.f );
			}
			if ( m_GameKeyStates.downDirectKey == KEYSTATE_PRESSED )
			{   //Down
				SetPosition( GetPosition() + NNPoint( 0.f, 1.f) * dTime * 100.f );
			}
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
			if ( m_GameKeyStates.userActiveSkillKey == KEYSTATE_PRESSED )
			{   
				// activeSkill 
			}
		}
		break;
	case TYPE_ACTIVE_SKILL:
		{
			if ( m_GameKeyStates.typeActiveSkillKey == KEYSTATE_PRESSED )
			{   // activeSkill 
				
			}
		}
		break;
	default:
		break;
	}
}

void CPlayer::SetPlayerHP(int hp)
{
	//not yet
}

void CPlayer::Render()
{
	NNObject::Render();
}