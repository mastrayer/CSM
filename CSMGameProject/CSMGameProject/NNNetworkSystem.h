
/**********************************************************************/
/**********************************************************************/
/*                                                                    */
/*                                                                    */
/*                       작업 중 건들지 말 것!                        */
/*                                                                    */
/*                                                                    */
/**********************************************************************/
/**********************************************************************/

#pragma once

#include "NNConfig.h"
#include "NNPacketHeader.h"
#include "NNCircularBuffer.h"
#include <map>

class NNNetworkSystem
{
public:
	static NNNetworkSystem* GetInstance();
	static void ReleaseInstance();

	bool Init();
	void Destroy();
	bool Connect( const char* serverIP, int port );

	void ProcessPacket();

	void SetPacketFunction( short packetType, void(*Function)(NNCircularBuffer*&, NNPacketHeader&) );
	NNCircularBuffer* GetCircularBuffer() { return m_CircularBuffer; }

private:
	WSADATA m_WSAData;
	SOCKET m_Socket;

	SOCKADDR_IN m_ServerAddr;

	char* m_ServerIP;
	int m_Port;

	NNCircularBuffer* m_CircularBuffer;

	std::map<short,void(*)(NNCircularBuffer*&, NNPacketHeader&)> m_PacketFunction;

private:
	static NNNetworkSystem* m_pInstance;

	NNNetworkSystem();
	~NNNetworkSystem();
};