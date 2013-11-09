
/**********************************************************************/
/**********************************************************************/
/*                                                                    */
/*                                                                    */
/*                       작업 중 건들지 말 것!                        */
/*                                                                    */
/*                                                                    */
/**********************************************************************/
/**********************************************************************/

#ifdef _DEBUG

#include "NetworkSample.h"
#include "Packet.h"
#include "PacketFunction.h"
#include "NNNetworkSystem.h"

NetworkSample::NetworkSample()
{
	//NNNetworkSystem::GetInstance()->Init();
	NNNetworkSystem::GetInstance()->SetPacketFunction(PKT_TEST,TestPacketFunction);
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