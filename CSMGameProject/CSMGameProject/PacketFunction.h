
#pragma once

#include "Packet.h"
#include "NNCircularBuffer.h"
#include "NNNetworkSystem.h"
#include <iostream>

void TestPacketFunction( NNPacketHeader& header )
{
	TestPacket recvData;
	if ( NNNetworkSystem::GetInstance()->GetRecvBuffer()->Read((char*)&recvData, header.m_Size) )
	{
		std::cout << recvData.m_Char << std::endl;
		std::cout << recvData.m_Float << std::endl;
		std::cout << recvData.m_Int << std::endl;
	}
	else
	{
		std::cout << "exception" << std::endl;
	}
}


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