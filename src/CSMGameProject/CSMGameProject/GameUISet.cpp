
#include "GameUISet.h"
#include "GameManager.h"
#include "GameScene.h"
#include "NNApplication.h"

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
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
	mSkillCooltime[3] = 3.0f;
	mSkillCooltime[4] = 10.f;

	ZeroMemory(mNowSkillCooltime, sizeof(mNowSkillCooltime));
	//mKillCount = 25;
	//mRedKillCount = 40;
	//mHp = 80;

	swprintf_s(mSkillCooltimeBuff[0], L"%d", (int)mSkillCooltime[0]);
	swprintf_s(mSkillCooltimeBuff[1], L"%d", (int)mSkillCooltime[1]);

	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	//mFPSLabel = NNLabel::Create(L"", L"¸¼Àº °íµñ", 20);
	//AddChild(mFPSLabel);

	mCharacterUIFrame = NNSprite::Create(L"Resource/Sprite/UI/GameUI/CharacterUIFrame.png");
	mCharacterUIFrame->SetPosition(0.f, 520.f);
	mCharacterUIFrame->SetOpacity(0.9f);

	mSkillUIFrame = NNSprite::Create(L"Resource/Sprite/UI/Skill/SkillUIFrame.png");
	mSkillUIFrame->SetCenter(mSkillUIFrame->GetImageWidth() / 2.f, mSkillUIFrame->GetImageHeight() / 2.f);
	mSkillUIFrame->SetPosition(width / 2.f, height / 2.f + 270);
	mSkillUIFrame->SetOpacity(0.9f);

	/*mHpBarBackground = NNSprite::Create(L"Resource/Sprite/UI/GameUI/GameHpBar_BackGround.png");
	mHpBarBackground->SetCenter(mHpBarBackground->GetImageWidth() / 2.f, mHpBarBackground->GetImageHeight() / 2.f);
	mHpBarBackground->SetPosition(width / 2.f, height / 2.f + 280);*/

	/*mHpBar = NNSprite::Create(L"Resource/Sprite/UI/GameUI/GameHpBar.png");
	mHpBar->SetPosition(340.f, 570.f);*/


	//mRedKillBar->SetSc	aleX(-1.f);

	mTypeSkillUI[ZERO] = NNSprite::Create(L"Resource/Sprite/UI/Skill/TypeSkill/ZeroTypeSkillUI.png");
	mTypeSkillUI[ZERO]->SetCenter(mTypeSkillUI[ZERO]->GetImageWidth() / 2.f, mTypeSkillUI[ZERO]->GetImageHeight() / 2.f);
	mTypeSkillUI[ZERO]->SetPosition(width / 2.f - 30, height / 2.f + 270);
	mTypeSkillUI[ZERO]->SetScale(0.91f, 0.86f);

	mTypeSkillUI[FIRE] = NNSprite::Create(L"Resource/Sprite/UI/Skill/TypeSkill/FireTypeSkillUI.png");
	mTypeSkillUI[FIRE]->SetCenter(mTypeSkillUI[FIRE]->GetImageWidth() / 2.f, mTypeSkillUI[FIRE]->GetImageHeight() / 2.f);
	mTypeSkillUI[FIRE]->SetPosition(width / 2.f - 30, height / 2.f + 270);
	mTypeSkillUI[FIRE]->SetScale(0.91f, 0.86f);

	mTypeSkillUI[WATER] = NNSprite::Create(L"Resource/Sprite/UI/Skill/TypeSkill/WaterTypeSkillUI.png");
	mTypeSkillUI[WATER]->SetCenter(mTypeSkillUI[WATER]->GetImageWidth() / 2.f, mTypeSkillUI[WATER]->GetImageHeight() / 2.f);
	mTypeSkillUI[WATER]->SetPosition(width / 2.f - 30, height / 2.f + 270);
	mTypeSkillUI[WATER]->SetScale(0.91f, 0.86f);

	mTypeSkillUI[WIND] = NNSprite::Create(L"Resource/Sprite/UI/Skill/TypeSkill/WindTypeSkillUI.png");
	mTypeSkillUI[WIND]->SetCenter(mTypeSkillUI[WIND]->GetImageWidth() / 2.f, mTypeSkillUI[WIND]->GetImageHeight() / 2.f);
	mTypeSkillUI[WIND]->SetPosition(width / 2.f - 30, height / 2.f + 270);
	mTypeSkillUI[WIND]->SetScale(0.91f, 0.86f);

	mTypeSkillUI[EARTH] = NNSprite::Create(L"Resource/Sprite/UI/Skill/TypeSkill/EarthTypeSkillUI.png");
	mTypeSkillUI[EARTH]->SetCenter(mTypeSkillUI[EARTH]->GetImageWidth() / 2.f, mTypeSkillUI[EARTH]->GetImageHeight() / 2.f);
	mTypeSkillUI[EARTH]->SetPosition(width / 2.f - 30, height / 2.f + 270);
	mTypeSkillUI[EARTH]->SetScale(0.91f, 0.86f);

	mUserSkillUI = NNSprite::Create(L"Resource/Sprite/UI/Skill/UserSkill/Dash.png");
	mUserSkillUI->SetCenter(mUserSkillUI->GetImageWidth() / 2.f, mUserSkillUI->GetImageHeight() / 2.f);
	mUserSkillUI->SetPosition(width / 2.f + 30, height / 2.f + 270);
	mUserSkillUI->SetScale(0.92f, 0.88f);

	/*mSkillUI[0] = NNSprite::Create(L"Resource/Sprite/TypeSkillUI.png");
	mSkillUI[0]->SetCenter(mSkillUI[0]->GetImageWidth() / 2.f, mSkillUI[0]->GetImageHeight() / 2.f);
	mSkillUI[0]->SetPosition(width / 2.f - 32, height / 2.f + 235);

	mSkillUI[1] = NNSprite::Create(L"Resource/Sprite/UserSkillUI.png");
	mSkillUI[1]->SetCenter(mSkillUI[1]->GetImageWidth() / 2.f, mSkillUI[1]->GetImageHeight() / 2.f);
	mSkillUI[1]->SetPosition(width / 2.f + 32, height / 2.f + 235);*/

	//TypeSKill icon cooltime count label
	mTypeSKillTimer = NNLabel::Create(L"", L"¸¼Àº °íµñ", 30.f);
	mTypeSKillTimer->SetCenter(mTypeSKillTimer->GetCenterX(), mTypeSKillTimer->GetCenterY());
	mTypeSKillTimer->SetPosition(width / 2.f - 50, height / 2.f + 250);
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
	mUserSkillTimer->SetPosition(width / 2.f + 10, height / 2.f + 250);
	mUserSkillTimer->SetBold(true);
	mUserSkillTimer->SetRGBA(255, 255, 255, 255);

	//KillPoint count label
	mKillPoint[BLUE] = NNLabel::Create(L"", L"¸¼Àº °íµñ", 20.f);
	mKillPoint[BLUE]->SetCenter(mKillPoint[BLUE]->GetCenterX(), mKillPoint[BLUE]->GetCenterY());
	mKillPoint[BLUE]->SetPosition(width / 2.f - 270, 20);
	mKillPoint[BLUE]->SetRGBA(0, 0, 0, 255);

	mKillPoint[RED] = NNLabel::Create(L"", L"¸¼Àº °íµñ", 20.f);
	mKillPoint[RED]->SetCenter(mKillPoint[RED]->GetCenterX(), mKillPoint[RED]->GetCenterY());
	mKillPoint[RED]->SetPosition(width / 2.f + 250, 20);
	mKillPoint[RED]->SetRGBA(0, 0, 0, 255);

	//Character Face Sprite
	mTypeFace[ZERO] = NNSprite::Create(L"Resource/Sprite/CharacterFace/ZeroSlime.png");
	mTypeFace[ZERO]->SetPosition(10.f, 535.f);

	mTypeFace[FIRE] = NNSprite::Create(L"Resource/Sprite/CharacterFace/EarthSlime.png");
	mTypeFace[FIRE]->SetPosition(10.f, 535.f);

	mTypeFace[WATER] = NNSprite::Create(L"Resource/Sprite/CharacterFace/BlueSlime.png");
	mTypeFace[WATER]->SetPosition(10.f, 535.f);

	mTypeFace[WIND] = NNSprite::Create(L"Resource/Sprite/CharacterFace/MetalSlime.png");
	mTypeFace[WIND]->SetPosition(10.f, 535.f);

	mTypeFace[EARTH] = NNSprite::Create(L"Resource/Sprite/CharacterFace/EarthSlime.png");
	mTypeFace[EARTH]->SetPosition(10.f, 535.f);
	//mRedKillPointNumber->SetScaleX(-1.f);

	mStatusWindow = CStatusWindow::Create();
	mStatusWindow->SetVisible(false);
	mStatusWindow->SetPosition(150.f, 100.f);

	mHelp = NNSprite::Create(L"Resource/Sprite/UI/GameUI/Help.png");
	mHelp->SetOpacity(0.75f);

	mHelpPanel = NNSprite::Create(L"Resource/Sprite/UI/Loading/intro.png");
	mHelpPanel->SetVisible(false);

	AddChild(mHelp);
	AddChild(mHelpPanel);

	AddChild(mCharacterUIFrame);
	AddChild(mSkillUIFrame);
	/*AddChild(mHpBarBackground);
	AddChild(mHpBar);
	*/
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

	/*mType = NNLabel::Create(L"asdf", L"¸¼Àº °íµñ", 50.f);
	mType->SetPosition(0.f, 450.f);
	AddChild(mType);*/

	mMyPlayer = CPlayerManager::GetInstance()->GetMyPlayer();
	//ZeroMemory(mFPSLabelBuff, sizeof(mFPSLabelBuff));
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

		//mType->SetString(L"Zero");
		mTypeFace[ZERO]->SetVisible(true);
		mTypeSkillUI[ZERO]->SetVisible(true);
		break;
	case PlayerType::TYPE_A:
		if (mTypeFace[FIRE]->IsVisible() == true)
			break;

		//mType->SetString(L"Fire");
		mTypeFace[FIRE]->SetVisible(true);
		mTypeSkillUI[FIRE]->SetVisible(true);
		break;
	case PlayerType::TYPE_B:
		if (mTypeFace[WATER]->IsVisible() == true)
			break;

		//mType->SetString(L"Water");
		mTypeFace[WATER]->SetVisible(true);
		mTypeSkillUI[WATER]->SetVisible(true);
		break;
	case PlayerType::TYPE_C:
		if (mTypeFace[WIND]->IsVisible() == true)
			break;

		//mType->SetString(L"Wind");
		mTypeFace[WIND]->SetVisible(true);
		mTypeSkillUI[WIND]->SetVisible(true);
		break;
	case PlayerType::TYPE_D:
		if (mTypeFace[EARTH]->IsVisible() == true)
			break;

		//mType->SetString(L"Earth");
		mTypeFace[EARTH]->SetVisible(true);
		mTypeSkillUI[EARTH]->SetVisible(true);
		break;
	}

	//swprintf_s(mFPSLabelBuff, L"%d", (int)NNApplication::GetInstance()->GetFPS());

	//mFPSLabel->SetString(mFPSLabelBuff);
	//	mHpBar->SetScale(mMyPlayer->GetPlayerHP() / 50.f, 1.f);
	/*
	mKillBar[TeamColor::BLUE]->SetScale(CPlayerManager::GetInstance()->GetKillScore(TeamColor::BLUE) / 50.f, 1.f);
	mKillPoint[TeamColor::BLUE]->SetPosition(width / 2.f - 5 * (CPlayerManager::GetInstance()->GetKillScore(TeamColor::BLUE)) - 60, 20);
	mKillBar[TeamColor::RED]->SetScale(CPlayerManager::GetInstance()->GetKillScore(TeamColor::RED) / 50.f, 1.f);
	mKillPoint[TeamColor::RED]->SetPosition(width / 2.f + 5 * CPlayerManager::GetInstance()->GetKillScore(TeamColor::RED) + 40, 20);
	*/

	/*
	//int t = GameManager::GetInstance()->GetKillScore(TeamColor::RED);
	mKillBar[TeamColor::RED]->SetScale(-GameManager::GetInstance()->GetKillScore(TeamColor::RED) / 50.f, 1.f);
	mKillPoint[TeamColor::RED]->SetPosition(width / 2.f + 5 * GameManager::GetInstance()->GetKillScore(TeamColor::RED) + 40, 20);
	swprintf_s(mKillBuf[TeamColor::RED], L"%d", GameManager::GetInstance()->GetKillScore(TeamColor::BLUE));
	mKillPoint[RED]->SetString(mKillBuf[TeamColor::RED]);

	//t = GameManager::GetInstance()->GetKillScore(TeamColor::BLUE);
	mKillBar[TeamColor::BLUE]->SetScale(GameManager::GetInstance()->GetKillScore(TeamColor::BLUE) / 50.f, 1.f);
	mKillPoint[TeamColor::BLUE]->SetPosition(width / 2.f - 5 * (GameManager::GetInstance()->GetKillScore(TeamColor::BLUE)) - 60, 20);
	swprintf_s(mKillBuf[TeamColor::BLUE], L"%d", GameManager::GetInstance()->GetKillScore(TeamColor::RED));
	mKillPoint[BLUE]->SetString(mKillBuf[TeamColor::BLUE]);
	*/

	/*
	mKillBar[TeamColor::RED]->SetScale(-GameManager::GetInstance()->GetKillScore(TeamColor::RED) / 50.f, 1.f);
	mKillPoint[TeamColor::RED]->SetPosition(width / 2.f - 5 * (GameManager::GetInstance()->GetKillScore(TeamColor::RED)) + 40, 20);
	swprintf_s(mKillBuf[TeamColor::RED], L"%d", GameManager::GetInstance()->GetKillScore(TeamColor::RED));
	mKillPoint[RED]->SetString(mKillBuf[TeamColor::RED]);

	mKillBar[TeamColor::BLUE]->SetScale(GameManager::GetInstance()->GetKillScore(TeamColor::BLUE) / 50.f, 1.f);
	mKillPoint[TeamColor::BLUE]->SetPosition(width / 2.f + 5 * GameManager::GetInstance()->GetKillScore(TeamColor::BLUE) - 60, 20);
	swprintf_s(mKillBuf[TeamColor::BLUE], L"%d", GameManager::GetInstance()->GetKillScore(TeamColor::BLUE));
	mKillPoint[BLUE]->SetString(mKillBuf[TeamColor::BLUE]);
	*/

	ControlSkillTimer(dTime);

	// 	for (int i = 0; i < SKILL_COUNT; ++i)
	// 		ControlSkillUI((PlayerState)(TYPE_ACTIVE_SKILL + i), dTime);

	if (dynamic_cast<CGameScene*>(NNSceneDirector::GetInstance()->GetNowScene())->IsEnd() == true)
		return;

	if (NNInputSystem::GetInstance()->GetKeyState(VK_TAB) == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState(VK_TAB) == KEY_DOWN)
	{
		mStatusWindow->GetAllPlayerInfo();
		mStatusWindow->SetVisible(true);
	}
	else if (NNInputSystem::GetInstance()->GetKeyState(VK_TAB) == KEY_NOTPRESSED)
	{
		mStatusWindow->SetVisible(false);
	}

	if (NNInputSystem::GetInstance()->GetKeyState(VK_F1) == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState(VK_F1) == KEY_DOWN)
	{
		mHelpPanel->SetVisible(true);
	}
	else if (NNInputSystem::GetInstance()->GetKeyState(VK_F1) == KEY_NOTPRESSED)
	{
		mHelpPanel->SetVisible(false);
	}
}

