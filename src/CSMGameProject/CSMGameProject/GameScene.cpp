
#include "GameScene.h"
#include "NNApplication.h"
#include "PacketType.h"
#include "NNNetworkSystem.h"
#include "PacketHandler.h"
#include "EffectManager.h"
#include "NNAudioSystem.h"
#include "NNResourceManager.h"

#include "PlayerManager.h"
#include "GameManager.h"

#include "NNLogger.h"

CGameScene::CGameScene() :
mNowGameKeyStates(), mAngle(0), mLastAngleChangedTime(timeGetTime()),
misInit(false),
mLoadingComplete(false), mIsKeyDown(false),mFristLogin(true)
{
	// Camera Setting
	GetCamera().SetCameraAnchor(CameraAnchor::MIDDLE_CENTER);

 	mBackgroundImage = NNSprite::Create(NNResourceManager::GetInstance()->UnzipFileToMemory(L"resource/map/44.csm", L"title"));
	mIntro1 = NNSprite::Create(L"Resource/Sprite/UI/Loading/intro.png");
	mIntro2 = NNSprite::Create(L"Resource/Sprite/UI/Loading/intro2.png");
	mVictory = NNSprite::Create(L"Resource/Sprite/GameOver/Victory.png");
	mDefeat = NNSprite::Create(L"Resource/Sprite/GameOver/Defeat.png");

	// GameMap Create
	mGameMap[0] = CGameMap::Create(L"resource/map/44.csm");
	mGameMap[1] = CGameMap::Create(L"resource/map/44.csm");
	mGameMap[2] = CGameMap::Create(L"resource/map/44.csm");


	// EffectManager
	AddChild( EffectManager::GetInstance() , 1);

	// Sound Preload
	NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/player_walk.wav");
	NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/player_hit.wav");
	NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/fire_attack.wav");
	NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/fire_skill.wav");
	NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/water_attack.wav");
	NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/water_skill.wav");
	NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/wind_attack.wav");
	NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/wind_skill.wav");
	NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/earth_attack.wav");
	NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/earth_skill.wav");
	NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/GameScene.mp3");
	NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/Flash.mp3");
	
	NNAudioSystem::GetInstance()->Play(NNResourceManager::GetInstance()->LoadSoundFromFile("Resource/Sound/GameScene.mp3"));

	InitNetworkSetting();
}

CGameScene::~CGameScene(void)
{
	CPlayerManager::ReleaseInstance();
	GameManager::ReleaseInstance();
}

void CGameScene::Init()
{
}

void CGameScene::Render()
{
	NNScene::Render();
	if (mLoadingComplete == false)
	{
		mBackgroundImage->Render();

		if (mIsKeyDown == false)
		{
			mIntro1->Render();
			mIntro2->Render();
		}
	}
}

