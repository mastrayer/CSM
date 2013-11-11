
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
		
		m_UpDirectKeyState = NNInputSystem::GetInstance()->GetUpDirectKeyState();
		m_DownDirectKeyState = NNInputSystem::GetInstance()->GetDownDirectKeyState();
		m_LeftDirectKeyState = NNInputSystem::GetInstance()->GetLeftDirectKeyState();
		m_RightDirectKeyState = NNInputSystem::GetInstance()->GetRightDirectKeyState();
		m_AttackKeyState = NNInputSystem::GetInstance()->GetAttackKeyState();
		m_UserActiveSkillKeyState = NNInputSystem::GetInstance()->GetUserActiveSkillKeyState();
		m_TypeActiveSkillKeyState = NNInputSystem::GetInstance()->GetTypeActiveSkillKeyState();
	}
	
	int m_PlayerId ;
	KeyState m_UpDirectKeyState;
	KeyState m_DownDirectKeyState;
	KeyState m_LeftDirectKeyState;
	KeyState m_RightDirectKeyState;
	KeyState m_AttackKeyState;
	KeyState m_UserActiveSkillKeyState;
	KeyState m_TypeActiveSkillKeyState;
} ;

#pragma pack(pop)