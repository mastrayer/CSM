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

	m_Text = NNLabel::Create( L"하지만 신틸리케는 자신의 권한과 힘에 흑화되었습니다.", L"맑은 고딕", 20.f );
	AddChild( m_Text );

	m_Text->SetPosition( 30.f, 500.f );
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