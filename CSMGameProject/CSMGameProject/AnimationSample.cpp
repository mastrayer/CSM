
#ifdef _DEBUG

#include "AnimationSample.h"

AnimationSample::AnimationSample()
{
	m_Animation = NNAnimation::Create( 6, L"Sprite/attack_0.png",
										L"Sprite/attack_1.png", 
										L"Sprite/die_0.png", 
										L"Sprite/die_1.png",
										L"Sprite/idle_0.png", 
										L"Sprite/idle_1.png");

	AddChild( m_Animation );
}
AnimationSample::~AnimationSample()
{

}

void AnimationSample::Render()
{
	NNObject::Render();
}
void AnimationSample::Update( float eTime )
{
	NNObject::Update( eTime );
}

#endif