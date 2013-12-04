
#include "PlayerUI.h"
#include "Player.h"
#include "NNApplication.h"

PlayerUI::PlayerUI()
{
	//m_Hp = (dynamic_cast<CPlayer*>(GetParent()))->GetPlayerHP();
	m_Hp = 1;

	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();
	
	m_HpBar = NNSprite::Create( L"Sprite/hpbar.png" );
	//m_HpBarFrame = NNSprite::Create( L"Sprite/hpbar_frame.png" );
	//m_HpBar->SetCenter( m_HpBar->GetImageWidth()/2.f, m_HpBar->GetImageHeight()/2.f );
	m_HpBar->SetPosition( -30.f, -50.f );
	AddChild( m_HpBar );
}

PlayerUI::~PlayerUI()
{
}

void PlayerUI::Render()
{
	NNObject::Render();
}

void PlayerUI::Update( float dTime )
{
	NNObject::Update( dTime );
	
	m_HpBar->SetScale( m_Hp/100.f, 1.f );
}