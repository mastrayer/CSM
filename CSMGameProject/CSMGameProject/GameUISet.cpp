
#include "GameUISet.h"
#include "NNApplication.h"

GameUISet::GameUISet()
{
	m_TypeSkillCooltime = 5;
	m_UserSkillCooltime = 10;

	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	m_FPSLabel = NNLabel::Create( L"", L"¸¼Àº °íµñ", 20 );
	AddChild( m_FPSLabel );

	m_UserSkillBarEffect = NNSprite::Create( L"Sprite/SkillBarEffect.jpg" );
	m_UserSkillBarEffect->SetCenter( m_UserSkillBarEffect->GetImageWidth()/2.f, m_UserSkillBarEffect->GetImageHeight()/2.f );
	m_UserSkillBarEffect->SetPosition( width/2.f - 40, height/2.f + 200 );
	AddChild( m_UserSkillBarEffect );

	m_UserSkillBarEffect->SetVisible(true);

	m_TypeSkillBarEffect = NNSprite::Create( L"Sprite/SkillBarEffect.jpg" );
	m_TypeSkillBarEffect->SetCenter( m_TypeSkillBarEffect->GetImageWidth()/2.f, m_TypeSkillBarEffect->GetImageHeight()/2.f );
	m_TypeSkillBarEffect->SetPosition( width/2.f + 40, height/2.f + 200 );
	AddChild( m_TypeSkillBarEffect );

	m_TypeSkillBarEffect->SetVisible(true);

	m_UserSkillUI = NNSprite::Create( L"Sprite/UserSkillUI_0.png" );
	m_UserSkillUI->SetCenter( m_UserSkillUI->GetImageWidth()/2.f, m_UserSkillUI->GetImageHeight()/2.f );
	m_UserSkillUI->SetPosition( width/2.f + 40, height/2.f + 200 );
	AddChild( m_UserSkillUI );

	m_UserSkillTimer = NNLabel::Create( L"20", L"¸¼Àº °íµñ", 40.f );
	m_UserSkillTimer->SetCenter( m_UserSkillUI->GetCenterX(), m_UserSkillUI->GetCenterY() );
	m_UserSkillTimer->SetPosition( width/2.f + 40, height/2.f + 200 );
	m_UserSkillTimer->SetRGBA(255,255,255,1);
	AddChild( m_UserSkillTimer ); 

	m_TypeSkillUI = NNSprite::Create( L"Sprite/TypeSkillUI_0.png" );
	m_TypeSkillUI->SetCenter( m_TypeSkillUI->GetImageWidth()/2.f, m_TypeSkillUI->GetImageHeight()/2.f );
	m_TypeSkillUI->SetPosition( width/2.f - 40, height/2.f + 200 );
	AddChild( m_TypeSkillUI );

	m_TypeSkillTimer = NNLabel::Create( L"5", L"¸¼Àº °íµñ", 40.f );
	m_TypeSkillTimer->SetCenter( m_TypeSkillUI->GetCenterX(), m_TypeSkillUI->GetCenterY() );
	m_TypeSkillTimer->SetPosition( width/2.f - 40, height/2.f + 200 );
	m_TypeSkillTimer->SetRGBA(255,255,255,1);
	AddChild( m_TypeSkillTimer );

	ZeroMemory( m_FPSLabelBuff, sizeof(m_FPSLabelBuff) );
}
GameUISet::~GameUISet()
{

}

void GameUISet::Render()
{
	NNUISet::Render();
}
void GameUISet::Update( float dTime )
{
	NNUISet::Update( dTime );

	swprintf_s( m_FPSLabelBuff, L"%d", (int)NNApplication::GetInstance()->GetFPS() );
	m_FPSLabel->SetString( m_FPSLabelBuff );

	m_TypeSkillUI->SetOpacity( m_TypeSkillCooltime/10 );
	m_UserSkillUI->SetOpacity( m_TypeSkillCooltime/20 );
}