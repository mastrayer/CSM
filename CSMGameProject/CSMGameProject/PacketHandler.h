
#pragma once

#include "NNBaseHandler.h"
#include "NNCircularBuffer.h"
#include "PacketType.h"

class HPUpdateHandler : public NNBaseHandler
{
public:
	HPUpdateHandler();
	virtual ~HPUpdateHandler();
	
	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	HPUpdateResult m_HPUpdateResult;
};

class MouseAngleUpdateHandler : public NNBaseHandler
{
public:
	MouseAngleUpdateHandler();
	virtual ~MouseAngleUpdateHandler();
	
	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	MouseAngleUpdateRequest m_MouseAngleUpdateRequest;
	MouseAngleUpdateResult m_MouseAngleUpdateResult;
};

class GameKeyStatesUpdateHandler : public NNBaseHandler
{
public:
	GameKeyStatesUpdateHandler();
	virtual ~GameKeyStatesUpdateHandler();

	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );
	GameKeyStatesUpdateRequest m_GameKeyStatesUpdateRequest;
	GameKeyStatesUpdateResult m_GameKeyStatesUpdateResult;
};

class LoginHandler : public NNBaseHandler
{
public:
	LoginHandler();
	virtual ~LoginHandler();

	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	LoginRequest m_LoginRequestPacket;
	LoginResult m_LoginResultPacket;
};

class LoginBroadcastHandler : public NNBaseHandler
{
public:
	LoginBroadcastHandler();
	virtual ~LoginBroadcastHandler();

	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	LoginBroadcastResult m_LoginBroadcastResultPacket;
};

class LogoutHandler : public NNBaseHandler
{
public:
	LogoutHandler();
	virtual ~LogoutHandler();

	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	LogoutResult m_LogoutResultPacket;
};