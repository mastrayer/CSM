
#include "StoryScene.h"
#include "FirstCut.h"

#include "NNInputSystem.h"

StoryScene::StoryScene()
	: m_CutState(0)
{
	m_StoryCut[0] = FirstCut::Create();
	m_StoryCut[1] = FirstCut::Create();
	AddChild( m_StoryCut[0] );
	AddChild( m_StoryCut[1] );

	for (int i=1; i<2; i++ )
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

	if ( NNInputSystem::GetInstance()->GetKeyState(VK_RETURN) == VK_UP )
	{
		++m_CutState;
		m_StoryCut[m_CutState-1]->SetVisible(false);
		m_StoryCut[m_CutState]->SetVisible(true);
	}
}