
#include "PlayerUI.h"

PlayerUI::PlayerUI()
{
	m_HpBar = NNSprite::Create( L"Sprite/hpbar.png" );
	//m_HpBarFrame = NNSprite::Create( L"Sprite/hpbar_frame.png" );
	m_HpBar->SetCenter( m_HpBar->GetImageWidth()/2.f, m_HpBar->GetImageHeight()/2.f );
	m_HpBarFrame->SetCenter( m_HpBar->GetImageWidth()/2.f, m_HpBar->GetImageHeight()/2.f );
	AddChild( m_HpBar );
	//AddChild( m_HpBarFrame );
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
}