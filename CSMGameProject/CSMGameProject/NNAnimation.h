
#pragma once

#include "NNSpriteNode.h"
#include <vector>

class NNAnimation : public NNObject
{
public:
	NNAnimation();
	virtual ~NNAnimation();

	void Render();
	void Update( float eTime );
private:
	std::vector<NNSpriteNode*> m_SpriteList;
};