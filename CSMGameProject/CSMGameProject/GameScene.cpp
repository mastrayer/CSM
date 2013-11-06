#include "GameScene.h"
#include "NNApplication.h"


CGameScene::CGameScene(void)
{
	m_GameMap = CGameMap::Create();
	AddChild(m_GameMap);

	m_Character = CCharacter::Create();
	AddChild(m_Character);

	m_FPSLbael = NNLabel::Create( L"Normal Label", L"¸¼Àº °íµñ", 35.f );
	AddChild(m_FPSLbael);
}


CGameScene::~CGameScene(void)
{
}

void CGameScene::Render()
{
	NNObject::Render();
}
void CGameScene::Update( float dTime )
{
	NNObject::Update(dTime);
	
	swprintf_s(m_FPSLabelBuff,L"%f",NNApplication::GetInstance()->GetFPS());
	m_FPSLbael->SetString(m_FPSLabelBuff);

	NNPoint endPoint = NNPoint(- m_Character->GetPositionX() - m_Character->GetCharacterSprite()->GetImageWidth()/2 + 400.f
		,- m_Character->GetPositionY() - m_Character->GetCharacterSprite()->GetImageHeight()/2 + 300.f);
	
	SetPosition(NNPoint().Lerp(GetPosition(),endPoint,0.99f));
}