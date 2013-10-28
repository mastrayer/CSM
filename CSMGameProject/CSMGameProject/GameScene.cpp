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
}