
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
	NNNetworkSystem::GetInstance()->Init();
	NNNetworkSystem::GetInstance()->SetPacketFunction(PKT_TEST,TestPacketFunction);
	NNNetworkSystem::GetInstance()->SetPacketFunction(PKT_SC_CHAT,TestChatResultPacketFunction);
	NNNetworkSystem::GetInstance()->SetPacketFunction(PKT_CS_CHAT,TestChatRequestPacketFunction);
	NNNetworkSystem::GetInstance()->Connect("127.0.0.1",9002);
	m_Time = 0;
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
	SleepEx(0, TRUE);
	m_Time += dTime;

	if(m_Time > 1)
	{
		m_Time = 0;
		ChatBroadcastRequest CBR = ChatBroadcastRequest();
		strcpy_s(CBR.m_Chat, "H");
		CBR.m_PlayerId = -1;
		NNNetworkSystem::GetInstance()->Send(&CBR);
	}
}

#endif