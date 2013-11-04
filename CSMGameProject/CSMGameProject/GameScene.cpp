#include "GameScene.h"


CGameScene::CGameScene(void)
{
	m_GameMap = CGameMap::Create();
	AddChild(m_GameMap);

	m_Character = CCharacter::Create();
	AddChild(m_Character);
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
	NNPoint endPoint = NNPoint(- m_Character->GetPositionX() - m_Character->GetCharacterSprite()->GetImageWidth()/2 + 400.f
		,- m_Character->GetPositionY() - m_Character->GetCharacterSprite()->GetImageHeight()/2 + 300.f);
	
	SetPosition(NNPoint().Lerp(GetPosition(),endPoint,0.7));
}