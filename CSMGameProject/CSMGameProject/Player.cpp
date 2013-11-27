
#include "Player.h"

#include "NNAudioSystem.h"
#include "NNNetworkSystem.h"

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
	default:
		break;
	}

	/* Player Sprite Setting */
	m_PlayerSprite = NNSprite::Create( imagePath );
	AddChild( m_PlayerSprite );

	m_PlayerSprite->SetCenter( m_PlayerSprite->GetImageWidth()/2.f, m_PlayerSprite->GetImageHeight()/2.f );
	/* // */
}


void CPlayer::Update( float dTime )
{
	NNObject::Update( dTime );
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
			if (m_GameKeyStates.upDirectKey == KEYSTATE_PRESSED )
			{   //UP
				SetPosition( GetPosition() + NNPoint( 0.f, -1.f) * dTime * 100.f );
			}
			if ( m_GameKeyStates.downDirectKey == KEYSTATE_PRESSED )
			{   //Down
				SetPosition( GetPosition() + NNPoint( 0.f, 1.f) * dTime * 100.f );
			}
		}
		break;
	case ATTAACK:
		{
		}
		break;
	case DIE:
		{
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