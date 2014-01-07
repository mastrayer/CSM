
#pragma once

#include "NNBaseHandler.h"
#include "NNCircularBuffer.h"
#include "PacketType.h"

	
	
class UserSkillFlashHandler : public NNBaseHandler
{
public:
	UserSkillFlashHandler();
	virtual ~UserSkillFlashHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	UserSkillFlashResult mUserSkillFlashResult;
};

class ItemComeHandler : public NNBaseHandler
{
public:
	ItemComeHandler();
	virtual ~ItemComeHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	ItemComeResult mItemComeResult;
};

class ItemPlayerConsumeHandler : public NNBaseHandler
{
public:
	ItemPlayerConsumeHandler();
	virtual ~ItemPlayerConsumeHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	ItemPlayerConsumeResult mItemPlayerConsumeResult;
};

class ItemPlayerDropHandler : public NNBaseHandler
{
public:
	ItemPlayerDropHandler();
	virtual ~ItemPlayerDropHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	ItemPlayerDropResult mItemPlayerDropResult;
};
class EmoticonHandler : public NNBaseHandler
{
public:
	EmoticonHandler();
	virtual ~EmoticonHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	EmoticonResult mEmoticonResult;
};
class CTypeAttackShootHandler : public NNBaseHandler
{
public:
	CTypeAttackShootHandler();
	virtual ~CTypeAttackShootHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	CTypeAttackShootResult mCTypeAttackShootResult;
};
class CTypeAttackEndHandler : public NNBaseHandler
{
public:
	CTypeAttackEndHandler();
	virtual ~CTypeAttackEndHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	CTypeAttackEndResult mCTypeAttackEndResult;
};
class CTypeSkillShootHandler : public NNBaseHandler
{
public:
	CTypeSkillShootHandler();
	virtual ~CTypeSkillShootHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	CTypeSkillShootResult mCTypeSkillShootResult;
};
class DTypeAttackShootHandler : public NNBaseHandler
{
public:
	DTypeAttackShootHandler();
	virtual ~DTypeAttackShootHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	DTypeAttackShootResult mDTypeAttackShootResult;
};
class DTypeSkillShootHandler : public NNBaseHandler
{
public:
	DTypeSkillShootHandler();
	virtual ~DTypeSkillShootHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	DTypeSkillShootResult mDTypeSkillShootResult;
};
class DTypeSkillEndHandler : public NNBaseHandler
{
public:
	DTypeSkillEndHandler();
	virtual ~DTypeSkillEndHandler();

	void HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header);

	DTypeSkillEndResult mDTypeSkillEndResult;
};
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

