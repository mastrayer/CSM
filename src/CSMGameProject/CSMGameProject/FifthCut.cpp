#include "FifthCut.h"
#include "NNApplication.h"

FifthCut::FifthCut()
{
	////////// Window Frame Size //////////
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	////////// Background Image //////////
	mBackground = NNSprite::Create( L"Resource/Sprite/StoryScene/StoryScene_4.png" );
	mBackground->SetPosition( width/2, height/2 );
	mBackground->SetCenter( mBackground->GetImageWidth()/2.f, mBackground->GetImageHeight()/2.f );
	AddChild( mBackground );

	////////// Story Text Box //////////
	mStoryTextBox = NNSprite::Create( L"Resource/Sprite/StoryTextBox.png");
	mStoryTextBox->SetPosition( width/2, height/2 + 200.f );
	mStoryTextBox->SetCenter( mStoryTextBox->GetImageWidth()/2.f, mStoryTextBox->GetImageHeight()/2.f );
	AddChild( mStoryTextBox );

	////////// Story Text Label //////////
	mText = NNLabel::Create( L"다음 정령왕이 되어 악의 정령왕 신틸리케를 무찔러주세요.\n일어나세요, 용사여...", L"맑은 고딕", 20.f );
	mText->SetPosition( 100.f, 460.f );
	mText->SetBold( true );
	AddChild( mText );
}
FifthCut::~FifthCut()
{
}

void FifthCut::Render()
{
	StoryCut::Render();
}
void FifthCut::Update( float dTime )
{
	StoryCut::Update( dTime );
}