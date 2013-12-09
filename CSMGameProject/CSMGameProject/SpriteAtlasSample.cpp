
#ifdef _DEBUG

#include "SpriteAtlasSample.h"

SpriteAtlasSample::SpriteAtlasSample()
{
	mSpriteAtlas = NNSpriteAtlas::Create(L"Sprite/map.png");
	AddChild(mSpriteAtlas);

	mSpriteAtlas->SetCutSize(0,0,100.f,100.f);
	mSpriteAtlas->SetPosition(100.f,100.f);
}

SpriteAtlasSample::~SpriteAtlasSample()
{

}

void SpriteAtlasSample::Render()
{
	NNScene::Render();
}

void SpriteAtlasSample::Update( float dTime )
{
	NNScene::Update(dTime);
}

#endif