
#ifdef _DEBUG

#include "AnimationSample.h"

AnimationSample::AnimationSample()
{
	mAnimation = NNAnimation::Create( 6, L"Sprite/attack_0.png",
										L"Sprite/attack_1.png", 
										L"Sprite/die_0.png", 
										L"Sprite/die_1.png",
										L"Sprite/idle_0.png", 
										L"Sprite/idle_1.png");

	mAnimation->SetPosition( NNPoint(50.f,50.f) );
	 
	AddChild( mAnimation );
}
AnimationSample::~AnimationSample()
{

}

void AnimationSample::Render()
{
	NNScene::Render();
}
void AnimationSample::Update( float eTime )
{
	NNScene::Update( eTime );
}

#endif