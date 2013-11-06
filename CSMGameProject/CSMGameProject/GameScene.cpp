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
	
	WCHAR buff[1024];
	swprintf_s(buff,L"%f",(1.f/dTime));
	m_FPSLbael->SetString(buff);

	NNPoint endPoint = NNPoint(- m_Character->GetPositionX() - m_Character->GetCharacterSprite()->GetImageWidth()/2 + 400.f
		,- m_Character->GetPositionY() - m_Character->GetCharacterSprite()->GetImageHeight()/2 + 300.f);
	
	SetPosition(NNPoint().Lerp(GetPosition(),endPoint,0.9f));
}