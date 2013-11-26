
#include "GameUISet.h"
#include "NNApplication.h"

GameUISet::GameUISet()
{
	m_FPSLabel = NNLabel::Create( L"", L"¸¼Àº °íµñ", 20 );
	AddChild( m_FPSLabel );

	ZeroMemory( m_FPSLabelBuff, sizeof(m_FPSLabelBuff) );
}
GameUISet::~GameUISet()
{

}

void GameUISet::Render()
{
	NNUISet::Render();
}
void GameUISet::Update( float dTime )
{
	NNUISet::Update( dTime );

	swprintf_s( m_FPSLabelBuff, L"%d", (int)NNApplication::GetInstance()->GetFPS() );
	m_FPSLabel->SetString( m_FPSLabelBuff );
}