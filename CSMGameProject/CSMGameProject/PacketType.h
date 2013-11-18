
#pragma once

#include "NNPacketHeader.h"
#include "NNInputSystem.h"

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
	PKT_SC_LOGOUT	= 6,
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
	float m_X, m_Y;
	int m_PlayerId;
	GameKeyStates m_GameKeyStates;
};
#pragma pack(push,1)
/*
struct ChatBroadcastRequest : public NNPacketHeader
{
	ChatBroadcastRequest()
	{
		m_Size = sizeof(ChatBroadcastRequest) ;
		m_Type = PKT_CS_CHAT ;
		m_PlayerId = -1 ;
	
		memset(m_Chat, 0, MAX_CHAT_LEN) ;
	}

	int	m_PlayerId ;
	char m_Chat[MAX_CHAT_LEN] ;
} ;

struct ChatBroadcastResult : public NNPacketHeader
{
	ChatBroadcastResult()
	{
		m_Size = sizeof(ChatBroadcastResult) ;
		m_Type = PKT_SC_CHAT ;
		m_PlayerId = -1 ;
		
		memset(m_Name, 0, MAX_NAME_LEN) ;
		memset(m_Chat, 0, MAX_CHAT_LEN) ;
	}
	
	int	m_PlayerId ;
	char m_Name[MAX_NAME_LEN] ;
	char m_Chat[MAX_CHAT_LEN] ;
} ;
*/
struct LoginRequest : public NNPacketHeader
{
	LoginRequest()
	{
		m_Size = sizeof(LoginRequest);
		m_Type = PKT_CS_LOGIN;
	}
};
struct LoginResult : public NNPacketHeader
{
	LoginResult()
	{
		m_Size = sizeof(LoginResult);
		m_Type = PKT_SC_LOGIN;
	}
	PlayerInfo m_MyPlayerInfo;
	int m_NowPlayersLength;
	PlayerInfo m_PlayerInfo[MAX_PLAYER_LEN];
};
struct LoginBroadcastResult : public NNPacketHeader
{
	LoginBroadcastResult()
	{
		m_Size = sizeof(LoginBroadcastResult);
		m_Type = PKT_SC_LOGIN_BROADCAST;
	}
	PlayerInfo m_MyPlayerInfo;
};
struct GameKeyStatesUpdateRequest : public NNPacketHeader
{
	GameKeyStatesUpdateRequest()
	{
		m_Size = sizeof(GameKeyStatesUpdateRequest) ;
		m_Type = PKT_CS_KEYSTATE ;
		m_MyPlayerInfo.m_PlayerId = -1 ;
		time_t m_TimeStamp = time(NULL);
	}
	
	PlayerInfo m_MyPlayerInfo;
	int m_TimeStamp;
} ;

struct GameKeyStatesUpdateResult : public NNPacketHeader
{
	GameKeyStatesUpdateResult()
	{
		m_Size = sizeof(GameKeyStatesUpdateResult) ;
		m_Type = PKT_SC_KEYSTATE ;
		m_MyPlayerInfo.m_PlayerId = -1 ;
	}
	PlayerInfo m_MyPlayerInfo;
} ;

struct LogoutResult : public NNPacketHeader
{
	LogoutResult()
	{
		m_Size = sizeof(LogoutResult);
		m_Type = PKT_SC_LOGOUT;
	}
	int m_PlayerId;
};

#pragma pack(pop)