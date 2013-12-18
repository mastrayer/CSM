
#include "Effect.h"

IEffect::IEffect()
	: mLifeTime(0.f), mNowLifeTime(0.f), mIsEnd(false)
{
}
IEffect::~IEffect()
{
}

void IEffect::Render()
{
	NNObject::Render();
}
void IEffect::Update( float dTime )
{
	NNObject::Update( dTime );

	mNowLifeTime += dTime;
}