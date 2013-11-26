#include "MainMenuScene.h"
#include "NNInputSystem.h"
#include "NNSceneDirector.h"
#include "GameScene.h"
#include "NNApplication.h"

MainMenuScene::MainMenuScene()
	: m_MainMenuImage(nullptr)
{
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	m_MainMenuImage = NNSprite::Create( L"Sprite/MainMenu.jpg" );
	m_MainMenuImage->SetPosition( width/2, height/2 );
	m_MainMenuImage->SetCenter( m_MainMenuImage->GetPositionX()/2.f, m_MainMenuImage->GetPositionY()/2.f + 70.f );
	AddChild( m_MainMenuImage );

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

	if ( NNInputSystem::GetInstance()->GetKeyState( VK_RETURN ) == KEY_UP )
	{
		NNSceneDirector::GetInstance()->ChangeScene( CGameScene::Create() );
		return;
	}
}