
#include "GameUISet.h"
#include "GameManager.h"

#include "NNApplication.h"

GameUISet* GameUISet::mInstance = nullptr;

GameUISet* GameUISet::GetInstance()
{
	if (mInstance == nullptr)
		mInstance = new GameUISet();
	return mInstance;
}
void GameUISet::ReleaseInstance()
{
	if (mInstance != nullptr)
		delete mInstance;
}
GameUISet::GameUISet()
{
	mSkillCooltime[0] = 5.0f;
	mSkillCooltime[1] = 7.0f;
	mSkillCooltime[2] = 3.0f;
	mSkillCooltime[3] = 5.0f;

	ZeroMemory(mNowSkillCooltime, sizeof(mNowSkillCooltime));
	//mKillCount = 25;
	//mRedKillCount = 40;
	//mHp = 80;

	swprintf_s(mSkillCooltimeBuff[0], L"%d", (int)mSkillCooltime[0]);
	swprintf_s(mSkillCooltimeBuff[1], L"%d", (int)mSkillCooltime[1]);

	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	mFPSLabel = NNLabel::Create(L"", L"¸¼Àº °íµñ", 20);
	AddChild(mFPSLabel);

	mCharacterUIFrame = NNSprite::Create(L"Resource/Sprite/UI/GameUI/CharacterUIFrame.png");
	mCharacterUIFrame->SetPosition(0.f, 500.f);
	mCharacterUIFrame->SetOpacity(0.9f);

	mSkillUIFrame = NNSprite::Create(L"Resource/Sprite/UI/Skill/SkillUIFrame.png");
	mSkillUIFrame->SetCenter(mSkillUIFrame->GetImageWidth() / 2.f, mSkillUIFrame->GetImageHeight() / 2.f);
	mSkillUIFrame->SetPosition(width / 2.f, height / 2.f + 250);
	mSkillUIFrame->SetOpacity(0.9f);

	mHpBarBackground = NNSprite::Create(L"Resource/Sprite/UI/GameUI/GameHpBar_BackGround.png");
	mHpBarBackground->SetCenter(mHpBarBackground->GetImageWidth() / 2.f, mHpBarBackground->GetImageHeight() / 2.f);
	mHpBarBackground->SetPosition(width / 2.f, height / 2.f + 280);

	mHpBar = NNSprite::Create(L"Resource/Sprite/UI/GameUI/GameHpBar.png");
	mHpBar->SetPosition(340.f, 570.f);

	mCrown = NNSprite::Create(L"Resource/Sprite/Object/Crown.png");
	mCrown->SetCenter(mCrown->GetImageWidth() / 2.f, mCrown->GetImageHeight() / 2.f);
	mCrown->SetPosition(width / 2.f, 30);

	mKillBar[BLUE] = NNSprite::Create(L"Resource/Sprite/UI/GameUI/KillPointBlueBar.png");
	mKillBar[BLUE]->SetPosition(width / 2.f - 32, 20);
	mKillBar[BLUE]->SetScaleX(-1.f);

	mKillBar[RED] = NNSprite::Create(L"Resource/Sprite/UI/GameUI/KillPointRedBar.png");
	mKillBar[RED]->SetPosition(width / 2.f + 32, 20);
	//mRedKillBar->SetScaleX(-1.f);

	mTypeSkillUI[ZERO] = NNSprite::Create(L"Resource/Sprite/UI/Skill/TypeSkill/ZeroTypeSkillUI.png");
	mTypeSkillUI[ZERO]->SetCenter(mTypeSkillUI[ZERO]->GetImageWidth() / 2.f, mTypeSkillUI[ZERO]->GetImageHeight() / 2.f);
	mTypeSkillUI[ZERO]->SetPosition(width / 2.f - 32, height / 2.f + 235);

	mTypeSkillUI[FIRE] = NNSprite::Create(L"Resource/Sprite/UI/Skill/TypeSkill/FireTypeSkillUI.png");
	mTypeSkillUI[FIRE]->SetCenter(mTypeSkillUI[FIRE]->GetImageWidth() / 2.f, mTypeSkillUI[FIRE]->GetImageHeight() / 2.f);
	mTypeSkillUI[FIRE]->SetPosition(width / 2.f - 32, height / 2.f + 235);

	mTypeSkillUI[WATER] = NNSprite::Create(L"Resource/Sprite/UI/Skill/TypeSkill/WaterTypeSkillUI.png");
	mTypeSkillUI[WATER]->SetCenter(mTypeSkillUI[WATER]->GetImageWidth() / 2.f, mTypeSkillUI[WATER]->GetImageHeight() / 2.f);
	mTypeSkillUI[WATER]->SetPosition(width / 2.f - 32, height / 2.f + 235);

	mTypeSkillUI[WIND] = NNSprite::Create(L"Resource/Sprite/UI/Skill/TypeSkill/WindTypeSkillUI.png");
	mTypeSkillUI[WIND]->SetCenter(mTypeSkillUI[WIND]->GetImageWidth() / 2.f, mTypeSkillUI[WIND]->GetImageHeight() / 2.f);
	mTypeSkillUI[WIND]->SetPosition(width / 2.f - 32, height / 2.f + 235);

	mTypeSkillUI[EARTH] = NNSprite::Create(L"Resource/Sprite/UI/Skill/TypeSkill/EarthTypeSkillUI.png");
	mTypeSkillUI[EARTH]->SetCenter(mTypeSkillUI[EARTH]->GetImageWidth() / 2.f, mTypeSkillUI[EARTH]->GetImageHeight() / 2.f);
	mTypeSkillUI[EARTH]->SetPosition(width / 2.f - 32, height / 2.f + 235);

	mUserSkillUI = NNSprite::Create(L"Resource/Sprite/UI/Skill/UserSkill/Dash.png");
	mUserSkillUI->SetCenter(mUserSkillUI->GetImageWidth() / 2.f, mUserSkillUI->GetImageHeight() / 2.f);
	mUserSkillUI->SetPosition(width / 2.f + 32, height / 2.f + 235);

	/*mSkillUI[0] = NNSprite::Create(L"Resource/Sprite/TypeSkillUI.png");
	mSkillUI[0]->SetCenter(mSkillUI[0]->GetImageWidth() / 2.f, mSkillUI[0]->GetImageHeight() / 2.f);
	mSkillUI[0]->SetPosition(width / 2.f - 32, height / 2.f + 235);

	mSkillUI[1] = NNSprite::Create(L"Resource/Sprite/UserSkillUI.png");
	mSkillUI[1]->SetCenter(mSkillUI[1]->GetImageWidth() / 2.f, mSkillUI[1]->GetImageHeight() / 2.f);
	mSkillUI[1]->SetPosition(width / 2.f + 32, height / 2.f + 235);*/

	//TypeSKill icon cooltime count label
	mTypeSKillTimer = NNLabel::Create(L"", L"¸¼Àº °íµñ", 30.f);
	mTypeSKillTimer->SetCenter(mTypeSKillTimer->GetCenterX(), mTypeSKillTimer->GetCenterY());
	mTypeSKillTimer->SetPosition(width / 2.f - 45, height / 2.f + 225);
	//mTypeSKillTimer->SetRGBA(255, 255, 255, 255);
	mTypeSKillTimer->SetBold(true);
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
	mUserSkillTimer = NNLabel::Create(L"", L"¸¼Àº °íµñ", 30.f);
	mUserSkillTimer->SetCenter(mUserSkillTimer->GetCenterX(), mUserSkillTimer->GetCenterY());
	mUserSkillTimer->SetPosition(width / 2.f + 20, height / 2.f + 230);
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

	mStatusWindow = CStatusWindow::Create();
	mStatusWindow->SetVisible(false);
	mStatusWindow->SetPosition(100.f, 100.f);

	AddChild(mCharacterUIFrame);
	AddChild(mSkillUIFrame);
	AddChild(mHpBarBackground);
	AddChild(mHpBar);
	AddChild(mKillBar[RED]);
	AddChild(mKillBar[BLUE]);
	AddChild(mCrown);
	AddChild(mKillPoint[RED]);
	AddChild(mKillPoint[BLUE]);
	AddChild(mUserSkillUI);
	for (int i = 0; i <= EARTH; ++i)
	{
		AddChild(mTypeSkillUI[i]);
		AddChild(mTypeFace[i]);
	}
	AddChild(mTypeSKillTimer);
	AddChild(mUserSkillTimer);
	AddChild(mStatusWindow);
	
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
		if (mTypeFace[ZERO]->IsVisible() == true)
			break;

		mType->SetString(L"Zero");
		mTypeFace[ZERO]->SetVisible(true);
		mTypeSkillUI[ZERO]->SetVisible(true);
		break;
 	case PlayerType::TYPE_A:
		if (mTypeFace[FIRE]->IsVisible() == true)
			break;

 		mType->SetString(L"Fire");
		mTypeFace[FIRE]->SetVisible(true);
		mTypeSkillUI[FIRE]->SetVisible(true);
 		break;
 	case PlayerType::TYPE_B:
		if (mTypeFace[WATER]->IsVisible() == true)
			break;

 		mType->SetString(L"Water");
 		mTypeFace[WATER]->SetVisible(true);
		mTypeSkillUI[WATER]->SetVisible(true);
 		break;
 	case PlayerType::TYPE_C:
		if (mTypeFace[WIND]->IsVisible() == true)
			break;

 		mType->SetString(L"Wind");
 		mTypeFace[WIND]->SetVisible(true);
		mTypeSkillUI[WIND]->SetVisible(true);
		break;
	case PlayerType::TYPE_D:
		if (mTypeFace[EARTH]->IsVisible() == true)
			break;

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

	ControlSkillTimer(dTime);

// 	for (int i = 0; i < SKILL_COUNT; ++i)
// 		ControlSkillUI((PlayerState)(TYPE_ACTIVE_SKILL + i), dTime);

	if( NNInputSystem::GetInstance()->GetKeyState(VK_TAB) == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState(VK_TAB) == KEY_DOWN)
	{
		mStatusWindow->GetAllPlayerInfo();
		mStatusWindow->SetVisible(true);
	}
	else if ( NNInputSystem::GetInstance()->GetKeyState(VK_TAB) == KEY_NOTPRESSED )
	{
		mStatusWindow->SetVisible(false);
	}

}

