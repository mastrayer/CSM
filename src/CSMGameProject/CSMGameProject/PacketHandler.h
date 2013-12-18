
#pragma once

#include "NNBaseHandler.h"
#include "NNCircularBuffer.h"
#include "PacketType.h"
class ATypeAttackShootHandler : public NNBaseHandler
{
public:
	ATypeAttackShootHandler();
	virtual ~ATypeAttackShootHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	ATypeAttackShootResult mATypeAttackShootResult;
};
class ATypeAttackEndHandler : public NNBaseHandler
{
public:
	ATypeAttackEndHandler();
	virtual ~ATypeAttackEndHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	ATypeAttackEndResult mATypeAttackEndResult;
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
class BTypeAttackShootHandler : public NNBaseHandler
{
public:
	BTypeAttackShootHandler();
	virtual ~BTypeAttackShootHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	BTypeAttackShootResult mBTypeAttackShootResult;
};
class BTypeAttackEndHandler : public NNBaseHandler
{
public:
	BTypeAttackEndHandler();
	virtual ~BTypeAttackEndHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	BTypeAttackEndResult mBTypeAttackEndResult;
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

