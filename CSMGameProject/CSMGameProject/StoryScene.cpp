
#include "StoryScene.h"
#include "FirstCut.h"
#include "SecondCut.h"
#include "ThirdCut.h"
#include "FourthCut.h"
#include "FifthCut.h"

#include "GameScene.h"

#include "NNInputSystem.h"
#include "NNSceneDirector.h"

StoryScene::StoryScene()
	: m_CutState(0)
{
	m_StoryCut[0] = FirstCut::Create();
	m_StoryCut[1] = SecondCut::Create();
	m_StoryCut[2] = ThirdCut::Create();
	m_StoryCut[3] = FourthCut::Create();
	m_StoryCut[4] = FifthCut::Create();
	AddChild( m_StoryCut[0] );
	AddChild( m_StoryCut[1] );
	AddChild( m_StoryCut[2] );
	AddChild( m_StoryCut[3] );
	AddChild( m_StoryCut[4] );

	for (int i=1; i<5; i++ )
	{
		m_StoryCut[i]->SetVisible(false);
	}
}
StoryScene::~StoryScene()
{

}

void StoryScene::Render()
{
	NNScene::Render();
}
void StoryScene::Update( float dTime )
{
	NNScene::Update( dTime );

	if ( NNInputSystem::GetInstance()->GetKeyState(VK_RETURN) == KEY_UP )
	{
		++m_CutState;
		if ( m_CutState >= 5 )
		{
			NNSceneDirector::GetInstance()->ChangeScene( CGameScene::Create() );
			return;
		}
		m_StoryCut[m_CutState-1]->SetVisible(false);
		m_StoryCut[m_CutState]->SetVisible(true);
	}
}