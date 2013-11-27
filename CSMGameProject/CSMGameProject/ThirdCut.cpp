#include "ThirdCut.h"
#include "NNApplication.h"

ThirdCut::ThirdCut()
{
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	m_Background = NNSprite::Create( L"Sprite/StoryScene_2.png" );
	m_Background->SetPosition( width/2, height/2 );
	m_Background->SetCenter( m_Background->GetImageWidth()/2.f, m_Background->GetImageHeight()/2.f );
	AddChild( m_Background );

	m_Text = NNLabel::Create( L"이번 정령왕은 신틸리케입니다. 신틸레케는 자신의 임무를 다할 것을 약속하였습니다.", L"맑은 고딕", 20.f );
	AddChild( m_Text );

	m_Text->SetPosition( 30.f, 500.f );
	m_Text->SetBold( true );
}
ThirdCut::~ThirdCut()
{

}

void ThirdCut::Render()
{
	StoryCut::Render();
}
void ThirdCut::Update( float dTime )
{
	StoryCut::Update( dTime );
}