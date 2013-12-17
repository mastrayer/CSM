
#pragma once

#include "NNBaseHandler.h"
#include "NNCircularBuffer.h"
#include "PacketType.h"

class BTypeSkillEndHandler : public NNBaseHandler
{
public:
	BTypeSkillEndHandler();
	virtual ~BTypeSkillEndHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	BTypeSkillEndResult mBTypeSkillEndResult;
};
class ATypeSkillShootHandler : public NNBaseHandler
{
public:
	ATypeSkillShootHandler();
	virtual ~ATypeSkillShootHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	ATypeSkillShootResult mATypeSkillShootResult;
};
class BTypeSkillShootHandler : public NNBaseHandler
{
public:
	BTypeSkillShootHandler();
	virtual ~BTypeSkillShootHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	BTypeSkillShootResult mBTypeSkillShootResult;
};
class CTypeSkillShootHandler : public NNBaseHandler
{
public:
	CTypeSkillShootHandler();
	virtual ~CTypeSkillShootHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	CTypeSkillShootResult mCTypeSkillShootResult;
};

class KillScoreHandler : public NNBaseHandler
{
public:
	KillScoreHandler();
	virtual ~KillScoreHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	KillScoreResult mKillScoreResult;
	PlayerKillScoreUpdateResult mPlayerKillScoreResult;
};

class HPUpdateHandler : public NNBaseHandler
{
public:
	HPUpdateHandler();
	virtual ~HPUpdateHandler();
	
	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	HPUpdateResult mHPUpdateResult;
};

class MouseAngleUpdateHandler : public NNBaseHandler
{
public:
	MouseAngleUpdateHandler();
	virtual ~MouseAngleUpdateHandler();
	
	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	MouseAngleUpdateRequest mMouseAngleUpdateRequest;
	MouseAngleUpdateResult mMouseAngleUpdateResult;
};

class GameKeyStatesUpdateHandler : public NNBaseHandler
{
public:
	GameKeyStatesUpdateHandler();
	virtual ~GameKeyStatesUpdateHandler();

	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );
	GameKeyStatesUpdateRequest mGameKeyStatesUpdateRequest;
	GameKeyStatesUpdateResult mGameKeyStatesUpdateResult;
};

class LoginHandler : public NNBaseHandler
{
public:
	LoginHandler();
	virtual ~LoginHandler();

	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	LoginRequest mLoginRequestPacket;
	LoginResult mLoginResultPacket;
};

class LoginBroadcastHandler : public NNBaseHandler
{
public:
	LoginBroadcastHandler();
	virtual ~LoginBroadcastHandler();

	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	LoginBroadcastResult mLoginBroadcastResultPacket;
};

class LogoutHandler : public NNBaseHandler
{
public:
	LogoutHandler();
	virtual ~LogoutHandler();

	void HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header );

	LogoutResult mLogoutResultPacket;
};