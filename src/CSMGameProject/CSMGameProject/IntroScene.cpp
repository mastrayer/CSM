#include "IntroScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "NNApplication.h"

#include "StoryScene.h"

IntroScene::IntroScene()
	: mIntroSceneImage(nullptr)
{
	mIntroSceneIndex = 0;
	/*
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();
	
	
	mIntroSceneImage = NNSprite::Create( L"Resource/Sprite/IntroImage_0.png" );
	mIntroSceneImage->SetPosition( width/2, height/2 );
	mIntroSceneImage->SetCenter( mIntroSceneImage->GetPositionX()/2.f, mIntroSceneImage->GetPositionY()/2.f + 70.f );
	AddChild( mIntroSceneImage );

	mIntroSceneImage = NNSprite::Create( L"Resource/Sprite/IntroImage_1.png" );
	mIntroSceneImage->SetPosition( width/2, height/2 );
	mIntroSceneImage->SetCenter( mIntroSceneImage->GetPositionX()/2.f, mIntroSceneImage->GetPositionY()/2.f + 70.f );
	AddChild( mIntroSceneImage );

	mIntroSceneImage = NNSprite::Create( L"Resource/Sprite/IntroImage_2.png" );
	mIntroSceneImage->SetPosition( width/2, height/2 );
	mIntroSceneImage->SetCenter( mIntroSceneImage->GetPositionX()/2.f, mIntroSceneImage->GetPositionY()/2.f + 70.f );
	AddChild( mIntroSceneImage );

	mIntroSceneImage = NNSprite::Create( L"Resource/Sprite/IntroImage_3.png" );
	mIntroSceneImage->SetPosition( width/2, height/2 );
	mIntroSceneImage->SetCenter( mIntroSceneImage->GetPositionX()/2.f, mIntroSceneImage->GetPositionY()/2.f + 70.f );
	AddChild( mIntroSceneImage );

	mIntroSceneImage = NNSprite::Create( L"Resource/Sprite/IntroImage_4.png" );
	mIntroSceneImage->SetPosition( width/2, height/2 );
	mIntroSceneImage->SetCenter( mIntroSceneImage->GetPositionX()/2.f, mIntroSceneImage->GetPositionY()/2.f + 70.f );
	AddChild( mIntroSceneImage );
	*/

	/* MenuSellectionBar type
	mMainMenuSellcetionBar = NNSprite::Create( L"Resource/Sprite/MenuSellectionBar.png");
	mMainMenuSellcetionBar->SetPosition( width/2 + 200.f, height/2 + 200.f + mMenuSellction * 50 );
	AddChild( mMainMenuSellcetionBar ) ;
	*/

	/*
	mIntroNextSellcetionImage = NNSprite::Create( L"Resource/Sprite/MenuSellecter.png");
	mIntroNextSellcetionImage->SetPosition( width/2, height/2 );
	mIntroNextSellcetionImage->SetScale( 0.5f, 0.5f );
	AddChild( mIntroNextSellcetionImage ) ;

	
	mIntroSceneMenu[MENU_SKIP] = NNLabel::Create( L"Skip", L"¸¼Àº °íµñ", 35.f );
	mIntroSceneMenu[MENU_SKIP]->SetPosition( width/2 + 200.f, height/2 + 150.f );
	AddChild( mIntroSceneMenu[MENU_SKIP] );
	
	mIntroSceneMenu[MENU_INTRO_EXIT] = NNLabel::Create( L"Exit", L"¸¼Àº °íµñ", 35.f );
	mIntroSceneMenu[MENU_INTRO_EXIT]->SetPosition( width/2 + 200.f, height/2 + 200.f);
	AddChild( mIntroSceneMenu[MENU_INTRO_EXIT] );
	*/
}

IntroScene::~IntroScene()
{
}

void IntroScene::Render()
{
	NNScene::Render();
}

void IntroScene::Update( float dTime )
{
	NNScene::Update( dTime );
	/*
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

	mMenuSellction = ( mMenuSellction + MENU_EXIT + 1 ) % ( MENU_EXIT + 1);

	if ( mMenuSellction == 0 && NNInputSystem::GetInstance()->GetKeyState(VK_RETURN) == KEY_UP )
	{
		NNSceneDirector::GetInstance()->ChangeScene( StoryScene::Create() );
	}
	else if ( mMenuSellction == 1 )
	{
		// exit
	}
	*/
}