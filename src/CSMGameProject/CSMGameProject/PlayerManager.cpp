
#include "PlayerManager.h"
#include "PacketType.h"
#include "NNApplication.h"

CPlayerManager* CPlayerManager::m_Instance = nullptr;

CPlayerManager::CPlayerManager(void)
	: mMyPlayerId(-1), mMyPlayer(nullptr)
{
}


CPlayerManager::~CPlayerManager(void)
{
}

CPlayerManager* CPlayerManager::GetInstance()
{
	if (m_Instance == nullptr)
		m_Instance = new CPlayerManager();
	return m_Instance;
}
void CPlayerManager::ReleaseInstance()
{
	if (m_Instance != nullptr)
		delete m_Instance;
}

void CPlayerManager::UpdatePlayerMoveDirection(int _playerId, NNPoint direction)
{
	std::map<int,CPlayer*>::iterator itor = mPlayers.find(_playerId);
	if( itor != mPlayers.end() ) 
	{
		CPlayer* player = mPlayers.find(_playerId)->second;
		player->SetPlayerMoveDirection(direction);
	}
}
void CPlayerManager::UpdatePlayerPosition(int _playerId, NNPoint point)
{
	std::map<int,CPlayer*>::iterator itor = mPlayers.find(_playerId);
	if( itor != mPlayers.end() ) 
	{
		CPlayer* player = mPlayers.find(_playerId)->second;
		player->SetPlayerPosition(point);
	}
}

void CPlayerManager::UpdatePlayerHP(int _playerId, int hp )
{
	std::map<int,CPlayer*>::iterator itor = mPlayers.find(_playerId);
	if( itor != mPlayers.end() ) 
	{
		CPlayer* player = mPlayers.find(_playerId)->second;
		player->SetPlayerHP(hp);
	}
}

void CPlayerManager::UpdatePlayerState(int _playerId, short state )
{
	std::map<int,CPlayer*>::iterator itor = mPlayers.find(_playerId);
	if( itor != mPlayers.end() ) 
	{
		CPlayer* player = mPlayers.find(_playerId)->second;
		player->TransState((PlayerState)state);
	}
}

void CPlayerManager::UpdatePlayerRotation(int _playerId, float angle )
{
	std::map<int,CPlayer*>::iterator itor = mPlayers.find(_playerId);
	if( itor != mPlayers.end() ) 
	{
		CPlayer* player = mPlayers.find(_playerId)->second;
		player->SetPlayerRotation(angle);
	}
}

void CPlayerManager::UpdatePlayerTeam(int _playerId, int team)
{
	std::map<int,CPlayer*>::iterator itor = mPlayers.find(_playerId);
	if( itor != mPlayers.end() ) 
	{
		CPlayer* player = mPlayers.find(_playerId)->second;
		player->SetPlayerTeam(team);
	}
}
/*
void CPlayerManager::UpdatePlayerType(int _playerId, int type)
{
	std::map<int,CPlayer*>::iterator itor = mPlayers.find(_playerId);
	if( itor != mPlayers.end() ) 
	{
		CPlayer* player = mPlayers.find(_playerId)->second;
		player->SetPlayerType((PlayerType)type);
	}
}*/
void CPlayerManager::UpdatePlayerKillScore( int playerId, int killScore )
{
	std::map<int,CPlayer*>::iterator itor = mPlayers.find(playerId);
	if( itor != mPlayers.end() ) 
	{
		CPlayer* player = mPlayers.find(playerId)->second;
		player->SetKillScore( killScore );
	}
}
void CPlayerManager::UpdatePlayerType( int playerId, PlayerType type )
{
	std::map<int,CPlayer*>::iterator itor = mPlayers.find(playerId);
	if( itor != mPlayers.end() ) 
	{
		CPlayer* player = mPlayers.find(playerId)->second;
		player->SetPlayerType( type );
	}
}
void CPlayerManager::UpdatePlayerInfo(PlayerInfo info)
{
	UpdatePlayerState(info.mPlayerId, info.mPlayerState);
	UpdatePlayerPosition(info.mPlayerId, NNPoint( info.mX, info.mY ) );
	UpdatePlayerRotation(info.mPlayerId, info.mAngle);
	UpdatePlayerMoveDirection(info.mPlayerId, info.mMoveVelocity);
	UpdatePlayerHP(info.mPlayerId, info.mHP);
	UpdatePlayerTeam(info.mPlayerId, info.mTeam);
	UpdatePlayerType(info.mPlayerId, (PlayerType)info.mType);
	UpdatePlayerKillScore( info.mPlayerId, info.mKillScore );
}

void CPlayerManager::SetMyPlayerId(int id)
{
	mMyPlayerId = id;
	mMyPlayer = NewPlayer(id);	
}
CPlayer* CPlayerManager::NewPlayer(int id)
{ 
	CPlayer* newPlayer = NULL;
	std::map<int,CPlayer*>::iterator itor = mPlayers.find(id);
	if( itor == mPlayers.end() ) 
	{
		newPlayer = CPlayer::Create();//new CPlayer();
		mPlayers.insert(std::map<int,CPlayer*>::value_type(id,newPlayer));
		NNSceneDirector::GetInstance()->GetNowScene()->AddChild(newPlayer, 0);
	}
	else
		newPlayer = mPlayers.find(id)->second;
	return newPlayer;
}
void CPlayerManager::DeletePlayer(int id)
{
	std::map<int,CPlayer*>::iterator itor = mPlayers.find(id);
	if( itor != mPlayers.end() ) 
	{
		CPlayer* deleteTarget = mPlayers.find(id)->second;
		mPlayers.erase( mPlayers.find(id) );
		NNSceneDirector::GetInstance()->GetNowScene()->RemoveChild(deleteTarget);
	}
}