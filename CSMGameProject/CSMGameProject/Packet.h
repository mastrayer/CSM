
#pragma once

#include "NNPacketHeader.h"

#define MAX_CHAT_LEN	1024

#define MAX_NAME_LEN	30
#define MAX_COMMENT_LEN	40

enum PacketTypes
{
	PKT_CS_CHAT		= 3,
	PKT_SC_CHAT		= 4,
	PKT_CS_KEYSTATE = 5,
};

#pragma pack(push,1)

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

struct KeyStateUpdateResult : public NNPacketHeader
{
	KeyStateUpdateResult()
	{
		m_Size = sizeof(KeyStateUpdateResult) ;
		m_Type = PKT_CS_KEYSTATE ;
		m_PlayerId = -1 ;
		
		memset(m_Name, 0, MAX_NAME_LEN) ;
		memset(m_Chat, 0, MAX_CHAT_LEN) ;
	}
	
	int	m_PlayerId ;
	char m_Name[MAX_NAME_LEN] ;
	char m_Chat[MAX_CHAT_LEN] ;
} ;

#pragma pack(pop)