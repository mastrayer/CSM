
#ifdef _DEBUG

#include "NetworkSample.h"

NetworkSample::NetworkSample()
{

}
NetworkSample::~NetworkSample()
{

}

void NetworkSample::Render()
{
	NNScene::Render();
}
void NetworkSample::Update( float dTime )
{
	NNScene::Update(dTime);
}

#endif