void GameUISet::ControlSkillTimer(float dTime)
{
	int type = mMyPlayer->GetPlayerType() - 1;
	if (mIsCooldown[0] == true)
	{
		mNowSkillCooltime[0] += dTime;
		mTypeSkillUI[type +1]->SetOpacity(pow(mNowSkillCooltime[0] / mSkillCooltime[type],3));

		swprintf_s(mSkillCooltimeBuff[0], L"%.1f", mSkillCooltime[type] - mNowSkillCooltime[0]);
		mTypeSKillTimer->SetString(mSkillCooltimeBuff[0]);

		if (mNowSkillCooltime[0] >= mSkillCooltime[type])
		{
			mIsCooldown[0] = false;
			mNowSkillCooltime[0] = 0.f;

			mTypeSkillUI[type+1]->SetOpacity(1.f);
			mTypeSKillTimer->SetString(L"");
		}
	}
// 	mMyPlayer->SetSkillCount(mMyPlayer->GetSkillCount(type) + dTime, type);
// 	mTypeSkillUI[type]->SetOpacity(mMyPlayer->GetSkillCount(type) / mSkillCooltime[type]);
// 
// 	swprintf_s(mSkillCooltimeBuff[type], L"%.0f", mSkillCooltime[type] - mMyPlayer->GetSkillCount(type));
// 	mTypeSKillTimer[type].SetString(mSkillCooltimeBuff[type]);
// 
// 	if (mMyPlayer->GetSkillCount(type) >= mSkillCooltime[type])
// 	{
// 		mMyPlayer->SetSkillCooldown(false, type);
// 		mMyPlayer->SetSkillCount(0.f, type);
// 
// 		mTypeSkillUI[type]->SetOpacity(1.f);
// 		mTypeSKillTimer[type].SetString(L"");
// 	}
}


