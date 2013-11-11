#include "PacketFunction.h"
void ChatResultPacketFunction( NNPacketHeader& header )
{
	ChatBroadcastResult recvData;
	std::cout << "ChatResultPacketFunction" << std::endl;
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

void KeyStateUpdateResultPacketFunction( NNPacketHeader& header )
{
	KeyStateUpdateResult recvData;
	std::cout << "KeyStateUpdateResultPacketFunction" << std::endl;
	if ( NNNetworkSystem::GetInstance()->GetRecvBuffer()->Read((char*)&recvData, header.m_Size) )
	{
		std::cout << recvData.m_PlayerId << std::endl;

	}
	else
	{
		std::cout << "exception" << std::endl;
	}
}