
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

	NNAnimation* Create( ... );
private:
	std::vector<NNSpriteNode*> m_SpriteList;

	int m_Frame;
	float m_Time;
};