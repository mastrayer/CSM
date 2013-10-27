#include "GameMap.h"


CGameMap::CGameMap(void)
{
	m_MapSprite = NNSprite::Create( L"Sprite/map.png" );
	m_MapSprite->SetPosition( 0.f, 0.f );
	AddChild( m_MapSprite );
}


CGameMap::~CGameMap(void)
{
}

void CGameMap::Update( float dTime)
{

}
void CGameMap::Render()
{
	NNObject::Render();
}