#include "MainMenuScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "NNApplication.h"
#include "NNAudioSystem.h"

#include "GameMap.h"

#include "StoryScene.h"

#include "GameScene.h"

MainMenuScene::MainMenuScene()
	: mMainMenuImage(nullptr)
{
	mMenuSellction = 0;

	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	////////// Main Menu Background //////////
	mMainMenuImage = NNSprite::Create( L"Sprite/MainMenu.jpg" );
	mMainMenuImage->SetPosition( width/2, height/2 );
	mMainMenuImage->SetCenter( mMainMenuImage->GetImageWidth()/2.f, mMainMenuImage->GetImageHeight()/2.f + 70.f );
	AddChild( mMainMenuImage );

	////////// Main Menu SellcetionBar //////////
	mMainMenuSellcetionBar = NNSprite::Create( L"Sprite/MenuSellecter.png");
	mMainMenuSellcetionBar->SetPosition( width/2, height/2 );
	mMainMenuSellcetionBar->SetScale( 0.5f, 0.5f );
	AddChild( mMainMenuSellcetionBar ) ;

	////////// Main Menu Labels //////////
	mMainMenuLable[MENU_PLAY] = NNLabel::Create( L"Play", L"¸¼Àº °íµñ", 35.f );
	mMainMenuLable[MENU_PLAY]->SetPosition( width/2 + 200.f, height/2 + 150.f );
	AddChild( mMainMenuLable[MENU_PLAY] );

	mMainMenuLable[MENU_STORY] = NNLabel::Create( L"Story", L"¸¼Àº °íµñ", 35.f );
	mMainMenuLable[MENU_STORY]->SetPosition( width/2 + 200.f, height/2 + 200.f );
	AddChild( mMainMenuLable[MENU_STORY] );

	mMainMenuLable[MENU_EXIT] = NNLabel::Create( L"Exit", L"¸¼Àº °íµñ", 35.f );
	mMainMenuLable[MENU_EXIT]->SetPosition( width/2 + 200.f, height/2 + 250.f);
	AddChild( mMainMenuLable[MENU_EXIT] );

	////////// Background Music //////////
	mBGM = NNResourceManager::GetInstance()->LoadSoundFromFile( "sound/mainBGM.mp3", true );
	NNAudioSystem::GetInstance()->Play( mBGM ); 
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::Render()
{
	NNScene::Render();
}

void MainMenuScene::Update( float dTime )
{
	NNScene::Update( dTime );

	mMainMenuImage->SetVisible( true );

	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();
	
	if ( NNInputSystem::GetInstance()->GetKeyState( VK_UP ) == KEY_DOWN
		|| NNInputSystem::GetInstance()->GetKeyState( VK_LEFT ) == KEY_DOWN )
	{
		--mMenuSellction;
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( VK_DOWN ) == KEY_DOWN
		|| NNInputSystem::GetInstance()->GetKeyState( VK_RIGHT ) == KEY_DOWN )
	{
		++mMenuSellction;
	}

	mMainMenuSellcetionBar->SetPosition( width/2 + 150.f, height/2 + 150.f + mMenuSellction * 50 );

	mMenuSellction = ( mMenuSellction + MENU_EXIT + 1 ) % ( MENU_EXIT + 1 );

	if ( mMenuSellction == MenuList::MENU_PLAY && NNInputSystem::GetInstance()->GetKeyState(VK_RETURN) == KEY_UP )
	{
		NNSceneDirector::GetInstance()->ChangeScene( CGameScene::Create() );
	}
	else if ( mMenuSellction == MenuList::MENU_STORY && NNInputSystem::GetInstance()->GetKeyState(VK_RETURN) == KEY_UP )
	{
		NNSceneDirector::GetInstance()->ChangeScene( StoryScene::Create() );
	}
	else if ( mMenuSellction == MenuList::MENU_EXIT )
	{
		// exit
	}
}