CStatusWindow::CStatusWindow()
{
}
void CStatusWindow::Init()
{
	mPanel = NNSprite::Create(L"Resource/Sprite/UI/GameUI/Panel.png");
	mPanel->SetOpacity(0.5f);

	NNLabel *PanelName = NNLabel::Create(L"Score", L"¸¼Àº °íµñ", 40.f);
	PanelName->SetColor(255, 255, 255);

	NNLabel *RedID = NNLabel::Create(L"ID", L"¸¼Àº °íµñ", 30.f);
	RedID->SetColor(255, 255, 255);
	RedID->SetPosition(20.f, 60.f);
	NNLabel *RedKillScore = NNLabel::Create(L"KILL", L"¸¼Àº °íµñ", 30.f);
	RedKillScore->SetColor(255, 255, 255);
	RedKillScore->SetPosition(150.f, 60.f);

	NNLabel *BlueID = NNLabel::Create(L"ID", L"¸¼Àº °íµñ", 30.f);
	BlueID->SetColor(255, 255, 255);
	BlueID->SetPosition(320.f, 60.f);
	NNLabel *BlueKillScore = NNLabel::Create(L"KILL", L"¸¼Àº °íµñ", 30.f);
	BlueKillScore->SetColor(255, 255, 255);
	BlueKillScore->SetPosition(450.f, 60.f);


	for (int i = 0; i < MAX_PLAYER_LEN; ++i)
	{
		wsprintf(mLabelBuf[i], L"Player%d", i);

		mPlayerLabelList[i] = NNLabel::Create(mLabelBuf[i], L"¸¼Àº °íµñ", 20.f);
		mPlayerKillScoreList[i] = NNLabel::Create(L"0", L"¸¼Àº °íµñ", 20.f);
		mPlayerLabelList[i]->SetColor(255, 255, 255);
		mPlayerKillScoreList[i]->SetColor(255, 255, 255);

		mPlayerLabelList[i]->SetVisible(false);
		mPlayerKillScoreList[i]->SetVisible(false);
		AddChild(mPlayerLabelList[i], 2);
		AddChild(mPlayerKillScoreList[i], 2);
	}

	AddChild(PanelName, 2);
	AddChild(mPanel);
	AddChild(RedID);
	AddChild(RedKillScore);
	AddChild(BlueID);
	AddChild(BlueKillScore);

	//GetAllPlayerInfo();
}
CStatusWindow::~CStatusWindow()
{
}
void CStatusWindow::Render()
{
	NNObject::Render();
}

