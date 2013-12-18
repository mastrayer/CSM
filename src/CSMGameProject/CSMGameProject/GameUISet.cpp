
#include "GameUISet.h"
#include "GameManager.h"

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

	mCharacterUIFrame = NNSprite::Create(L"Resource/Sprite/CharacterUIFrame.png");
	mCharacterUIFrame->SetPosition(0.f, 500.f);
	mCharacterUIFrame->SetOpacity(0.9f);

	mSkillUIFrame = NNSprite::Create(L"Resource/Sprite/SkillUIFrame.png");
	mSkillUIFrame->SetCenter(mSkillUIFrame->GetImageWidth() / 2.f, mSkillUIFrame->GetImageHeight() / 2.f);
	mSkillUIFrame->SetPosition(width / 2.f, height / 2.f + 250);
	mSkillUIFrame->SetOpacity(0.9f);

	mHpBarBackground = NNSprite::Create(L"Resource/Sprite/GameHpBar_BackGround.png");
	mHpBarBackground->SetCenter(mHpBarBackground->GetImageWidth() / 2.f, mHpBarBackground->GetImageHeight() / 2.f);
	mHpBarBackground->SetPosition(width / 2.f, height / 2.f + 280);

	mHpBar = NNSprite::Create(L"Resource/Sprite/GameHpBar.png");
	mHpBar->SetPosition(340.f, 570.f);

	mCrown = NNSprite::Create(L"Resource/Sprite/Crown.png");
	mCrown->SetCenter(mCrown->GetImageWidth() / 2.f, mCrown->GetImageHeight() / 2.f);
	mCrown->SetPosition(width / 2.f, 30);

	mKillBar[BLUE] = NNSprite::Create(L"Resource/Sprite/KillPointBlueBar.png");
	mKillBar[BLUE]->SetPosition(width / 2.f - 32, 20);
	mKillBar[BLUE]->SetScaleX(-1.f);

	mKillBar[RED] = NNSprite::Create(L"Resource/Sprite/KillPointRedBar.png");
	mKillBar[RED]->SetPosition(width / 2.f + 32, 20);
	//mRedKillBar->SetScaleX(-1.f);

	mTypeSkillUI[ZERO] = NNSprite::Create(L"Resource/Sprite/TypeSkillUI/ZeroTypeSkillUI.png");
	mTypeSkillUI[ZERO]->SetCenter(mTypeSkillUI[ZERO]->GetImageWidth() / 2.f, mTypeSkillUI[ZERO]->GetImageHeight() / 2.f);
	mTypeSkillUI[ZERO]->SetPosition(width / 2.f - 32, height / 2.f + 235);

	mTypeSkillUI[FIRE] = NNSprite::Create(L"Resource/Sprite/TypeSkillUI/FireTypeSkillUI.png");
	mTypeSkillUI[FIRE]->SetCenter(mTypeSkillUI[FIRE]->GetImageWidth() / 2.f, mTypeSkillUI[FIRE]->GetImageHeight() / 2.f);
	mTypeSkillUI[FIRE]->SetPosition(width / 2.f - 32, height / 2.f + 235);

	mTypeSkillUI[WATER] = NNSprite::Create(L"Resource/Sprite/TypeSkillUI/WaterTypeSkillUI.png");
	mTypeSkillUI[WATER]->SetCenter(mTypeSkillUI[WATER]->GetImageWidth() / 2.f, mTypeSkillUI[WATER]->GetImageHeight() / 2.f);
	mTypeSkillUI[WATER]->SetPosition(width / 2.f - 32, height / 2.f + 235);

	mTypeSkillUI[WIND] = NNSprite::Create(L"Resource/Sprite/TypeSkillUI/WindTypeSkillUI.png");
	mTypeSkillUI[WIND]->SetCenter(mTypeSkillUI[WIND]->GetImageWidth() / 2.f, mTypeSkillUI[WIND]->GetImageHeight() / 2.f);
	mTypeSkillUI[WIND]->SetPosition(width / 2.f - 32, height / 2.f + 235);

	mTypeSkillUI[EARTH] = NNSprite::Create(L"Resource/Sprite/TypeSkillUI/EarthTypeSkillUI.png");
	mTypeSkillUI[EARTH]->SetCenter(mTypeSkillUI[EARTH]->GetImageWidth() / 2.f, mTypeSkillUI[EARTH]->GetImageHeight() / 2.f);
	mTypeSkillUI[EARTH]->SetPosition(width / 2.f - 32, height / 2.f + 235);

	mUserSkillUI = NNSprite::Create(L"Resource/Sprite/UserSkillUI/Dash.png");
	mUserSkillUI->SetCenter(mUserSkillUI->GetImageWidth() / 2.f, mUserSkillUI->GetImageHeight() / 2.f);
	mUserSkillUI->SetPosition(width / 2.f + 32, height / 2.f + 235);

	/*mSkillUI[0] = NNSprite::Create(L"Resource/Sprite/TypeSkillUI.png");
	mSkillUI[0]->SetCenter(mSkillUI[0]->GetImageWidth() / 2.f, mSkillUI[0]->GetImageHeight() / 2.f);
	mSkillUI[0]->SetPosition(width / 2.f - 32, height / 2.f + 235);

	mSkillUI[1] = NNSprite::Create(L"Resource/Sprite/UserSkillUI.png");
	mSkillUI[1]->SetCenter(mSkillUI[1]->GetImageWidth() / 2.f, mSkillUI[1]->GetImageHeight() / 2.f);
	mSkillUI[1]->SetPosition(width / 2.f + 32, height / 2.f + 235);*/

	//TypeSKill icon cooltime count label
	mTypeSKillTimer = NNLabel::Create(L"", L"¸¼Àº °íµñ", 40.f);
	mTypeSKillTimer->SetCenter(mTypeSKillTimer->GetCenterX(), mTypeSKillTimer->GetCenterY());
	mTypeSKillTimer->SetPosition(width / 2.f - 35, height / 2.f + 250);
	mTypeSKillTimer->SetRGBA(255, 255, 255, 255);

	/*mTypeSKillTimer[WATER] = NNLabel::Create(L"", L"¸¼Àº °íµñ", 40.f);
	mTypeSKillTimer[WATER]->SetCenter(mTypeSKillTimer[WATER]->GetCenterX(), mTypeSKillTimer[WATER]->GetCenterY());
	mTypeSKillTimer[WATER]->SetPosition(width / 2.f - 35, height / 2.f + 250);
	mTypeSKillTimer[WATER]->SetRGBA(255, 255, 255, 255);

	mTypeSKillTimer[WIND] = NNLabel::Create(L"", L"¸¼Àº °íµñ", 40.f);
	mTypeSKillTimer[WIND]->SetCenter(mTypeSKillTimer[WIND]->GetCenterX(), mTypeSKillTimer[WIND]->GetCenterY());
	mTypeSKillTimer[WIND]->SetPosition(width / 2.f - 35, height / 2.f + 250);
	mTypeSKillTimer[WIND]->SetRGBA(255, 255, 255, 255);

	mTypeSKillTimer[EARTH] = NNLabel::Create(L"", L"¸¼Àº °íµñ", 40.f);
	mTypeSKillTimer[EARTH]->SetCenter(mTypeSKillTimer[EARTH]->GetCenterX(), mTypeSKillTimer[EARTH]->GetCenterY());
	mTypeSKillTimer[EARTH]->SetPosition(width / 2.f - 35, height / 2.f + 250);
	mTypeSKillTimer[EARTH]->SetRGBA(255, 255, 255, 255);*/

	//UserSKill icon cooltime count label
	mUserSkillTimer = NNLabel::Create(L"", L"¸¼Àº °íµñ", 40.f);
	mUserSkillTimer->SetCenter(mUserSkillTimer->GetCenterX(), mUserSkillTimer->GetCenterY());
	mUserSkillTimer->SetPosition(width / 2.f + 35, height / 2.f + 250);
	mUserSkillTimer->SetRGBA(255, 255, 255, 255);

	//KillPoint count label
	mKillPoint[BLUE] = NNLabel::Create(L"40", L"¸¼Àº °íµñ", 20.f);
	mKillPoint[BLUE]->SetCenter(mKillPoint[BLUE]->GetCenterX(), mKillPoint[BLUE]->GetCenterY());
	mKillPoint[BLUE]->SetPosition(width / 2.f - 270, 20);
	mKillPoint[BLUE]->SetRGBA(0, 0, 0, 255);

	mKillPoint[RED] = NNLabel::Create(L"25", L"¸¼Àº °íµñ", 20.f);
	mKillPoint[RED]->SetCenter(mKillPoint[RED]->GetCenterX(), mKillPoint[RED]->GetCenterY());
	mKillPoint[RED]->SetPosition(width / 2.f + 250, 20);
	mKillPoint[RED]->SetRGBA(0, 0, 0, 255);

	//Character Face Sprite
	mTypeFace[ZERO] = NNSprite::Create(L"Resource/Sprite/CharacterFace/ZeroSlime.png");
	mTypeFace[ZERO]->SetPosition(5.f, 505.f);

	mTypeFace[FIRE] = NNSprite::Create(L"Resource/Sprite/CharacterFace/EarthSlime.png");
	mTypeFace[FIRE]->SetPosition(5.f, 505.f);

	mTypeFace[WATER] = NNSprite::Create(L"Resource/Sprite/CharacterFace/BlueSlime.png");
	mTypeFace[WATER]->SetPosition(5.f, 505.f);

	mTypeFace[WIND] = NNSprite::Create(L"Resource/Sprite/CharacterFace/MetalSlime.png");
	mTypeFace[WIND]->SetPosition(5.f, 505.f);

	mTypeFace[EARTH] = NNSprite::Create(L"Resource/Sprite/CharacterFace/EarthSlime.png");
	mTypeFace[EARTH]->SetPosition(5.f, 505.f);

	//mRedKillPointNumber->SetScaleX(-1.f);

	AddChild(mCharacterUIFrame);
	AddChild(mSkillUIFrame);
	AddChild(mHpBarBackground);
	AddChild(mHpBar);
	AddChild(mKillBar[RED]);
	AddChild(mKillBar[BLUE]);
	AddChild(mCrown);
	AddChild(mUserSkillTimer);
	AddChild(mKillPoint[RED]);
	AddChild(mKillPoint[BLUE]);
	AddChild(mUserSkillUI);
	AddChild(mTypeSKillTimer);
	
	for (int i = 0; i <= EARTH; ++i)
	{
		AddChild(mTypeSkillUI[i]);
		AddChild(mTypeFace[i]);
	}
	
	mType = NNLabel::Create(L"asdf", L"¸¼Àº °íµñ", 50.f);
	mType->SetPosition(0.f, 450.f); 
	AddChild(mType);
	 		
	mMyPlayer = CPlayerManager::GetInstance()->GetMyPlayer();
	ZeroMemory( mFPSLabelBuff, sizeof(mFPSLabelBuff) );
}

