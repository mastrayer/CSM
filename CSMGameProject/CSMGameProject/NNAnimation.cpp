
#include "NNAnimation.h"

NNAnimation::NNAnimation()
	: m_FrameCount(0), m_Frame(0), m_Time(0.f)
{

}
NNAnimation::~NNAnimation()
{
	for (auto& iter=m_SpriteList.begin(); iter!=m_SpriteList.end(); iter++ )
	{
		SafeDelete( *iter );
	}
	m_SpriteList.clear();
}

NNAnimation* NNAnimation::Create( int count, ... )
{
	NNAnimation* pInstance = new NNAnimation();

	va_list ap;
	va_start( ap, count );

	for (int i=0; i<count; i++ )
	{
		pInstance->m_SpriteList[i] = NNSpriteNode::Create( va_arg( ap, std::wstring ) );
		pInstance->m_SpriteList[i]->SetFrameTime( 0.2f );
	}

	va_end( ap );

	return pInstance;
}

void NNAnimation::Render()
{
	NNObject::Render();

	m_SpriteList[m_Frame]->Render();
}
void NNAnimation::Update( float eTime )
{
	NNObject::Update( eTime );

	m_Time += eTime;

	if ( m_Time >= m_SpriteList[m_Frame]->GetFrameTime() )
	{
		++m_Frame;
		m_Time = 0.f;
	}

	if ( m_Frame >= m_FrameCount ) 
	{
		m_Frame = 0;
	}
}