void CStatusWindow::Update(float dTime)
{
	NNObject::Update(dTime);
	//GetAllPlayerInfo();
}

void CStatusWindow::GetAllPlayerInfo()
{
	CPlayerManager *playerManager = CPlayerManager::GetInstance();

	std::map<int, CPlayer*> playerList = playerManager->GetPlayerList();
	float aY, bY;
	aY = bY = 90.f;

	for (int i = 0; i < MAX_PLAYER_LEN; ++i)
	{
		mPlayerLabelList[i]->SetVisible(false);
		mPlayerKillScoreList[i]->SetVisible(false);
	}

	for (auto &iter : playerList)
	{
		mPlayerLabelList[iter.first]->SetVisible(true);
		mPlayerKillScoreList[iter.first]->SetVisible(true);
		wsprintf(mKillScoreBuf[iter.first], L"%d", iter.second->GetKillScore());
		mPlayerKillScoreList[iter.first]->SetString(mKillScoreBuf[iter.first]);

		if (iter.second->GetTeam() == TeamColor::RED)
		{
			mPlayerLabelList[iter.first]->SetPosition(5, aY);
			mPlayerKillScoreList[iter.first]->SetPosition(165, aY);
			aY += 30.f;
		}
		else if (iter.second->GetTeam() == TeamColor::BLUE)
		{
			mPlayerLabelList[iter.first]->SetPosition(305, bY);
			mPlayerKillScoreList[iter.first]->SetPosition(465, bY);
			bY += 30.f;
		}
	}
}
