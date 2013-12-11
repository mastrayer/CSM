
#include "GameUISet.h"
#include "NNApplication.h"

GameUISet::GameUISet()
{
	mSkillCooltime[0] = 3.0f;
	mSkillCooltime[1] = 5.0f;
	//mKillCount = 25;
	//mRedKillCount = 40;
	//mHp = 80;

	swprintf_s(mSkillCooltimeBuff[0], L"%d", (int)mSkillCooltime[0]);
	swprintf_s(mSkillCooltimeBuff[1], L"%d", (int)mSkillCooltime[1]);

	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	mFPSLabel = NNLabel::Create(L"", L"¸¼Àº °íµñ", 20);
	AddChild(mFPSLabel);

	mCharacterUIFrame = NNSprite::Create(L"Sprite/CharacterUIFrame.png");
	mCharacterUIFrame->SetPosition(0.f, 500.f);
	mCharacterUIFrame->SetOpacity(0.9f);

	mSkillUIFrame = NNSprite::Create(L"Sprite/SkillUIFrame.png");
	mSkillUIFrame->SetCenter(mSkillUIFrame->GetImageWidth() / 2.f, mSkillUIFrame->GetImageHeight() / 2.f);
	mSkillUIFrame->SetPosition(width / 2.f, height / 2.f + 250);
	mSkillUIFrame->SetOpacity(0.9f);

	mHpBarBackground = NNSprite::Create(L"Sprite/GameHpBar_BackGround.png");
	mHpBarBackground->SetCenter(mHpBarBackground->GetImageWidth() / 2.f, mHpBarBackground->GetImageHeight() / 2.f);
	mHpBarBackground->SetPosition(width / 2.f, height / 2.f + 280);

	mHpBar = NNSprite::Create(L"Sprite/GameHpBar.png");
	mHpBar->SetPosition(340.f, 570.f);

	mCrown = NNSprite::Create(L"Sprite/Crown.png");
	mCrown->SetCenter(mCrown->GetImageWidth() / 2.f, mCrown->GetImageHeight() / 2.f);
	mCrown->SetPosition(width / 2.f, 30);

	mKillBar[BLUE] = NNSprite::Create(L"Sprite/KillPointBlueBar.png");
	mKillBar[BLUE]->SetPosition(width / 2.f - 32, 20);
	mKillBar[BLUE]->SetScaleX(-1.f);

	mKillBar[RED] = NNSprite::Create(L"Sprite/KillPointRedBar.png");
	mKillBar[RED]->SetPosition(width / 2.f + 32, 20);
	//mRedKillBar->SetScaleX(-1.f);


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

	mKillPoint[BLUE] = NNLabel::Create(L"40", L"¸¼Àº °íµñ", 20.f);
	mKillPoint[BLUE]->SetCenter(mKillPoint[BLUE]->GetCenterX(), mKillPoint[BLUE]->GetCenterY());
	mKillPoint[BLUE]->SetPosition(width / 2.f - 270, 20);
	mKillPoint[BLUE]->SetRGBA(0, 0, 0, 255);

	mKillPoint[RED] = NNLabel::Create(L"25", L"¸¼Àº °íµñ", 20.f);
	mKillPoint[RED]->SetCenter(mKillPoint[RED]->GetCenterX(), mKillPoint[RED]->GetCenterY());
	mKillPoint[RED]->SetPosition(width / 2.f + 250, 20);
	mKillPoint[RED]->SetRGBA(0, 0, 0, 255);
	//mRedKillPointNumber->SetScaleX(-1.f);

	AddChild(mCharacterUIFrame);
	AddChild(mSkillUIFrame);
	AddChild(mHpBarBackground);
	AddChild(mHpBar);
	AddChild(mKillBar[BLUE]);
	AddChild(mKillBar[RED]);
	AddChild(mCrown);
	AddChild(mSkillUI[0]);
	AddChild(mSkillUI[1]);
	AddChild(mSkillTimer[0]);
	AddChild(mSkillTimer[1]);
 	AddChild(mKillPoint[BLUE]);
	AddChild(mKillPoint[RED]);

	mType = NNLabel::Create(L"asdf", L"¸¼Àº °íµñ", 50.f);
	mType->SetPosition(60.f, 60.f); 
	AddChild(mType);
	
 	mTypeFace[FIRE] = NNSprite::Create(L"Sprite/SheSlime.png");
 	mTypeFace[FIRE]->SetPosition(5.f, 505.f);
	AddChild(mTypeFace[FIRE]);
 
 	mTypeFace[WATER] = NNSprite::Create(L"Sprite/BlueSlime.png");
 	mTypeFace[WATER]->SetPosition(5.f, 505.f);
	AddChild(mTypeFace[WATER]);
	
 	mTypeFace[WIND] = NNSprite::Create(L"Sprite/MetalSlime.png");
 	mTypeFace[WIND]->SetPosition(5.f, 505.f);
	AddChild(mTypeFace[WIND]);
	
	
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

void GameUISet::Update(float dTime)
{
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

 	for (int i = 0; i < 2; ++i)
 		mTypeFace[i]->SetVisible(false);

 	switch (mMyPlayer->GetPlayerType())
 	{
 	case PlayerType::TYPE_A:
 		mType->SetString(L"ºÒ");
 		mTypeFace[FIRE]->SetVisible(true);
 		break;
 	case PlayerType::TYPE_B:
 		mType->SetString(L"¹°");
 		mTypeFace[WATER]->SetVisible(true);
 		break;
 	case PlayerType::TYPE_C:
 		mType->SetString(L"¼öÁõ±â");
 		mTypeFace[WIND]->SetVisible(true);
 		break;
 	}
	swprintf_s(mFPSLabelBuff, L"%d", (int)NNApplication::GetInstance()->GetFPS());

	mFPSLabel->SetString(mFPSLabelBuff);
	mHpBar->SetScale(mMyPlayer->GetPlayerHP() / 50.f, 1.f);
	mKillBar[TeamColor::BLUE]->SetScale(CPlayerManager::GetInstance()->GetKillScore(TeamColor::BLUE) / 50.f, 1.f);
	mKillPoint[TeamColor::BLUE]->SetPosition(width / 2.f - 5 * (CPlayerManager::GetInstance()->GetKillScore(TeamColor::BLUE)) - 60, 20);
	mKillBar[TeamColor::RED]->SetScale(CPlayerManager::GetInstance()->GetKillScore(TeamColor::RED) / 50.f, 1.f);
	mKillPoint[TeamColor::RED]->SetPosition(width / 2.f + 5 * CPlayerManager::GetInstance()->GetKillScore(TeamColor::RED) + 40, 20);

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
