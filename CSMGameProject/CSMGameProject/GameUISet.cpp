
#include "GameUISet.h"
#include "NNApplication.h"
#include "LabelManager.h"

GameUISet::GameUISet()
{
	m_Hp = 50;
// 	m_TypeSkillCooltime = 5.f;
// 	m_UserSkillCooltime = 10.f;
	m_SkillCooltime[0] = 5.f;
	m_SkillCooltime[1] = 10.f;

	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	m_FPSLabel = NNLabel::Create( L"", L"¸¼Àº °íµñ", 20 );
	AddChild( m_FPSLabel );

	m_SkillBarEffect[0] = NNSprite::Create(L"Sprite/SkillBarEffect.png");
	m_SkillBarEffect[0]->SetCenter(m_SkillBarEffect[0]->GetImageWidth() / 2.f, m_SkillBarEffect[0]->GetImageHeight() / 2.f);
	m_SkillBarEffect[0]->SetPosition(width / 2.f - 40, height / 2.f + 200);

	m_SkillBarEffect[1] = NNSprite::Create(L"Sprite/SkillBarEffect.png");
	m_SkillBarEffect[1]->SetCenter(m_SkillBarEffect[1]->GetImageWidth() / 2.f, m_SkillBarEffect[1]->GetImageHeight() / 2.f);
	m_SkillBarEffect[1]->SetPosition(width / 2.f + 40, height / 2.f + 200);

	m_SkillUI[0] = NNSprite::Create(L"Sprite/UserSkillUI_0.png");
	m_SkillUI[0]->SetCenter(m_SkillUI[0]->GetImageWidth() / 2.f, m_SkillUI[0]->GetImageHeight() / 2.f);
	m_SkillUI[0]->SetPosition(width / 2.f + 40, height / 2.f + 200);

	m_SkillUI[1] = NNSprite::Create(L"Sprite/TypeSkillUI_0.png");
	m_SkillUI[1]->SetCenter(m_SkillUI[1]->GetImageWidth() / 2.f, m_SkillUI[1]->GetImageHeight() / 2.f);
	m_SkillUI[1]->SetPosition(width / 2.f - 40, height / 2.f + 200);
	
	m_SkillTimer[0] = NNLabel::Create(L"20", L"¸¼Àº °íµñ", 40.f);
	m_SkillTimer[0]->SetCenter(m_SkillUI[0]->GetCenterX(), m_SkillUI[0]->GetCenterY());
	m_SkillTimer[0]->SetPosition(width / 2.f + 40, height / 2.f + 200);
	m_SkillTimer[0]->SetRGBA(255, 255, 255, 1);

	m_SkillTimer[1] = NNLabel::Create(L"5", L"¸¼Àº °íµñ", 40.f);
	m_SkillTimer[1]->SetCenter(m_SkillUI[1]->GetCenterX(), m_SkillUI[1]->GetCenterY());
	m_SkillTimer[1]->SetPosition(width / 2.f - 40, height / 2.f + 200);
	m_SkillTimer[1]->SetRGBA(255, 255, 255, 1);

	AddChild(m_SkillBarEffect[0]);
	AddChild(m_SkillBarEffect[1]);
	AddChild(m_SkillUI[0]);
	AddChild(m_SkillUI[1]);
	AddChild(m_SkillTimer[0]);
	AddChild(m_SkillTimer[1]);
	/*
	m_UserSkillBarEffect = NNSprite::Create( L"Sprite/SkillBarEffect.png" );
	m_UserSkillBarEffect->SetCenter( m_UserSkillBarEffect->GetImageWidth()/2.f, m_UserSkillBarEffect->GetImageHeight()/2.f );
	m_UserSkillBarEffect->SetPosition( width/2.f - 40, height/2.f + 200 );
	AddChild( m_UserSkillBarEffect );

	m_UserSkillBarEffect->SetVisible(true);

	m_TypeSkillBarEffect = NNSprite::Create( L"Sprite/SkillBarEffect.png" );
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
	*/

	m_CharacterFace = NNSprite::Create( L"Sprite/BlueSlime.png" );
	m_CharacterFace->SetCenter( m_CharacterFace->GetImageWidth()/2.f, m_CharacterFace->GetImageHeight()/2.f );
	m_CharacterFace->SetPosition( 60.f, 60.f );
	AddChild( m_CharacterFace );
	

	m_HpBar = NNSprite::Create( L"Sprite/GameHpBar.png" );
	m_HpBar->SetCenter( m_HpBar->GetImageWidth()/2.f, m_HpBar->GetImageHeight()/2.f );
	m_HpBar->SetPosition( 60.f, m_CharacterFace->GetImageHeight() + 30.f );
	AddChild( m_HpBar );

	m_MyPlayer = CPlayerManager::GetInstance()->GetMyPlayer();
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
	m_HpBar->SetScale( m_Hp/100.f, 1.f );

	for (int i = 0; i < SKILL_COUNT; ++i)
		ControlSkillUI((PlayerState)(TYPE_ACTIVE_SKILL + i), dTime);

// 	if(m_MyPlayer->GetSkillCooldown(TYPE_ACTIVE_SKILL) == true)
// 	{
// 		m_MyPlayer->SetSkillCount(m_MyPlayer->GetSkillCount() + dTime, TYPE_ACTIVE_SKILL);
// 		m_TypeSkillUI->SetOpacity(m_MyPlayer->GetSkillCount() / m_TypeSkillCooltime);
// 	}else
// 		m_TypeSkillUI->SetOpacity( 1.f );
// 
// 	m_UserSkillUI->SetOpacity( m_TypeSkillCooltime/20 );
}

void GameUISet::ControlSkillUI(PlayerState skillType, float dTime)
{
	if (m_MyPlayer->GetSkillCooldown(skillType) == true)
	{
		m_MyPlayer->SetSkillCount(m_MyPlayer->GetSkillCount(skillType) + dTime, skillType);
		m_SkillUI[skillType - TYPE_ACTIVE_SKILL]->SetOpacity(m_MyPlayer->GetSkillCount(skillType) / m_SkillCooltime[skillType - TYPE_ACTIVE_SKILL]);

		if (m_MyPlayer->GetSkillCount(skillType) >= m_SkillCooltime[skillType - TYPE_ACTIVE_SKILL])
		{
			m_MyPlayer->SetSkillCooldown(false, skillType);
			m_MyPlayer->SetSkillCount(0.f, skillType);
		}
	}else
		m_SkillUI[skillType - TYPE_ACTIVE_SKILL]->SetOpacity( 1.f );
}
