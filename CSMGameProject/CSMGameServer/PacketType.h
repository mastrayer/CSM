#pragma once

#define MAX_CHAT_LEN	1024

#define MAX_NAME_LEN	30
#define MAX_COMMENT_LEN	40

enum PacketTypes
{
	PKT_NONE	= 0,
	
	PKT_CS_LOGIN	= 1,
	PKT_SC_LOGIN	= 2,
	
	PKT_CS_CHAT		= 3,
	PKT_SC_CHAT		= 4,
	
	PKT_CS_KEYSTATE = 5,
	PKT_SC_KEYSTATE = 6,
	
} ;
enum KeyState
{
	KEY_DOWN,
	KEY_PRESSED,
	KEY_UP,
	KEY_NOTPRESSED,
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
		mSize = sizeof(LoginRequest) ;
		mType = PKT_CS_LOGIN ;
		mPlayerId = -1 ;
	}

	int	mPlayerId ;
} ;

struct LoginResult : public PacketHeader
{
	LoginResult()
	{
		mSize = sizeof(LoginResult) ;
		mType = PKT_SC_LOGIN ;
		mPlayerId = -1 ;
		memset(mName, 0, MAX_NAME_LEN) ;
	}

	int		mPlayerId ;
	double	mPosX ;
	double	mPosY ;
	double	mPosZ ;
	char	mName[MAX_NAME_LEN] ;

} ;

struct ChatBroadcastRequest : public PacketHeader
{
	ChatBroadcastRequest()
	{
		mSize = sizeof(ChatBroadcastRequest) ;
		mType = PKT_CS_CHAT ;
		mPlayerId = -1 ;
	
		memset(mChat, 0, MAX_CHAT_LEN) ;
	}

	int	mPlayerId ;
	char mChat[MAX_CHAT_LEN] ;
} ;

struct ChatBroadcastResult : public PacketHeader
{
	ChatBroadcastResult()
	{
		mSize = sizeof(ChatBroadcastResult) ;
		mType = PKT_SC_CHAT ;
		mPlayerId = -1 ;
		
		memset(mName, 0, MAX_NAME_LEN) ;
		memset(mChat, 0, MAX_CHAT_LEN) ;
	}
	
	int	mPlayerId ;
	char mName[MAX_NAME_LEN] ;
	char mChat[MAX_CHAT_LEN] ;
} ;

struct KeyStateUpdateRequset : public PacketHeader
{
	KeyStateUpdateRequset()
	{
		mSize = sizeof(KeyStateUpdateRequset) ;
		mType = PKT_CS_KEYSTATE ;
		mPlayerId = -1 ;
	}
	
	int	mPlayerId ;
	KeyState mUpDirectKeyState;
	KeyState mDownDirectKeyState;
	KeyState mLeftDirectKeyState;
	KeyState mRightDirectKeyState;
	KeyState mAttackKeyState;
	KeyState mUserActiveSkillKeyState;
	KeyState mTypeActiveSkillKeyState;
} ;

struct KeyStateUpdateResult : public PacketHeader
{
	KeyStateUpdateResult()
	{
		mSize = sizeof(KeyStateUpdateResult) ;
		mType = PKT_SC_KEYSTATE ;
		mPlayerId = -1 ;
	}
	
	int mPlayerId ;
} ;

#pragma pack(pop)