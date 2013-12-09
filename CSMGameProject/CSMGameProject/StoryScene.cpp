
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
	: mCutState(0)
{
	mStoryCut[0] = FirstCut::Create();
	mStoryCut[1] = SecondCut::Create();
	mStoryCut[2] = ThirdCut::Create();
	mStoryCut[3] = FourthCut::Create();
	mStoryCut[4] = FifthCut::Create();
	AddChild( mStoryCut[0] );
	AddChild( mStoryCut[1] );
	AddChild( mStoryCut[2] );
	AddChild( mStoryCut[3] );
	AddChild( mStoryCut[4] );

	for (int i=1; i<5; i++ )
	{
		mStoryCut[i]->SetVisible(false);
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
		++mCutState;
		if ( mCutState >= 5 )
		{
			NNSceneDirector::GetInstance()->ChangeScene( CGameScene::Create() );
			return;
		}
		mStoryCut[mCutState-1]->SetVisible(false);
		mStoryCut[mCutState]->SetVisible(true);
	}
}