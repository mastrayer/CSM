#include "FourthCut.h"
#include "NNApplication.h"

FourthCut::FourthCut()
{
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	m_Background = NNSprite::Create( L"Sprite/StoryScene_3.png" );
	m_Background->SetPosition( width/2, height/2 );
	m_Background->SetCenter( m_Background->GetImageWidth()/2.f, m_Background->GetImageHeight()/2.f );
	AddChild( m_Background );

	m_StoryTextBox = NNSprite::Create( L"Sprite/StoryTextBox.png");
	m_StoryTextBox->SetPosition( width/2, height/2 + 200.f );
	m_StoryTextBox->SetCenter( m_StoryTextBox->GetImageWidth()/2.f, m_StoryTextBox->GetImageHeight()/2.f );
	AddChild( m_StoryTextBox );

	m_Text = NNLabel::Create( L"하지만 신틸리케는 흑화되어\n 다음 정령왕에게 왕좌를 주지 않으려 음모를 꾸밉니다.", L"맑은 고딕", 20.f );
	AddChild( m_Text );

	m_Text->SetPosition( 100.f, 460.f );
	m_Text->SetBold( true );
}
FourthCut::~FourthCut()
{

}

void FourthCut::Render()
{
	StoryCut::Render();
}
void FourthCut::Update( float dTime )
{
	StoryCut::Update( dTime );
}