GameUISet::~GameUISet()
{
}

void GameUISet::Init()
{
	mTypeFace[ZERO]->SetVisible(false);
	mTypeFace[FIRE]->SetVisible(false);
	mTypeFace[WATER]->SetVisible(false);
	mTypeFace[WIND]->SetVisible(false);
	mTypeFace[EARTH]->SetVisible(false);
}

void GameUISet::Render()
{
	NNUISet::Render();
}

void GameUISet::Update(float dTime)
{
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	for (int i = 0; i <= EARTH; ++i)
	{
		mTypeFace[i]->SetVisible(false);
		mTypeSkillUI[i]->SetVisible(false);
	}
 	
 	switch (mMyPlayer->GetPlayerType())
 	{
	case PlayerType::TYPE_ZERO:
		mType->SetString(L"Zero");
		mTypeFace[ZERO]->SetVisible(true);
		mTypeSkillUI[ZERO]->SetVisible(true);
		break;
 	case PlayerType::TYPE_A:
 		mType->SetString(L"Fire");
		mTypeFace[FIRE]->SetVisible(true);
		mTypeSkillUI[FIRE]->SetVisible(true);
 		break;
 	case PlayerType::TYPE_B:
 		mType->SetString(L"Water");
 		mTypeFace[WATER]->SetVisible(true);
		mTypeSkillUI[WATER]->SetVisible(true);
 		break;
 	case PlayerType::TYPE_C:
 		mType->SetString(L"Wind");
 		mTypeFace[WIND]->SetVisible(true);
		mTypeSkillUI[WIND]->SetVisible(true);
	case PlayerType::TYPE_D:
		mType->SetString(L"Earth");
		mTypeFace[EARTH]->SetVisible(true);
		mTypeSkillUI[EARTH]->SetVisible(true);
 		break;
 	}

	swprintf_s(mFPSLabelBuff, L"%d", (int)NNApplication::GetInstance()->GetFPS());

	mFPSLabel->SetString(mFPSLabelBuff);
	mHpBar->SetScale(mMyPlayer->GetPlayerHP() / 50.f, 1.f);
	/*
	mKillBar[TeamColor::BLUE]->SetScale(CPlayerManager::GetInstance()->GetKillScore(TeamColor::BLUE) / 50.f, 1.f);
	mKillPoint[TeamColor::BLUE]->SetPosition(width / 2.f - 5 * (CPlayerManager::GetInstance()->GetKillScore(TeamColor::BLUE)) - 60, 20);
	mKillBar[TeamColor::RED]->SetScale(CPlayerManager::GetInstance()->GetKillScore(TeamColor::RED) / 50.f, 1.f);
	mKillPoint[TeamColor::RED]->SetPosition(width / 2.f + 5 * CPlayerManager::GetInstance()->GetKillScore(TeamColor::RED) + 40, 20);
	*/
	mKillBar[TeamColor::BLUE]->SetScale(-GameManager::GetInstance()->GetKillScore(TeamColor::BLUE) / 50.f, 1.f);
	mKillPoint[TeamColor::BLUE]->SetPosition(width / 2.f - 5 * (GameManager::GetInstance()->GetKillScore(TeamColor::RED)) - 60, 20);
	mKillBar[TeamColor::RED]->SetScale(GameManager::GetInstance()->GetKillScore(TeamColor::RED) / 50.f, 1.f);
	mKillPoint[TeamColor::RED]->SetPosition(width / 2.f + 5 * GameManager::GetInstance()->GetKillScore(TeamColor::RED) + 40, 20);

	for (int i = 0; i < SKILL_COUNT; ++i)
		ControlSkillUI((PlayerState)(TYPE_ACTIVE_SKILL + i), dTime);
}

