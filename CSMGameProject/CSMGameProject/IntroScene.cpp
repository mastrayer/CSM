#include "IntroScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "NNApplication.h"

#include "StoryScene.h"

IntroScene::IntroScene()
	: m_IntroSceneImage(nullptr)
{
	m_IntroSceneIndex = 0;

	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();
	
	
	m_IntroSceneImage = NNSprite::Create( L"Sprite/MainMenu.jpg" );
	m_IntroSceneImage->SetPosition( width/2, height/2 );
	m_IntroSceneImage->SetCenter( m_IntroSceneImage->GetPositionX()/2.f, m_IntroSceneImage->GetPositionY()/2.f + 70.f );
	AddChild( m_IntroSceneImage );

	/* MenuSellectionBar type
	m_MainMenuSellcetionBar = NNSprite::Create( L"Sprite/MenuSellectionBar.png");
	m_MainMenuSellcetionBar->SetPosition( width/2 + 200.f, height/2 + 200.f + m_MenuSellction * 50 );
	AddChild( m_MainMenuSellcetionBar ) ;
	*/

	m_IntroNextSellcetionImage = NNSprite::Create( L"Sprite/MenuSellecter.gif");
	m_IntroNextSellcetionImage->SetPosition( width/2, height/2 );
	m_IntroNextSellcetionImage->SetScale( 0.5f, 0.5f );
	AddChild( m_IntroNextSellcetionImage ) ;

	
	m_IntroSceneMenu[MENU_SKIP] = NNLabel::Create( L"Skip", L"¸¼Àº °íµñ", 35.f );
	m_IntroSceneMenu[MENU_SKIP]->SetPosition( width/2 + 200.f, height/2 + 150.f );
	AddChild( m_IntroSceneMenu[MENU_SKIP] );
	
	m_IntroSceneMenu[MENU_INTRO_EXIT] = NNLabel::Create( L"Exit", L"¸¼Àº °íµñ", 35.f );
	m_IntroSceneMenu[MENU_INTRO_EXIT]->SetPosition( width/2 + 200.f, height/2 + 200.f);
	AddChild( m_IntroSceneMenu[MENU_INTRO_EXIT] );

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
	m_MainMenuImage->SetVisible( true );

	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();
	
	if ( NNInputSystem::GetInstance()->GetKeyState( VK_UP ) == KEY_DOWN
		|| NNInputSystem::GetInstance()->GetKeyState( VK_LEFT ) == KEY_DOWN )
	{
		--m_MenuSellction;
	}
	if ( NNInputSystem::GetInstance()->GetKeyState( VK_DOWN ) == KEY_DOWN
		|| NNInputSystem::GetInstance()->GetKeyState( VK_RIGHT ) == KEY_DOWN )
	{
		++m_MenuSellction;
	}

	m_MainMenuSellcetionBar->SetPosition( width/2 + 150.f, height/2 + 150.f + m_MenuSellction * 50 );

	m_MenuSellction = ( m_MenuSellction + MENU_EXIT + 1 ) % ( MENU_EXIT + 1);

	if ( m_MenuSellction == 0 && NNInputSystem::GetInstance()->GetKeyState(VK_RETURN) == KEY_UP )
	{
		NNSceneDirector::GetInstance()->ChangeScene( StoryScene::Create() );
	}
	else if ( m_MenuSellction == 1 )
	{
		// exit
	}
	*/
}