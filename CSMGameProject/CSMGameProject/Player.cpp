#include "Player.h"



CPlayer::CPlayer( void )
	: m_PlayerSprite(NULL)
{
	TransState(PLAYER_STATE_IDLE);
}

CPlayer::~CPlayer( void )
{
}

void CPlayer::TransState( short state )
{
	m_PlayerState = state;
	if ( m_PlayerSprite != NULL )
	{
		RemoveChild( m_PlayerSprite );
	}
	m_PlayerSprite = NNSprite::Create( L"Sprite/walk_0.png" );
	m_PlayerSprite->SetCenter( m_PlayerSprite->GetImageWidth()/2.f, m_PlayerSprite->GetImageHeight()/2.f );
	AddChild( m_PlayerSprite );
	 
	m_PlayerSprite->SetCenter( m_PlayerSprite->GetImageWidth()/2.f, m_PlayerSprite->GetImageHeight()/2.f );

	m_HpBar = NNSprite::Create( L"Sprite/hpbar.png" );
	//m_HpBarFrame = NNSprite::Create( L"Sprite/hpbar_frame.png" );
	m_HpBar->SetCenter( m_HpBar->GetImageWidth()/2.f, m_PlayerSprite->GetImageHeight()/2.f );
	m_HpBar->SetPosition( 0.f, -15.f );
	//m_HpBarFrame->SetPosition( 0.f, -30.f );
	AddChild( m_HpBar );
	//AddChild( m_HpBarFrame );
}


void CPlayer::Update( float dTime )
{
	
	NNObject::Update( dTime );

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
void CPlayer::Render()
{
	NNObject::Render();
}