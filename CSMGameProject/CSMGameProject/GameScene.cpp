#include "GameScene.h"


CGameScene::CGameScene(void)
{
	m_GameMap = CGameMap::Create();
	AddChild(m_GameMap);
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

}