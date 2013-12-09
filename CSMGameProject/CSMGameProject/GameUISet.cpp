
#include "GameUISet.h"
#include "NNApplication.h"

GameUISet::GameUISet()
{
	m_Hp = 80;
	m_SkillCooltime[0] = 5.f;
	m_SkillCooltime[1] = 5.f;
	swprintf_s(m_SkillCooltimeBuff[0], L"%d", (int)m_SkillCooltime[0]);
	swprintf_s(m_SkillCooltimeBuff[1], L"%d", (int)m_SkillCooltime[1]);

	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	m_FPSLabel = NNLabel::Create( L"", L"¸¼Àº °íµñ", 20 );
	AddChild( m_FPSLabel );

	m_CharacterUIFrame = NNSprite::Create(L"Sprite/CharacterUIFrame.png");
	m_CharacterUIFrame->SetPosition(0.f, 450.f);

	m_SkillUIFrame = NNSprite::Create(L"Sprite/SkillUIFrame.png");
	m_SkillUIFrame->SetCenter(m_SkillUIFrame->GetImageWidth() / 2.f, m_SkillUIFrame->GetImageHeight() / 2.f);
	m_SkillUIFrame->SetPosition(width / 2.f, height / 2.f + 250);

	m_HpBarBackground = NNSprite::Create(L"Sprite/GameHpBar_BackGround.png");
	m_HpBarBackground->SetCenter(m_HpBarBackground->GetImageWidth() / 2.f, m_HpBarBackground->GetImageHeight() / 2.f);
	m_HpBarBackground->SetPosition(width / 2.f, height / 2.f + 280);

	m_HpBar = NNSprite::Create(L"Sprite/GameHpBar.png");
	m_HpBar->SetPosition(340.f, 570.f);
	
	m_SkillUI[0] = NNSprite::Create(L"Sprite/TypeSkillUI_0.png");
	m_SkillUI[0]->SetCenter(m_SkillUI[0]->GetImageWidth() / 2.f, m_SkillUI[0]->GetImageHeight() / 2.f);
	m_SkillUI[0]->SetPosition(width / 2.f - 32, height / 2.f + 235);

	m_SkillUI[1] = NNSprite::Create(L"Sprite/UserSkillUI_0.png");
	m_SkillUI[1]->SetCenter(m_SkillUI[1]->GetImageWidth() / 2.f, m_SkillUI[1]->GetImageHeight() / 2.f);
	m_SkillUI[1]->SetPosition(width / 2.f + 32, height / 2.f + 235);
	
	m_SkillTimer[0] = NNLabel::Create(L"", L"¸¼Àº °íµñ", 40.f);
	m_SkillTimer[0]->SetCenter(m_SkillUI[0]->GetCenterX(), m_SkillUI[0]->GetCenterY());
	m_SkillTimer[0]->SetPosition(width / 2.f - 35, height / 2.f + 250);
	m_SkillTimer[0]->SetRGBA(255, 255, 255, 1);

	m_SkillTimer[1] = NNLabel::Create(L"", L"¸¼Àº °íµñ", 40.f);
	m_SkillTimer[1]->SetCenter(m_SkillUI[1]->GetCenterX(), m_SkillUI[1]->GetCenterY());
	m_SkillTimer[1]->SetPosition(width / 2.f + 35, height / 2.f + 250);
	m_SkillTimer[1]->SetRGBA(255, 255, 255, 1);
	
	AddChild(m_CharacterUIFrame);
	AddChild(m_SkillUIFrame);
	AddChild(m_HpBarBackground);
	AddChild(m_HpBar);
	AddChild(m_SkillUI[0]);
	AddChild(m_SkillUI[1]);
	AddChild(m_SkillTimer[0]);
	AddChild(m_SkillTimer[1]);
	
	m_CharacterFace = NNSprite::Create( L"Sprite/BlueSlime.png" );
	m_CharacterFace->SetCenter( m_CharacterFace->GetImageWidth()/2.f, m_CharacterFace->GetImageHeight()/2.f );
	m_CharacterFace->SetPosition( 60.f, 60.f );
	AddChild( m_CharacterFace );
	
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
}

void GameUISet::ControlSkillUI(PlayerState skillType, float dTime)
{
	if (m_MyPlayer->GetSkillCooldown(skillType) == true)
	{
		m_MyPlayer->SetSkillCount(m_MyPlayer->GetSkillCount(skillType) + dTime, skillType);
		m_SkillUI[skillType - TYPE_ACTIVE_SKILL]->SetOpacity(m_MyPlayer->GetSkillCount(skillType) / m_SkillCooltime[skillType - TYPE_ACTIVE_SKILL]);

		swprintf_s(m_SkillCooltimeBuff[skillType - TYPE_ACTIVE_SKILL], L"%.0f", m_SkillCooltime[skillType - TYPE_ACTIVE_SKILL] - m_MyPlayer->GetSkillCount(skillType));
		m_SkillTimer[skillType - TYPE_ACTIVE_SKILL]->SetString(m_SkillCooltimeBuff[skillType - TYPE_ACTIVE_SKILL]);

		if (m_MyPlayer->GetSkillCount(skillType) >= m_SkillCooltime[skillType - TYPE_ACTIVE_SKILL])
		{
			m_MyPlayer->SetSkillCooldown(false, skillType);
			m_MyPlayer->SetSkillCount(0.f, skillType);

			m_SkillUI[skillType - TYPE_ACTIVE_SKILL]->SetOpacity(1.f);
			m_SkillTimer[skillType - TYPE_ACTIVE_SKILL]->SetString(L"");
		}
	}
}
