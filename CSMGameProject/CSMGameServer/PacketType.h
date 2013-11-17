#pragma once
#include <time.h>

#define MAX_CHAT_LEN	1024

#define MAX_NAME_LEN	30
#define MAX_COMMENT_LEN	40

#define MAX_PLAYER_LEN 20

enum PacketTypes
{
	PKT_NONE		= 0,
	PKT_CS_LOGIN	= 1,
	PKT_SC_LOGIN	= 2,
	PKT_SC_LOGIN_BROADCAST	= 3,
	PKT_CS_KEYSTATE = 4,
	PKT_SC_KEYSTATE = 5,
};

enum KeyState
{
	KEY_DOWN,
	KEY_PRESSED,
	KEY_UP,
	KEY_NOTPRESSED,
};
struct GameKeyStates
{
	GameKeyStates()
	{
		upDirectKey = KEY_NOTPRESSED;
		downDirectKey = KEY_NOTPRESSED;
		leftDirectKey = KEY_NOTPRESSED;
		rightDirectKey = KEY_NOTPRESSED;
		attackKey = KEY_NOTPRESSED;
		userActiveSkillKey = KEY_NOTPRESSED;
		typeActiveSkillKey = KEY_NOTPRESSED;
	}
	KeyState upDirectKey;
	KeyState downDirectKey;
	KeyState leftDirectKey;
	KeyState rightDirectKey;
	KeyState attackKey;
	KeyState userActiveSkillKey;
	KeyState typeActiveSkillKey;
};

struct PlayerInfo
{
	float mX, mY;
	int mPlayerId;
	GameKeyStates mGameKeyStates;
};
#pragma pack(push, 1)

struct PacketHeader
{
	PacketHeader() : mSize(0), mType(PKT_NONE) 	{}
	short mSize ;
	short mType ;
} ;


struct LoginRequest : public PacketHeader
{
	LoginRequest()
	{
		mSize = sizeof(LoginRequest);
		mType = PKT_CS_LOGIN;
	}
};
struct LoginResult : public PacketHeader
{
	LoginResult()
	{
		mSize = sizeof(LoginResult);
		mType = PKT_SC_LOGIN;
	}
	PlayerInfo mMyPlayerInfo;
	int mNowPlayersLength;
	PlayerInfo mPlayerInfo[MAX_PLAYER_LEN];
};
struct LoginBroadcastResult : public PacketHeader
{
	LoginBroadcastResult()
	{
		mSize = sizeof(LoginBroadcastResult);
		mType = PKT_SC_LOGIN_BROADCAST;
	}
	PlayerInfo mMyPlayerInfo;
};
struct GameKeyStatesUpdateRequest : public PacketHeader
{
	GameKeyStatesUpdateRequest()
	{
		mSize = sizeof(GameKeyStatesUpdateRequest) ;
		mType = PKT_CS_KEYSTATE ;
		mMyPlayerInfo.mPlayerId = -1 ;
		time_t mTimeStamp = time(NULL);
	}

	PlayerInfo mMyPlayerInfo;
	int mTimeStamp;
} ;

struct GameKeyStatesUpdateResult : public PacketHeader
{
	GameKeyStatesUpdateResult()
	{
		mSize = sizeof(GameKeyStatesUpdateResult) ;
		mType = PKT_SC_KEYSTATE ;
		mMyPlayerInfo.mPlayerId = -1 ;
	}
	PlayerInfo mMyPlayerInfo;
} ;


#pragma pack(pop)