void CGameScene::Update( float dTime )
{
	NNScene::Update(dTime);

	if (mIsKeyDown == false && NNInputSystem::GetInstance()->GetKeyState(VK_RETURN) == KEY_DOWN)
	{
		mIsKeyDown = true;
		
	}

	if (mIsKeyDown == true && mLoadingComplete == false)
	{
		if (mBackgroundImage->GetOpacity() > 0.f)
			mBackgroundImage->SetOpacity(mBackgroundImage->GetOpacity() - 0.01f);
		else
		{
			mLoadingComplete = true;
			delete mBackgroundImage;
			delete mIntro1;
			delete mIntro2;
		}
	}

	if( CPlayerManager::GetInstance()->IsLogin() == true )
	{
		if(mFristLogin == true)
		{
			AddChild(mGameMap[CPlayerManager::GetInstance()->GetMapType()],-1);
			mFristLogin = false;
		}
	//	TODO :: CPlayerManager의 Score, Limit를 표현해주세요
		if(misInit == false)
		{
			misInit = true;
			mMyPlayer = CPlayerManager::GetInstance()->GetMyPlayer();
			// UI Setting
			SetUISet( GameUISet::GetInstance() );
		}

		/*GetCamera().SetPosition(NNPoint().Lerp(GetCamera().GetPosition(),
		CPlayerManager::GetInstance()->GetMyPlayer()->GetPosition()
		,1.f));*/
		GetCamera().SetPosition(CPlayerManager::GetInstance()->GetMyPlayer()->GetPosition());

		if (mMyPlayer->IsEmoticonRunning() == false)
		{
			if (NNInputSystem::GetInstance()->GetKeyState('1') == KEY_DOWN)
			{
				EmoticonRequest outPacket = EmoticonRequest();
				outPacket.mEmoticonNumber = EmoticonType::SMILE;
				outPacket.mPlayerId = CPlayerManager::GetInstance()->GetMyPlayerId();
				NNNetworkSystem::GetInstance()->Write((const char*)&outPacket,
					outPacket.mSize);
				mMyPlayer->SetEmoticonRunning(true);
			}
			if (NNInputSystem::GetInstance()->GetKeyState('2') == KEY_DOWN)
			{
				EmoticonRequest outPacket = EmoticonRequest();
				outPacket.mEmoticonNumber = EmoticonType::SAD;
				outPacket.mPlayerId = CPlayerManager::GetInstance()->GetMyPlayerId();
				NNNetworkSystem::GetInstance()->Write((const char*)&outPacket,
					outPacket.mSize);
				mMyPlayer->SetEmoticonRunning(true);
			}

			if (NNInputSystem::GetInstance()->GetKeyState('3') == KEY_DOWN)
			{
				EmoticonRequest outPacket = EmoticonRequest();
				outPacket.mEmoticonNumber = EmoticonType::ANGRY;
				outPacket.mPlayerId = CPlayerManager::GetInstance()->GetMyPlayerId();
				NNNetworkSystem::GetInstance()->Write((const char*)&outPacket,
					outPacket.mSize);
				mMyPlayer->SetEmoticonRunning(true);
			}

			if (NNInputSystem::GetInstance()->GetKeyState('4') == KEY_DOWN)
			{
				EmoticonRequest outPacket = EmoticonRequest();
				outPacket.mEmoticonNumber = EmoticonType::HELP;
				outPacket.mPlayerId = CPlayerManager::GetInstance()->GetMyPlayerId();
				NNNetworkSystem::GetInstance()->Write((const char*)&outPacket,
					outPacket.mSize);
				mMyPlayer->SetEmoticonRunning(true);
			}
		}
		

		if( isChangedGameKeyStates() == true )
		{
			mLastAngleChangedTime = timeGetTime();
			mAngle = GetNowAngle();
			mNowGameKeyStates = GetNowGameKeyStates();
			if(mNowGameKeyStates.leftDirectKey == KEYSTATE_PRESSED && mNowGameKeyStates.rightDirectKey == KEYSTATE_PRESSED)
			{
				//printf("ok");
			}
			//send packet
			mGameKeyStatesUpdateHandler->mGameKeyStatesUpdateRequest.mMyPlayerInfo.mGameKeyStates = mNowGameKeyStates;
			mGameKeyStatesUpdateHandler->mGameKeyStatesUpdateRequest.mMyPlayerInfo.mPlayerId = CPlayerManager::GetInstance()->GetMyPlayerId();
			mGameKeyStatesUpdateHandler->mGameKeyStatesUpdateRequest.mMyPlayerInfo.mX = CPlayerManager::GetInstance()->GetMyPlayer()->GetPositionX();
			mGameKeyStatesUpdateHandler->mGameKeyStatesUpdateRequest.mMyPlayerInfo.mY = CPlayerManager::GetInstance()->GetMyPlayer()->GetPositionY();
			mGameKeyStatesUpdateHandler->mGameKeyStatesUpdateRequest.mMyPlayerInfo.mAngle = mAngle;
			NNNetworkSystem::GetInstance()->Write( (const char*)&mGameKeyStatesUpdateHandler->mGameKeyStatesUpdateRequest,
				mGameKeyStatesUpdateHandler->mGameKeyStatesUpdateRequest.mSize );
		}
		if( isChangedAngle() == true )
		{
			mLastAngleChangedTime = timeGetTime();
			mAngle = GetNowAngle();
			mMouseAngleUpdateHandler->mMouseAngleUpdateRequest.mPlayerId = CPlayerManager::GetInstance()->GetMyPlayerId();
			mMouseAngleUpdateHandler->mMouseAngleUpdateRequest.mAngle = mAngle;
			NNNetworkSystem::GetInstance()->Write( (const char*)&mMouseAngleUpdateHandler->mMouseAngleUpdateRequest,
				mMouseAngleUpdateHandler->mMouseAngleUpdateRequest.mSize );
		}
	}
}

