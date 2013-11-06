
#pragma once

#include "NNSprite.h"

class NNSpriteNode : public NNObject
{
public:
	NNSpriteNode();
	virtual ~NNSpriteNode();

	void Render();
	void Update( float dTime );

	//NNCREATE_FUNC(NNSpriteNode);

	static NNSpriteNode* Create( std::wstring path );

private:
	NNSprite* m_Sprite;
	float m_FrameTime;
	int m_Index;
};