void GameUISet::ControlSkillUI(PlayerState skillType, float dTime)
{
	/*if (mMyPlayer->GetSkillCooldown(skillType) == true)
	{
		mMyPlayer->SetSkillCount(mMyPlayer->GetSkillCount(skillType) + dTime, skillType);
		mTypeSkillUI[skillType - TYPE_ACTIVE_SKILL]->SetOpacity(mMyPlayer->GetSkillCount(skillType) / mSkillCooltime[skillType - TYPE_ACTIVE_SKILL]);

		swprintf_s(mSkillCooltimeBuff[skillType - TYPE_ACTIVE_SKILL], L"%.0f", mSkillCooltime[skillType - TYPE_ACTIVE_SKILL] - mMyPlayer->GetSkillCount(skillType));
		mTypeSKillTimer[skillType - TYPE_ACTIVE_SKILL]->SetString(mSkillCooltimeBuff[skillType - TYPE_ACTIVE_SKILL]);

		if (mMyPlayer->GetSkillCount(skillType) >= mSkillCooltime[skillType - TYPE_ACTIVE_SKILL])
		{
			mMyPlayer->SetSkillCooldown(false, skillType);
			mMyPlayer->SetSkillCount(0.f, skillType);

			mTypeSkillUI[skillType - TYPE_ACTIVE_SKILL]->SetOpacity(1.f);
			mTypeSKillTimer[skillType - TYPE_ACTIVE_SKILL]->SetString(L"");
		}
	}*/
}
