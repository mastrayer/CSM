
#ifdef _DEBUG

#include "CameraSample.h"

CameraSample::CameraSample()
{
	m_Sprite = NNSprite::Create(L"Sprite/character.png");
	AddChild(m_Sprite);
}
CameraSample::~CameraSample()
{

}

void CameraSample::Render()
{
	NNScene::Render();
}
void CameraSample::Update( float dTime )
{
	NNScene::Update(dTime);
}

#endif