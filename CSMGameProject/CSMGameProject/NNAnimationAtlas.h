
/**********************************************************************/
/**********************************************************************/
/*                                                                    */
/*                                                                    */
/*                       작업 중 건들지 말 것!                        */
/*                                                                    */
/*                                                                    */
/**********************************************************************/
/**********************************************************************/

#pragma once

#include "NNSpriteAtlas.h"

class NNAnimationAtlas : public NNObject
{
public:
	NNAnimationAtlas();
	virtual ~NNAnimationAtlas();

	void Render();
	void Update( float dTime );

	static NNAnimationAtlas* Create( std::wstring path );

	int GetFrameCount() const { return m_FrameCount; }
	int GetNowFrame() const { return m_Frame; }
	bool IsLoop() const { return m_Loop; }

	void AddFrame( float cutLeftX, float cutTopY, float cutRightX, float cutBottomY );
	void SetLoop( bool loop ) { m_Loop = loop; }

private:
	NNSpriteAtlas* m_SpriteAtlas;

	int m_FrameCount;
	int m_Frame;
	float m_Time;
	bool m_Loop;
	bool m_AnimationEnd;
};