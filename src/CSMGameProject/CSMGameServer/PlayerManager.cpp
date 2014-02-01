
#include "stdafx.h"
#include "PlayerManager.h"
#include <Windows.h>
#include "GameManager.h"

PlayerManager::PlayerManager(void)
{
	memset(mPlayersLength,0,sizeof(mPlayersLength));
	nowTime = prevTime = timeGetTime();
}

PlayerManager::~PlayerManager(void)
{
	for (auto iter=mPlayers.begin(); iter!=mPlayers.end(); iter++ )
	{
		delete iter->second;
	}
	mPlayers.clear();
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

Player* PlayerManager::NewPlayer(int playerId, int gameId, ClientSession* client)
{
	Player* newPlayer = NULL;
	std::map<int,Player*>::iterator itor = mPlayers.find(playerId);
	if( itor == mPlayers.end() ) 
	{
		mPlayersLength[gameId]++;
		newPlayer = new Player(gameId, playerId, client);
		client->mPlayerId = playerId;
		mPlayers.insert(std::map<int,Player*>::value_type(playerId,newPlayer));
	}
	else
		newPlayer = mPlayers.find(playerId)->second;
	return newPlayer;
}
int PlayerManager::GeneratePlayerId()
{
	int id;
	while(1)
	{
		id = rand()%19;
		std::map<int,Player*>::iterator itor = mPlayers.find(id);
		if( itor == mPlayers.end() ) 
		{
			return id;
		}
	}
}

void PlayerManager::DeletePlayer(int playerId)
{
	std::map<int,Player*>::iterator itor = mPlayers.find(playerId);
	if( itor != mPlayers.end() ) 
	{
		mPlayersLength[itor->second->GetGameId()] --;
		//TODO ERRER
		//delete itor->second;
		mPlayers.erase( itor );
	}
}

void PlayerManager::UpdatePlayers()
{
	nowTime = timeGetTime();
	for( std::map<int,Player*>::iterator it = mPlayers.begin(); it != mPlayers.end(); ++it ) 
	{
		it->second->Update((static_cast<float>(nowTime - prevTime))/1000.f);
		if(it == mPlayers.end()) break;
	}
	prevTime = nowTime;
}

void PlayerManager::GetPlayers(int gameId, std::map<int,Player*>* players) 
{ 
	for(auto it = mPlayers.begin(); it != mPlayers.end(); it++) 
		if( it->second->GetGameId() == gameId) 
			players->insert(std::map<int,Player*>::value_type(it->first,it->second));
};

PlayerManager* GPlayerManager = nullptr;