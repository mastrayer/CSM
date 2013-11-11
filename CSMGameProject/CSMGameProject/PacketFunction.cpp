#include "PacketFunction.h"
void TestChatResultPacketFunction( NNPacketHeader& header )
{
	ChatBroadcastResult recvData;
	if ( NNNetworkSystem::GetInstance()->GetRecvBuffer()->Read((char*)&recvData, header.m_Size) )
	{
		std::cout << recvData.m_Chat << std::endl;
		std::cout << recvData.m_Name << std::endl;
		std::cout << recvData.m_PlayerId << std::endl;
	}
	else
	{
		std::cout << "exception" << std::endl;
	}
}


void TestChatRequestPacketFunction( NNPacketHeader& header )
{
	ChatBroadcastRequest recvData;
	if ( NNNetworkSystem::GetInstance()->GetRecvBuffer()->Read((char*)&recvData, header.m_Size) )
	{
		std::cout << recvData.m_Chat << std::endl;
		std::cout << recvData.m_PlayerId << std::endl;
	}
	else
	{
		std::cout << "exception" << std::endl;
	}
}