
#include "SecondCut.h"
#include "NNApplication.h"

SecondCut::SecondCut()
{
	////////// Window Frame Size //////////
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	////////// Background Image //////////
	mBackground = NNSprite::Create( L"Resource/Sprite/StoryScene/StoryScene_1.png" );
	mBackground->SetPosition( width/2, height/2 );
	mBackground->SetCenter( mBackground->GetImageWidth()/2.f, mBackground->GetImageHeight()/2.f );
	AddChild( mBackground );

	////////// Story Text Box //////////
	mStoryTextBox = NNSprite::Create( L"Resource/Sprite/StoryScene/StoryTextBox.png");
	mStoryTextBox->SetPosition( width/2, height/2 + 200.f );
	mStoryTextBox->SetCenter( mStoryTextBox->GetImageWidth()/2.f, mStoryTextBox->GetImageHeight()/2.f );
	AddChild( mStoryTextBox );

	////////// Story Text Label //////////
	mText = NNLabel::Create( L"정령들은 정령왕을 뽑아 자연의 법칙을 관리하도록 하고 있다죠.", L"맑은 고딕", 20.f );
	mText->SetPosition( 100.f, 460.f );
	mText->SetBold( true );
	AddChild( mText );
}
SecondCut::~SecondCut()
{

}

void SecondCut::Render()
{
	StoryCut::Render();
}
void SecondCut::Update( float dTime )
{
	StoryCut::Update( dTime );
}