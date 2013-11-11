
#pragma once

#include "NNPacketHeader.h"
#include "NNInputSystem.h"

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

struct KeyStateUpdateRequset : public NNPacketHeader
{
	KeyStateUpdateRequset()
	{
		m_Size = sizeof(KeyStateUpdateRequset) ;
		m_Type = PKT_CS_KEYSTATE ;
		m_PlayerId = -1 ;
		
		m_UpDirectKey = NNInputSystem::GetInstance()->GetUpDirectKeyState();
		m_DownDirectKey = NNInputSystem::GetInstance()->GetDownDirectKeyState();
		m_LeftDirectKey = NNInputSystem::GetInstance()->GetLeftDirectKeyState();
		m_RightDirectKey = NNInputSystem::GetInstance()->GetRightDirectKeyState();
		m_AttackKey = NNInputSystem::GetInstance()->GetAttackKeyState();
		m_UserActiveSkillKey = NNInputSystem::GetInstance()->GetUserActiveSkillKeyState();
		m_TypeActiveSkillKey = NNInputSystem::GetInstance()->GetTypeActiveSkillKeyState();
	}
	
	int	m_PlayerId ;
	int m_UpDirectKey;
	int m_DownDirectKey;
	int m_LeftDirectKey;
	int m_RightDirectKey;
	int m_AttackKey;
	int m_UserActiveSkillKey;
	int m_TypeActiveSkillKey;
} ;

#pragma pack(pop)