void CGameScene::InitNetworkSetting()
{
	mLoginHandler = new LoginHandler();
	mLoginBroadcastHandler = new LoginBroadcastHandler();
	mGameKeyStatesUpdateHandler = new GameKeyStatesUpdateHandler();
	mLogoutHandler = new LogoutHandler();
	mMouseAngleUpdateHandler = new MouseAngleUpdateHandler();
	mHPUpdateHandler = new HPUpdateHandler();
	mEndOfGameHandler = new EndOfGameHandler();
	mKillScoreHandler = new KillScoreHandler();
	mPlayerKillScoreHandler = new KillScoreHandler();
	mATypeSkillShootHandler = new ATypeSkillShootHandler();
	mATypeAttackEndHandler = new ATypeAttackEndHandler();
	mATypeAttackShootHandler = new ATypeAttackShootHandler();

	mBTypeSkillShootHandler = new BTypeSkillShootHandler();
	mBTypeAttackEndHandler = new BTypeAttackEndHandler();
	mBTypeAttackShootHandler = new BTypeAttackShootHandler();

	mCTypeAttackEndHandler = new CTypeAttackEndHandler();
	mCTypeAttackShootHandler = new CTypeAttackShootHandler();
	mCTypeSkillShootHandler = new CTypeSkillShootHandler();
	
	mDTypeAttackShootHandler = new DTypeAttackShootHandler();
	mDTypeSkillShootHandler = new DTypeSkillShootHandler();
	mDTypeSkillEndHandler = new DTypeSkillEndHandler();

	mUserSkillFlashHandler = new UserSkillFlashHandler();

	mEmoticonHandler = new EmoticonHandler();

	mItemComeHandler = new ItemComeHandler();
	mItemPlayerConsumeHandler = new ItemPlayerConsumeHandler();
	mItemPlayerDropHandler = new ItemPlayerDropHandler();

	NNNetworkSystem::GetInstance()->Init();

	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_KEYSTATE, mGameKeyStatesUpdateHandler );
	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_LOGIN, mLoginHandler );
	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_LOGIN_BROADCAST, mLoginBroadcastHandler );
	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_LOGOUT, mLogoutHandler );
	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_MOUSEANGLE, mMouseAngleUpdateHandler );
	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_HP, mHPUpdateHandler );
	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_ENDOFGAME, mEndOfGameHandler );
	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_KILLSCORE, mKillScoreHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler( PKT_SC_PLAYER_KILLSCORE_UPDATE, mPlayerKillScoreHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_A_TYPESKILL_SHOOT, mATypeSkillShootHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_A_TYPEATTACK_SHOOT, mATypeAttackShootHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_A_TYPEATTACK_END, mATypeAttackEndHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_B_TYPESKILL_SHOOT, mBTypeSkillShootHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_B_TYPEATTACK_SHOOT, mBTypeAttackShootHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_B_TYPEATTACK_END, mBTypeAttackEndHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_C_TYPEATTACK_SHOOT, mCTypeAttackShootHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_C_TYPEATTACK_END, mCTypeAttackEndHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_C_TYPESKILL_SHOOT, mCTypeSkillShootHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_D_TYPEATTACK_SHOOT, mDTypeAttackShootHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_D_TYPESKILL_SHOOT, mDTypeSkillShootHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_D_TYPESKILL_END, mDTypeSkillEndHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_EMOTICON, mEmoticonHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_USERSKILL_FLASH, mUserSkillFlashHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_ITEM_COME, mItemComeHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_ITEM_PLAYER_CONSUME, mItemPlayerConsumeHandler);
	NNNetworkSystem::GetInstance()->SetPacketHandler(PKT_SC_ITEM_PLAYER_DROP, mItemPlayerDropHandler);
	


	NNNetworkSystem::GetInstance()->Connect( "10.73.44.30", 9001 );
	//NNNetworkSystem::GetInstance()->Connect("10.73.43.90", 9001);
	//NNNetworkSystem::GetInstance()->Connect( "127.0.0.1", 9001 );

	mLoginHandler->mLoginRequestPacket.mGameId = 1;
	mLoginHandler->mLoginRequestPacket.mPlayerId = 4;
	NNNetworkSystem::GetInstance()->Write( (const char*)&mLoginHandler->mLoginRequestPacket, mLoginHandler->mLoginRequestPacket.mSize );
}

