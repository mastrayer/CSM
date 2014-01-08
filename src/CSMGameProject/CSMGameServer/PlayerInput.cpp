
#include "stdafx.h"
#include "PlayerInput.h"

#include "PlayerManager.h"
#include "DatabaseJobManager.h"
#include "DatabaseJobContext.h"
#include "GameManager.h"
#include "ItemManager.h"
#include "SQLStatement.h"
#include "DbHelper.h"
const char* SQL_GetUserInfo = "SELECT nickname FROM tbl_user WHERE id=?";
const char* SQL_GetRoomInfo = "SELECT type FROM tbl_room WHERE id=?";
const char* SQL_RemoveRoom = "DELETE FROM tbl_room WHERE id=(data)";
const char* SQL_NewPlayer = "INSERT INTO tbl_player (user_id, room_id) values ( ?, ? )";
const char* SQL_DeletePlayer = "DELETE FROM tbl_player WHERE id=?";
std::wstring s2ws(const std::string& str)
{
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo( size_needed, 0 );
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}
void ClientLoginPacket( ClientSession* client, PacketHeader* header, CircularBuffer* buffer )
{
	LoginRequest inPacket ;
	buffer->Read((char*)&inPacket, header->mSize) ;
	int gameId = inPacket.mGameId;

	DbHelper dbhelperUserInfo(SQL_GetUserInfo) ; // TODO 
	dbhelperUserInfo.BindParamInt(inPacket.mPlayerId);
	/// 데이터가 없네?
	if ( RESULT_ROW != dbhelperUserInfo.FetchRow() )
	{
		printf("wrong!");
		return;
	}
	
	const unsigned char* name = dbhelperUserInfo.GetResultParamText() ;
	std::wstring playerName = std::wstring(s2ws((char*)name));

	DbHelper dbhelperRoomInfo(SQL_GetRoomInfo) ; // TODO 
	dbhelperRoomInfo.BindParamInt(inPacket.mPlayerId);
	/// 데이터가 없네?
	if ( RESULT_ROW != dbhelperRoomInfo.FetchRow() )
	{
		printf("wrong!");
		return;
	}

	int mapType = dbhelperRoomInfo.GetResultParamInt();

	if( GGameManager->GetGames()[gameId] == nullptr )
	{
		//TODO
		GGameManager->NewGame(gameId,mapType);
	}
	DbHelper dbhelperNewPlayer(SQL_NewPlayer) ; // TODO 
	dbhelperNewPlayer.BindParamInt(inPacket.mPlayerId);
	dbhelperNewPlayer.BindParamInt(inPacket.mGameId);
	/// 데이터가 없네?
	if ( RESULT_ROW != dbhelperNewPlayer.FetchRow() )
	{
		printf("wrong!");
		return;
	}


	/// 로그인은 DB 작업을 거쳐야 하기 때문에 DB 작업 요청한다.
	//LoadPlayerDataContext* newDbJob = new LoadPlayerDataContext(client->mSocket, id);
	//GDatabaseJobManager->PushDatabaseJobRequest(newDbJob) ;

	LoginResult outPacket ;
	outPacket.mNowPlayersLength = GPlayerManager->GetPlayersLength(gameId);
	std::map<int,Player*> players;
	GPlayerManager->GetPlayers(gameId,&players);
	int i=0;
	for( std::map<int,Player*>::iterator it = players.begin(); it != players.end(); ++it ) 
	{
		outPacket.mPlayerInfo[i] = it->second->GetPlayerInfo();
		i++;
	}
	GPlayerManager->NewPlayer(inPacket.mPlayerId, gameId, client);
	GPlayerManager->SetPlayerName(inPacket.mPlayerId, playerName);
	outPacket.mMyPlayerInfo = GPlayerManager->GetPlayer(inPacket.mPlayerId)->GetPlayerInfo();

	outPacket.mKillLimit = GGameManager->GetKillLimit(gameId);
	outPacket.mKillScore[0] = GGameManager->GetKillScore(gameId)[0];
	outPacket.mKillScore[1] = GGameManager->GetKillScore(gameId)[1];
	if(!client->Write(&outPacket) )
		return;
	std::list<Item*>items;
	GItemManager->GetItems(gameId,&items);
	for(auto it = items.begin(); it != items.end(); it++)
	{
		if( (*it)->IsConsumed() == true)
		{
			ItemPlayerConsumeResult outPacket = ItemPlayerConsumeResult();
			outPacket.mItemType = (*it)->GetItemType();
			outPacket.mPlayerId = (*it)->GetOwnerId();
			outPacket.mItemId = (*it)->GetItemId();
			outPacket.mLifeTime = (*it)->GetLifeTime();
			client->Write(&outPacket);
		}
		else
		{
			ItemComeResult outPacket = ItemComeResult();
			outPacket.mItemType = (*it)->GetItemType();
			outPacket.mPosition = (*it)->GetPosition();
			outPacket.mItemId = (*it)->GetItemId();
			outPacket.mLifeTime = (*it)->GetLifeTime();
			client->Write(&outPacket);
		}
	}

	LoginBroadcastResult outPacketBroadCast;
	outPacketBroadCast.mMyPlayerInfo = GPlayerManager->GetPlayer(inPacket.mPlayerId)->GetPlayerInfo();
	if(!client->BroadcastWithoutSelf(&outPacketBroadCast) )
		return;
}