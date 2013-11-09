
#pragma once

#include "ABCircularBuffer.h"

#define BUF_SIZE (1024*10)

struct ClientInfo
{
	ClientInfo() : m_ClientId(-1), m_Sock(NULL), m_EchoBuffer(BUF_SIZE) {}

	int m_ClientId;
	SOCKET m_Sock;
	ABCircularBuffer m_EchoBuffer;
};