GameKeyStates CGameScene::GetNowGameKeyStates()
{
	GameKeyStates nowGameKeyState;
	if( NNInputSystem::GetInstance()->GetKeyState('W') == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState('W') == KEY_DOWN )
		nowGameKeyState.upDirectKey = KEYSTATE_PRESSED;
	if( NNInputSystem::GetInstance()->GetKeyState('S') == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState('S') == KEY_DOWN )
		nowGameKeyState.downDirectKey = KEYSTATE_PRESSED;
	if( NNInputSystem::GetInstance()->GetKeyState('A') == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState('A') == KEY_DOWN )
		nowGameKeyState.leftDirectKey = KEYSTATE_PRESSED;
	if( NNInputSystem::GetInstance()->GetKeyState('D') == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState('D') == KEY_DOWN )
		nowGameKeyState.rightDirectKey = KEYSTATE_PRESSED;
	if( NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState(VK_LBUTTON) == KEY_DOWN )
		nowGameKeyState.attackKey = KEYSTATE_PRESSED;
	if( NNInputSystem::GetInstance()->GetKeyState(VK_RBUTTON) == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState(VK_RBUTTON) == KEY_DOWN )
		nowGameKeyState.typeActiveSkillKey = KEYSTATE_PRESSED;
	if( NNInputSystem::GetInstance()->GetKeyState(VK_SPACE) == KEY_PRESSED ||
		NNInputSystem::GetInstance()->GetKeyState(VK_SPACE) == KEY_DOWN )
		nowGameKeyState.userActiveSkillKey = KEYSTATE_PRESSED;

	return nowGameKeyState;
}
bool CGameScene::isChangedGameKeyStates()
{
	GameKeyStates nowGameKeyState = GetNowGameKeyStates();
	printf("%d - %d // %d - %d\n ", nowGameKeyState.leftDirectKey,nowGameKeyState.rightDirectKey,mNowGameKeyStates.leftDirectKey,mNowGameKeyStates.rightDirectKey);
	if( nowGameKeyState.attackKey != mNowGameKeyStates.attackKey
		||nowGameKeyState.upDirectKey != mNowGameKeyStates.upDirectKey
		||nowGameKeyState.downDirectKey != mNowGameKeyStates.downDirectKey
		||nowGameKeyState.leftDirectKey != mNowGameKeyStates.leftDirectKey
		||nowGameKeyState.rightDirectKey != mNowGameKeyStates.rightDirectKey
		||nowGameKeyState.typeActiveSkillKey != mNowGameKeyStates.typeActiveSkillKey
		||nowGameKeyState.userActiveSkillKey != mNowGameKeyStates.userActiveSkillKey)
		return true;
	return false;
}

float CGameScene::GetNowAngle()
{
	NNPoint mousePoint = NNInputSystem::GetInstance()->GetMousePosition();
	// characterPositionByWC, WC -> window center. 화면 가운데를 0,0으로 했을때의 캐릭터 좌표
	//NNPoint characterPositionByWC = GetCamera().GetPosition() -	CPlayerManager::GetInstance()->GetMyPlayer()->GetPosition();
	NNPoint referencePointForMouse = NNPoint(GetCamera().GetScreenWidth()/2.f,GetCamera().GetScreenHeight()/2.f);// + characterPositionByWC;
	return atan2f( NNPoint(mousePoint-referencePointForMouse).GetY() , NNPoint(mousePoint-referencePointForMouse).GetX() );
}
bool CGameScene::isChangedAngle()
{
	DWORD time_A = timeGetTime();
	if( (timeGetTime() - mLastAngleChangedTime ) > 20 )
	{
		//20 밀리세컨드마다 마우스 방향 변경.
		if( mAngle != GetNowAngle() )
			return true;
	}
	return false;
}