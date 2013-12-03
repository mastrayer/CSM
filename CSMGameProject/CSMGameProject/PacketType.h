
#pragma once

#include "NNPacketHeader.h"
#include "NNPoint.h"
#define MAX_CHAT_LEN	1024

#define MAX_NAME_LEN	30
#define MAX_COMMENT_LEN	40
#define MAX_PLAYER_LEN 20

#define KEYSTATE_NOTPRESSED 0
#define KEYSTATE_PRESSED 1

#define PKT_NONE 0
#define PKT_CS_LOGIN 1
#define PKT_SC_LOGIN 2
#define PKT_SC_LOGIN_BROADCAST 3
#define PKT_CS_KEYSTATE 4
#define PKT_SC_KEYSTATE 5
#define PKT_SC_LOGOUT 6
#define PKT_CS_MOUSEANGLE 7
#define PKT_SC_MOUSEANGLE 8
#define PKT_SC_HP 9
struct GameKeyStates
{
	GameKeyStates()
	{
		upDirectKey = KEYSTATE_NOTPRESSED;
		downDirectKey = KEYSTATE_NOTPRESSED;
		leftDirectKey = KEYSTATE_NOTPRESSED;
		rightDirectKey = KEYSTATE_NOTPRESSED;
		attackKey = KEYSTATE_NOTPRESSED;
		userActiveSkillKey = KEYSTATE_NOTPRESSED;
		typeActiveSkillKey = KEYSTATE_NOTPRESSED;
	}
	short upDirectKey;
	short downDirectKey;
	short leftDirectKey;	
	short rightDirectKey;
	short attackKey;
	short userActiveSkillKey;
	short typeActiveSkillKey;
};
struct PlayerInfo
{
	float m_X, m_Y, m_Angle;
	int m_PlayerId;
	GameKeyStates m_GameKeyStates;
	short m_PlayerState;
	int m_HP;
	NNPoint m_MoveDirection;
};
#pragma pack(push,1)

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
	}

	PlayerInfo m_MyPlayerInfo;
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

struct MouseAngleUpdateRequest : public NNPacketHeader
{
	MouseAngleUpdateRequest()
	{
		m_Size = sizeof(MouseAngleUpdateRequest);
		m_Type = PKT_CS_MOUSEANGLE;
	}
	int m_PlayerId;
	float m_Angle;
};

struct MouseAngleUpdateResult : public NNPacketHeader
{
	MouseAngleUpdateResult()
	{
		m_Size = sizeof(MouseAngleUpdateResult);
		m_Type = PKT_SC_MOUSEANGLE;
	}
	int m_PlayerId;
	float m_Angle;
};
struct HPUpdateResult : public NNPacketHeader
{
	HPUpdateResult()
	{
		m_Size = sizeof(HPUpdateResult);
		m_Type = PKT_SC_HP;
	}
	int m_PlayerId;
	int m_HP;
};
#pragma pack(pop)