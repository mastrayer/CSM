
/**********************************************************************/
/**********************************************************************/
/*                                                                    */
/*                                                                    */
/*                       작업 중 건들지 말 것!                        */
/*                                                                    */
/*                                                                    */
/**********************************************************************/
/**********************************************************************/

#include "NNAnimationAtlas.h"

NNAnimationAtlas::NNAnimationAtlas()
	: m_FrameCount(0), m_Frame(0), m_Time(0.f), m_Loop(false), m_AnimationEnd(false)
{

}
NNAnimationAtlas::~NNAnimationAtlas()
{

}

void NNAnimationAtlas::Render()
{
	NNObject::Render();
}
void NNAnimationAtlas::Update( float dTime )
{
	NNObject::Update(dTime);
}

NNAnimationAtlas* NNAnimationAtlas::Create( std::wstring path )
{
	NNAnimationAtlas* pInstance = new NNAnimationAtlas();
	pInstance->m_SpriteAtlas = NNSpriteAtlas::Create( path );
	return pInstance;
}