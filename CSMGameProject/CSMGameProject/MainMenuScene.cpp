#include "MainMenuScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "NNApplication.h"

#include "StoryScene.h"

MainMenuScene::MainMenuScene()
	: m_MainMenuImage(nullptr)
{
	m_MenuSellction = 0;

	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();
	
	m_MainMenuImage = NNSprite::Create( L"Sprite/MainMenu.jpg" );
	m_MainMenuImage->SetPosition( width/2, height/2 );
	m_MainMenuImage->SetCenter( m_MainMenuImage->GetImageWidth()/2.f, m_MainMenuImage->GetImageHeight()/2.f + 70.f );
	AddChild( m_MainMenuImage );

	/* MenuSellectionBar type
	m_MainMenuSellcetionBar = NNSprite::Create( L"Sprite/MenuSellectionBar.png");
	m_MainMenuSellcetionBar->SetPosition( width/2 + 200.f, height/2 + 200.f + m_MenuSellction * 50 );
	AddChild( m_MainMenuSellcetionBar ) ;
	*/

	m_MainMenuSellcetionBar = NNSprite::Create( L"Sprite/MenuSellecter.png");
	m_MainMenuSellcetionBar->SetPosition( width/2, height/2 );
	m_MainMenuSellcetionBar->SetScale( 0.5f, 0.5f );
	AddChild( m_MainMenuSellcetionBar ) ;

	m_MianMenuLable[MENU_PLAY] = NNLabel::Create( L"Play", L"¸¼Àº °íµñ", 35.f );
	m_MianMenuLable[MENU_PLAY]->SetPosition( width/2 + 200.f, height/2 + 150.f );
	AddChild( m_MianMenuLable[MENU_PLAY] );

	m_MianMenuLable[MENU_EXIT] = NNLabel::Create( L"Exit", L"¸¼Àº °íµñ", 35.f );
	m_MianMenuLable[MENU_EXIT]->SetPosition( width/2 + 200.f, height/2 + 200.f);
	AddChild( m_MianMenuLable[MENU_EXIT] );

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
}