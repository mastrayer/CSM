
#pragma once

#include "Packet.h"
#include "NNCircularBuffer.h"
#include <iostream>

void TestPacketFunction( NNCircularBuffer*& circularBuffer, NNPacketHeader& header )
{
	TestPacket recvData;
	if ( circularBuffer->Read((char*)&recvData, header.m_Size) )
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