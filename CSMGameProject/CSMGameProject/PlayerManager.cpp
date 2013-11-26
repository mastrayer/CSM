
#include "PlayerManager.h"
#include "PacketType.h"
#include "NNApplication.h"

CPlayerManager::CPlayerManager(void)
	: m_MyPlayerId(-1), m_MyPlayer(nullptr)
{

}


CPlayerManager::~CPlayerManager(void)
{
}

void CPlayerManager::UpdateMyPlayerGameKeyStates(GameKeyStates _gameKeyStates)
{
	UpdatePlayerGameKeyStates(m_MyPlayerId, _gameKeyStates);
}

void CPlayerManager::UpdatePlayerGameKeyStates(int _playerId, GameKeyStates _gameKeyStaets)
{
	std::map<int,CPlayer*>::iterator itor = m_Players.find(_playerId);
	if( itor != m_Players.end() ) 
	{
		CPlayer* player = m_Players.find(_playerId)->second;
		player->SetPlayerGameKeyStates(_gameKeyStaets);
	}
}

void CPlayerManager::UpdatePlayerPosition(int _playerId, NNPoint point)
{
	std::map<int,CPlayer*>::iterator itor = m_Players.find(_playerId);
	if( itor != m_Players.end() ) 
	{
		CPlayer* player = m_Players.find(_playerId)->second;
		player->SetPlayerPosition(point);
	}
}

void CPlayerManager::UpdatePlayerHP(int _playerId, int hp )
{
	std::map<int,CPlayer*>::iterator itor = m_Players.find(_playerId);
	if( itor != m_Players.end() ) 
	{
		CPlayer* player = m_Players.find(_playerId)->second;
		player->SetPlayerHP(hp);
	}
}

void CPlayerManager::UpdatePlayerState(int _playerId, short state )
{
	std::map<int,CPlayer*>::iterator itor = m_Players.find(_playerId);
	if( itor != m_Players.end() ) 
	{
		CPlayer* player = m_Players.find(_playerId)->second;
		player->TransState((PlayerState)state);
	}
}

void CPlayerManager::UpdatePlayerRotation(int _playerId, float angle )
{
	std::map<int,CPlayer*>::iterator itor = m_Players.find(_playerId);
	if( itor != m_Players.end() ) 
	{
		CPlayer* player = m_Players.find(_playerId)->second;
		player->SetPlayerRotation(angle);
	}
}

void CPlayerManager::UpdatePlayerInfo(PlayerInfo info)
{
	UpdatePlayerGameKeyStates(info.m_PlayerId, info.m_GameKeyStates);
	UpdatePlayerPosition(info.m_PlayerId, NNPoint( info.m_X, info.m_Y ) );
	UpdatePlayerRotation(info.m_PlayerId, info.m_Angle);
	UpdatePlayerState(info.m_PlayerId, info.m_PlayerState);
}

void CPlayerManager::SetMyPlayerId(int id)
{
	m_MyPlayerId = id;
	m_MyPlayer = NewPlayer(id);	
}
CPlayer* CPlayerManager::NewPlayer(int id)
{
	CPlayer* newPlayer = NULL;
	std::map<int,CPlayer*>::iterator itor = m_Players.find(id);
	if( itor == m_Players.end() ) 
	{
		newPlayer = new CPlayer();
		m_Players.insert(std::map<int,CPlayer*>::value_type(id,newPlayer));
		NNSceneDirector::GetInstance()->GetNowScene()->AddChild(newPlayer);
	}
	else
		newPlayer = m_Players.find(id)->second;
	return newPlayer;
}
void CPlayerManager::DeletePlayer(int id)
{
	std::map<int,CPlayer*>::iterator itor = m_Players.find(id);
	if( itor != m_Players.end() ) 
	{
		CPlayer* deleteTarget = m_Players.find(id)->second;
		m_Players.erase( m_Players.find(id) );
		NNSceneDirector::GetInstance()->GetNowScene()->RemoveChild(deleteTarget);
	}
}