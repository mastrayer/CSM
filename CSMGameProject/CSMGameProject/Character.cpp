#include "Character.h"


CCharacter::CCharacter(void)
{
	m_CharacterSprite = NNSprite::Create(L"Sprite/character.png");
	m_CharacterSprite->SetPosition( 0.f, 0.f );
	AddChild(m_CharacterSprite);
}


CCharacter::~CCharacter(void)
{
}

void CCharacter::Update( float dTime)
{
	//Check Moving Input, and set Position to move
	if ( NNInputSystem::GetInstance()->GetKeyState( 'A' ) == KEY_DOWN  || 
		NNInputSystem::GetInstance()->GetKeyState( 'A' ) == KEY_PRESSED)
	{
		//Left
		SetPosition( GetPosition() + NNPoint(-100.f,0.f) * dTime );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( 'D' ) == KEY_DOWN  || 
		NNInputSystem::GetInstance()->GetKeyState( 'D' ) == KEY_PRESSED)
	{
		//Right
		SetPosition( GetPosition() + NNPoint(100.f,0.f) * dTime );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( 'W' ) == KEY_DOWN  || 
		NNInputSystem::GetInstance()->GetKeyState( 'W' ) == KEY_PRESSED)
	{
		//UP
		SetPosition( GetPosition() + NNPoint(0.f,-100.f) * dTime );
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( 'S' ) == KEY_DOWN  || 
		NNInputSystem::GetInstance()->GetKeyState( 'S' ) == KEY_PRESSED)
	{
		//Down
		SetPosition( GetPosition() + NNPoint(0.f,100.f) * dTime );
	}
}
void CCharacter::Render()
{
	NNObject::Render();
}