
#pragma once

#include "NNSpriteNode.h"
#include <vector>

class NNAnimation : public NNObject
{
public:
	NNAnimation();
	virtual ~NNAnimation();

	void Render();
	void Update( float dTime );

	static NNAnimation* Create( int count, ... );
	static NNAnimation* Create();

	int GetFrameCount() const { return m_FrameCount; }
	int GetNowFrame() const { return m_Frame; }
	bool IsLoop() const { return m_Loop; }

	void AddSpriteNode( wchar_t* path );

private:
	std::vector<NNSpriteNode*> m_SpriteList;

	int m_FrameCount;
	int m_Frame;
	float m_Time;
	bool m_Loop;
};