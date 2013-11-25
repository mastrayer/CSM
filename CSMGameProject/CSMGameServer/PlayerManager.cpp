
#include "stdafx.h"
#include "PlayerManager.h"
#include <Windows.h>

PlayerManager::PlayerManager(void):mPlayersLength(0)
{
	nowTime = prevTime = timeGetTime();
}

PlayerManager::~PlayerManager(void)
{

}

void PlayerManager::UpdatePlayerGameKeyStates(int _playerId, GameKeyStates _gameKeyStaets)
{
	std::map<int,Player*>::iterator itor = mPlayers.find(_playerId);
	if( itor != mPlayers.end() ) 
	{
		Player* player = mPlayers.find(_playerId)->second;
		player->SetGameKeyStates(_gameKeyStaets);
	}
}

void PlayerManager::UpdatePlayerPosition(int _playerId, Point point)
{
	std::map<int,Player*>::iterator itor = mPlayers.find(_playerId);
	if( itor != mPlayers.end() ) 
	{
		Player* player = mPlayers.find(_playerId)->second;
		player->SetPosition(point);
	}
}

void PlayerManager::UpdatePlayerRotation(int _playerId, float angle)
{
	
	std::map<int,Player*>::iterator itor = mPlayers.find(_playerId);
	if( itor != mPlayers.end() ) 
	{
		Player* player = mPlayers.find(_playerId)->second;
		player->SetRotation(angle);
	}
}

Player* PlayerManager::NewPlayer(int id)
{
	Player* newPlayer = NULL;
	std::map<int,Player*>::iterator itor = mPlayers.find(id);
	if( itor == mPlayers.end() ) 
	{
		mPlayersLength++;
		newPlayer = new Player(id);
		mPlayers.insert(std::map<int,Player*>::value_type(id,newPlayer));
	}
	else
		newPlayer = mPlayers.find(id)->second;
	return newPlayer;
}

void PlayerManager::DeletePlayer(int id)
{
	std::map<int,Player*>::iterator itor = mPlayers.find(id);
	if( itor != mPlayers.end() ) 
	{
		mPlayersLength--;
		Player* deleteTarget = mPlayers.find(id)->second;
		mPlayers.erase( mPlayers.find(id) );
	}
}

int PlayerManager::GetNewPlayerId()
{
	for(int id=0; id<20; id++)
	{
		std::map<int,Player*>::iterator itor = mPlayers.find(id);
		if( itor == mPlayers.end() ) 
		{
			return id;	
		}
	}
	return -1;
}

void PlayerManager::UpdatePlayers()
{
	nowTime = timeGetTime();
	std::map<int,Player*> players = GPlayerManager->GetPlayers();
	for( std::map<int,Player*>::iterator it = players.begin(); it != players.end(); ++it ) 
	{
		it->second->Update((static_cast<float>(nowTime - prevTime))/1000.f);
	}
	prevTime = nowTime;
}

PlayerManager* GPlayerManager = nullptr;