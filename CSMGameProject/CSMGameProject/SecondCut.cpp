
#include "SecondCut.h"
#include "NNApplication.h"

SecondCut::SecondCut()
{
	float width = (float)NNApplication::GetInstance()->GetScreenWidth();
	float height = (float)NNApplication::GetInstance()->GetScreenHeight();

	m_Background = NNSprite::Create( L"Sprite/StoryScene_1.png" );
	m_Background->SetPosition( width/2, height/2 );
	m_Background->SetCenter( m_Background->GetImageWidth()/2.f, m_Background->GetImageHeight()/2.f );
	AddChild( m_Background );

	m_Text = NNLabel::Create( L"정령들은 정령왕을 뽑아 자연의 법칙을 관리하도록 하고 있다죠.", L"맑은 고딕", 20.f );
	AddChild( m_Text );

	m_Text->SetPosition( 30.f, 500.f );
	m_Text->SetBold( true );
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