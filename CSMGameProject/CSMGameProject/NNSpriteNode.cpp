
#include "NNSpriteNode.h"

NNSpriteNode::NNSpriteNode()
	: m_Sprite(nullptr), m_FrameTime(0.f), m_Index(0)
{
}
NNSpriteNode::~NNSpriteNode()
{
	SafeDelete( m_Sprite );
}

NNSpriteNode* NNSpriteNode::Create( std::wstring path )
{
	NNSpriteNode* pInstance = new NNSpriteNode();
	pInstance->m_Sprite = NNSprite::Create( path );

	return pInstance;
}

void NNSpriteNode::Render()
{
	NNObject::Render();
}
void NNSpriteNode::Update( float dTime )
{
	NNObject::Update( dTime );
}