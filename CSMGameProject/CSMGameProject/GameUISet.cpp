
#include "GameUISet.h"
#include "NNApplication.h"

GameUISet::GameUISet()
{
	mHp = 80;
	mSkillCooltime[0] = 0.1f;
	mSkillCooltime[1] = 0.1f;
	swprintf_s(mSkillCooltimeBuff[0], L"%d", (int)mSkillCooltime[0]);
	swprintf_s(mSkillCooltimeBuff[1], L"%d", (int)mSkillCooltime[1]);

	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	mFPSLabel = NNLabel::Create( L"", L"¸¼Àº °íµñ", 20 );
	AddChild( mFPSLabel );

	mCharacterUIFrame = NNSprite::Create(L"Sprite/CharacterUIFrame.png");
	mCharacterUIFrame->SetPosition(0.f, 450.f);

	mSkillUIFrame = NNSprite::Create(L"Sprite/SkillUIFrame.png");
	mSkillUIFrame->SetCenter(mSkillUIFrame->GetImageWidth() / 2.f, mSkillUIFrame->GetImageHeight() / 2.f);
	mSkillUIFrame->SetPosition(width / 2.f, height / 2.f + 250);

	mHpBarBackground = NNSprite::Create(L"Sprite/GameHpBar_BackGround.png");
	mHpBarBackground->SetCenter(mHpBarBackground->GetImageWidth() / 2.f, mHpBarBackground->GetImageHeight() / 2.f);
	mHpBarBackground->SetPosition(width / 2.f, height / 2.f + 280);

	mHpBar = NNSprite::Create(L"Sprite/GameHpBar.png");
	mHpBar->SetPosition(340.f, 570.f);
	
	mSkillUI[0] = NNSprite::Create(L"Sprite/TypeSkillUI.png");
	mSkillUI[0]->SetCenter(mSkillUI[0]->GetImageWidth() / 2.f, mSkillUI[0]->GetImageHeight() / 2.f);
	mSkillUI[0]->SetPosition(width / 2.f - 32, height / 2.f + 235);

	mSkillUI[1] = NNSprite::Create(L"Sprite/UserSkillUI.png");
	mSkillUI[1]->SetCenter(mSkillUI[1]->GetImageWidth() / 2.f, mSkillUI[1]->GetImageHeight() / 2.f);
	mSkillUI[1]->SetPosition(width / 2.f + 32, height / 2.f + 235);
	
	mSkillTimer[0] = NNLabel::Create(L"", L"¸¼Àº °íµñ", 40.f);
	mSkillTimer[0]->SetCenter(mSkillUI[0]->GetCenterX(), mSkillUI[0]->GetCenterY());
	mSkillTimer[0]->SetPosition(width / 2.f - 35, height / 2.f + 250);
	mSkillTimer[0]->SetRGBA(255, 255, 255, 255);

	mSkillTimer[1] = NNLabel::Create(L"", L"¸¼Àº °íµñ", 40.f);
	mSkillTimer[1]->SetCenter(mSkillUI[1]->GetCenterX(), mSkillUI[1]->GetCenterY());
	mSkillTimer[1]->SetPosition(width / 2.f + 35, height / 2.f + 250);
	mSkillTimer[1]->SetRGBA(255, 255, 255, 255);
	
	AddChild(mCharacterUIFrame);
	AddChild(mSkillUIFrame);
	AddChild(mHpBarBackground);
	AddChild(mHpBar);
	AddChild(mSkillUI[0]);
	AddChild(mSkillUI[1]);
	AddChild(mSkillTimer[0]);
	AddChild(mSkillTimer[1]);
	
	mCharacterFace = NNSprite::Create( L"Sprite/BlueSlime.png" );
	mCharacterFace->SetCenter( mCharacterFace->GetImageWidth()/2.f, mCharacterFace->GetImageHeight()/2.f );
	mCharacterFace->SetPosition( 60.f, 60.f );
	AddChild( mCharacterFace );
	
	mMyPlayer = CPlayerManager::GetInstance()->GetMyPlayer();
	ZeroMemory( mFPSLabelBuff, sizeof(mFPSLabelBuff) );
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

	swprintf_s( mFPSLabelBuff, L"%d", (int)NNApplication::GetInstance()->GetFPS() );

	mFPSLabel->SetString( mFPSLabelBuff );
	mHpBar->SetScale( mHp/100.f, 1.f );

	for (int i = 0; i < SKILL_COUNT; ++i)
		ControlSkillUI((PlayerState)(TYPE_ACTIVE_SKILL + i), dTime);
}

void GameUISet::ControlSkillUI(PlayerState skillType, float dTime)
{
	if (mMyPlayer->GetSkillCooldown(skillType) == true)
	{
		mMyPlayer->SetSkillCount(mMyPlayer->GetSkillCount(skillType) + dTime, skillType);
		mSkillUI[skillType - TYPE_ACTIVE_SKILL]->SetOpacity(mMyPlayer->GetSkillCount(skillType) / mSkillCooltime[skillType - TYPE_ACTIVE_SKILL]);

		swprintf_s(mSkillCooltimeBuff[skillType - TYPE_ACTIVE_SKILL], L"%.0f", mSkillCooltime[skillType - TYPE_ACTIVE_SKILL] - mMyPlayer->GetSkillCount(skillType));
		mSkillTimer[skillType - TYPE_ACTIVE_SKILL]->SetString(mSkillCooltimeBuff[skillType - TYPE_ACTIVE_SKILL]);

		if (mMyPlayer->GetSkillCount(skillType) >= mSkillCooltime[skillType - TYPE_ACTIVE_SKILL])
		{
			mMyPlayer->SetSkillCooldown(false, skillType);
			mMyPlayer->SetSkillCount(0.f, skillType);

			mSkillUI[skillType - TYPE_ACTIVE_SKILL]->SetOpacity(1.f);
			mSkillTimer[skillType - TYPE_ACTIVE_SKILL]->SetString(L"");
		}
	}
}
