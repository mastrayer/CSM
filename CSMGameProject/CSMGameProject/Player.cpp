#include "Player.h"



CPlayer::CPlayer(void):m_PlayerSprite(NULL)
{
	TransState(IDLE);
}

CPlayer::~CPlayer(void)
{
}

void CPlayer::TransState(PlayerState state)
{
	m_PlayerState = state;
	if(m_PlayerSprite != NULL)
		RemoveChild(m_PlayerSprite);
	m_PlayerSprite = NNSprite::Create(L"Sprite/walk_0.png");
	SetCenter(m_PlayerSprite->GetImageWidth()/2.f, m_PlayerSprite->GetImageHeight()/2.f);
	AddChild(m_PlayerSprite);
}


void CPlayer::Update( float dTime)
{

	//Move myPlayer with Game Key States.
	//Check Moving Input, and set Position to d
	if ( m_GameKeyStates.leftDirectKey ==  KEY_DOWN  || 
		m_GameKeyStates.leftDirectKey == KEY_PRESSED )
	{
		//Left
		SetPosition( GetPosition() + NNPoint( 1.f, 0.f) * dTime * 100.f );
	}
	if ( m_GameKeyStates.rightDirectKey == KEY_DOWN  || 
		m_GameKeyStates.rightDirectKey == KEY_PRESSED)
	{
		//Right
		SetPosition( GetPosition() + NNPoint( -1.f, 0.f) * dTime * 100.f );
	}
	if (m_GameKeyStates.upDirectKey == KEY_DOWN  || 
		m_GameKeyStates.upDirectKey == KEY_PRESSED)
	{
		//UP
		SetPosition( GetPosition() + NNPoint( 0.f, -1.f) * dTime * 100.f );
	}
	if ( m_GameKeyStates.downDirectKey == KEY_DOWN  || 
		m_GameKeyStates.downDirectKey == KEY_PRESSED)
	{
		//Down
		SetPosition( GetPosition() + NNPoint( 0.f, 1.f) * dTime * 100.f );
	}
	//Change Image By now Frame.
	NNPoint mousePoint = NNInputSystem::GetInstance()->GetMousePosition();
	SetRotation(atan2f(mousePoint.GetY() - 300.f, mousePoint.GetX() - 400.f) * 180.0f / 3.14f);
}
void CPlayer::Render()
{
	NNObject::Render();
}