void GameUISet::ControlSkillTimer(float dTime)
{
	int type = mMyPlayer->GetPlayerType() - 1;
	if (mIsCooldown[0] == true)
	{
		mNowSkillCooltime[0] += dTime;
		mTypeSkillUI[type + 1]->SetOpacity(pow(mNowSkillCooltime[0] / mSkillCooltime[type], 3));

		swprintf_s(mSkillCooltimeBuff[0], L"%.1f", mSkillCooltime[type] - mNowSkillCooltime[0]);
		mTypeSKillTimer->SetString(mSkillCooltimeBuff[0]);

		if (mNowSkillCooltime[0] >= mSkillCooltime[type])
		{
			mIsCooldown[0] = false;
			mNowSkillCooltime[0] = 0.f;

			mTypeSkillUI[type + 1]->SetOpacity(1.f);
			mTypeSKillTimer->SetString(L"");
		}
	}
	if (mIsCooldown[1] == true)
	{
		mNowSkillCooltime[1] += dTime;
		mUserSkillUI->SetOpacity(pow(mNowSkillCooltime[1] / mSkillCooltime[4], 3));

		swprintf_s(mSkillCooltimeBuff[1], L"%.1f", mSkillCooltime[4] - mNowSkillCooltime[1]);
		mUserSkillTimer->SetString(mSkillCooltimeBuff[1]);

		if (mNowSkillCooltime[1] >= mSkillCooltime[4])
		{
			mIsCooldown[1] = false;
			mNowSkillCooltime[1] = 0.f;

			mUserSkillUI->SetOpacity(1.f);
			mUserSkillTimer->SetString(L"");
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

	AddChild(mPanel);

	ZeroMemory(mTeamKillScoreBuf, sizeof(mTeamKillScoreBuf));

	for (int i = 0; i < 3; ++i)
	{
		mTeamKillScore[i] = NNLabel::Create(mTeamKillScoreBuf[i], L"¸¼Àº °íµñ", 20.f);
		mTeamKillScore[i]->SetBold(true);
		mTeamKillScore[i]->SetColor(255, 255, 255);

		AddChild(mTeamKillScore[i]);
	}
	wsprintf(mTeamKillScoreBuf[0], L"%d", GameManager::GetInstance()->GetKillScore(RED));
	wsprintf(mTeamKillScoreBuf[1], L"%d", GameManager::GetInstance()->GetKillScore(BLUE));
	wsprintf(mTeamKillScoreBuf[2], L"%d", GameManager::GetInstance()->GetKillLimit());

	mTeamKillScore[0]->SetPosition(140.f, 35.f);
	mTeamKillScore[1]->SetPosition(370.f, 35.f);
	mTeamKillScore[2]->SetPosition(250.f, 5.f);

	for (int i = 0; i < MAX_PLAYER_LEN; ++i)
	{
		//wsprintf(mLabelBuf[i], L"Player%d", i);

		mElement[i].mNicknameLabel = NNLabel::Create(mElement[i].mNicknameBuf, L"¸¼Àº °íµñ", 15.f);
		mElement[i].mKillLabel = NNLabel::Create(mElement[i].mKillBuf, L"¸¼Àº °íµñ", 15.f);

		mElement[i].mNicknameLabel->SetColor(255, 255, 255);
		mElement[i].mKillLabel->SetColor(255, 255, 255);

		mElement[i].mNicknameLabel->SetVisible(false);
		mElement[i].mKillLabel->SetVisible(false);

		AddChild(mElement[i].mNicknameLabel, 2);
		AddChild(mElement[i].mKillLabel, 2);
// 		mPlayerLabelList[i] = NNLabel::Create(mLabelBuf[i], L"¸¼Àº °íµñ", 15.f);
// 		mPlayerKillScoreList[i] = NNLabel::Create(L"0", L"¸¼Àº °íµñ", 15.f);
// 
// 		mPlayerLabelList[i]->SetColor(255, 255, 255);
// 		mPlayerKillScoreList[i]->SetColor(255, 255, 255);
// 
// 		mPlayerLabelList[i]->SetVisible(false);
// 		mPlayerKillScoreList[i]->SetVisible(false);
// 		AddChild(mPlayerLabelList[i], 2);
// 		AddChild(mPlayerKillScoreList[i], 2);
	}

	

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
	GetAllPlayerInfo();
	wsprintf(mTeamKillScoreBuf[0], L"%d", GameManager::GetInstance()->GetKillScore(RED));
	wsprintf(mTeamKillScoreBuf[1], L"%d", GameManager::GetInstance()->GetKillScore(BLUE));
}
void CStatusWindow::SortByKillScore(int *result)
{
	std::map<int, CPlayer*> playerList = CPlayerManager::GetInstance()->GetPlayerList();
	int kill[MAX_PLAYER_LEN] = { 0, };
	int n = 0;

	for (auto &iter : playerList)
	{
		result[n] = iter.first;
		kill[n++] = (iter.second)->GetKillScore();
	}
	for (int i = 0; i < n; ++i)
	{
		int MaxValue = kill[i];
		int idx = i;

		for (int j = i+1; j < n; ++j)
		{
			if (kill[j] > MaxValue)
			{
				idx = j;
				MaxValue = kill[j];
			}
		}
		swap(&result[i], &result[idx]);
		swap(&kill[i], &kill[idx]);
	}
}
void CStatusWindow::GetAllPlayerInfo()
{
	CPlayerManager *playerManager = CPlayerManager::GetInstance();

	std::map<int, CPlayer*> playerList = playerManager->GetPlayerList();
	int SortOrder[MAX_PLAYER_LEN] = { 0, };
	float aY, bY;
	aY = bY = 90.f;

	SortByKillScore(SortOrder);
	
	for (int i = 0; i < MAX_PLAYER_LEN; ++i)
	{
		mElement[i].mKillLabel->SetVisible(false);
		mElement[i].mKillLabel->SetColor(240, 240, 240);
		mElement[i].mNicknameLabel->SetVisible(false);
		mElement[i].mNicknameLabel->SetColor(240, 240, 240);
// 		mPlayerLabelList[i]->SetVisible(false);
// 		mPlayerKillScoreList[i]->SetVisible(false);
	}

	for (int i = 0; i < playerList.size(); ++i)
	{
		if (SortOrder[i] == CPlayerManager::GetInstance()->GetMyPlayerId())
		{
			mElement[i].mKillLabel->SetColor(240, 240, 0);
			mElement[i].mNicknameLabel->SetColor(240, 240, 0);
		}
			
		wsprintf(mElement[i].mNicknameBuf, L"%s", playerList[SortOrder[i]]->GetNickname());
		wsprintf(mElement[i].mKillBuf, L"%d", playerList[SortOrder[i]]->GetKillScore());
		mElement[i].mKillLabel->SetVisible(true);
		mElement[i].mNicknameLabel->SetVisible(true);

		switch (playerList[SortOrder[i]]->GetTeam())
		{
		case TeamColor::RED :
			mElement[i].mNicknameLabel->SetPosition(70, aY);
			mElement[i].mKillLabel->SetPosition(200, aY);
			aY += 20.f;
			break;

		case TeamColor::BLUE :
			mElement[i].mNicknameLabel->SetPosition(300, bY);
			mElement[i].mKillLabel->SetPosition(410, bY);
			bY += 20.f;
			break;
		}
	}
//	for (auto &iter : playerList)
//	{
// 		mPlayerLabelList[iter.first]->SetVisible(true);
// 		mPlayerKillScoreList[iter.first]->SetVisible(true);
// 		wsprintf(mKillScoreBuf[iter.first], L"%d", iter.second->GetKillScore());
// 		mPlayerKillScoreList[iter.first]->SetString(mKillScoreBuf[iter.first]);
// 
// 		if (iter.second->GetTeam() == TeamColor::RED)
// 		{
// 			mPlayerLabelList[iter.first]->SetPosition(55, aY);
// 			mPlayerKillScoreList[iter.first]->SetPosition(205, aY);
// 			aY += 20.f;
// 		}
// 		else if (iter.second->GetTeam() == TeamColor::BLUE)
// 		{
// 			mPlayerLabelList[iter.first]->SetPosition(295, bY);
// 			mPlayerKillScoreList[iter.first]->SetPosition(415, bY);
// 			bY += 20.f;
// 		}
//	}
}
