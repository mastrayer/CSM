#include "FifthCut.h"
#include "NNApplication.h"

FifthCut::FifthCut()
{
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	m_Background = NNSprite::Create( L"Sprite/StoryScene_4.png" );
	m_Background->SetPosition( width/2, height/2 );
	m_Background->SetCenter( m_Background->GetImageWidth()/2.f, m_Background->GetImageHeight()/2.f );
	AddChild( m_Background );

	m_StoryTextBox = NNSprite::Create( L"Sprite/StoryTextBox.png");
	m_StoryTextBox->SetPosition( width/2, height/2 + 200.f );
	m_StoryTextBox->SetCenter( m_StoryTextBox->GetImageWidth()/2.f, m_StoryTextBox->GetImageHeight()/2.f );
	AddChild( m_StoryTextBox );

	m_Text = NNLabel::Create( L"악의 정령왕 신틸리케를 무찔러주세요. 일어나세요, 용사여...", L"맑은 고딕", 20.f );
	AddChild( m_Text );

	m_Text->SetPosition( 100.f, 460.f );
	m_Text->SetBold( true );
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