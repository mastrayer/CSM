
#include "PlayerUI.h"
#include "Player.h"

PlayerUI::PlayerUI()
{
	//m_Hp = (dynamic_cast<CPlayer*>(GetParent()))->GetPlayerHP();
	m_Hp = 100;
	m_TypeSkillCooltime = 5;
	m_UserSkillCooltime = 10;
	m_HpBar = NNSprite::Create( L"Sprite/hpbar.png" );
	//m_HpBarFrame = NNSprite::Create( L"Sprite/hpbar_frame.png" );
	m_HpBar->SetCenter( m_HpBar->GetImageWidth()/2.f, m_HpBar->GetImageHeight()/2.f + 50 );
	AddChild( m_HpBar );
	
	m_UserSkillUI = NNSprite::Create( L"Sprite/UserSkillUI_0.png" );
	m_UserSkillUI->SetCenter( m_UserSkillUI->GetImageWidth()/2.f - 40, m_UserSkillUI->GetImageHeight()/2.f - 220 );
	AddChild( m_UserSkillUI );

	m_UserSkillTimer = NNLabel::Create( L"20", L"¸¼Àº °íµñ", 40.f );
	m_UserSkillTimer->SetCenter( m_UserSkillUI->GetCenterX() - 10, m_UserSkillUI->GetCenterY() - 10 );
	m_UserSkillTimer->SetRGBA(255,255,255,1);
	AddChild( m_UserSkillTimer ); 
	
	m_TypeSkillUI = NNSprite::Create( L"Sprite/TypeSkillUI_0.png" );
	m_TypeSkillUI->SetCenter( m_TypeSkillUI->GetImageWidth()/2.f + 40, m_TypeSkillUI->GetImageHeight()/2.f - 220 );
	AddChild( m_TypeSkillUI );

	m_TypeSkillTimer = NNLabel::Create( L"5", L"¸¼Àº °íµñ", 40.f );
	m_TypeSkillTimer->SetCenter( m_TypeSkillUI->GetCenterX() - 10, m_TypeSkillUI->GetCenterY() - 10 );
	m_TypeSkillTimer->SetRGBA(255,255,255,1);
	AddChild( m_TypeSkillTimer );

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
	
	m_HpBar->SetScale( m_Hp/100, 1.f );
	m_TypeSkillUI->SetOpacity( m_TypeSkillCooltime/10 );
	m_UserSkillUI->SetOpacity( m_TypeSkillCooltime/20 );
	
}