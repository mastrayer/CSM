
#include "FirstCut.h"

FirstCut::FirstCut()
{
	m_Background = NNSprite::Create( L"Sprite/map.png" );
	AddChild( m_Background );

	m_Text = NNLabel::Create( L"테스트 테스트\n테스트 테스트 입니다.", L"맑은 고딕", 20.f );
	AddChild( m_Text );

	m_Text->SetPosition( 30.f, 500.f );
	m_Text->SetBold( true );
}
FirstCut::~FirstCut()
{

}

void FirstCut::Render()
{
	StoryCut::Render();
}
void FirstCut::Update( float dTime )
{
	StoryCut::Update( dTime );
}