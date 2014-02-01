
#include "stdafx.h"
#include "PlayerInput.h"

#include "PlayerManager.h"
#include "GameManager.h"
#include "ClientManager.h"
const char* SQL_GetUserInfo = "SELECT nickname FROM tbl_user WHERE id=";
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
	buffer->Read((char*)&inPacket, header->mSize);
	int playerId = inPacket.mPlayerId;
	int gameId = inPacket.mGameId;
	std::wstring playerName;
	int mapType;
	MYSQL_RES *sql_result;
	MYSQL_ROW sql_row;
	int query_stat;
	char query[255] = "";

	// SELECT nickname //
	sprintf_s(query,"SELECT nickname FROM tbl_user WHERE id=%d",playerId);
	query_stat = mysql_query(GMYSQLConnection, query);
	if( query_stat != 0)
	{
		printf( "Mysql query error : %s", mysql_error(GMYSQLConnection));
		return;
	}
	sql_result=mysql_store_result(GMYSQLConnection);
	while((sql_row=mysql_fetch_row(sql_result))!=NULL)
	{
		playerName = std::wstring(s2ws(sql_row[0]));
	}
	mysql_free_result(sql_result);

	// SELECT type //
	sprintf_s(query,"SELECT type FROM tbl_room WHERE id=%d",gameId);
	query_stat = mysql_query(GMYSQLConnection, query);
	if( query_stat != 0)
	{
		printf( "Mysql query error : %s", mysql_error(GMYSQLConnection));
		return;
	}
	sql_result=mysql_store_result(GMYSQLConnection);
	while((sql_row=mysql_fetch_row(sql_result))!=NULL)
	{
		mapType = atoi(sql_row[0]);
	}
	mysql_free_result(sql_result);

	// INSERT newPlayer //
	sprintf_s(query,"INSERT INTO tbl_player (user_id, room_id) values ( %d, %d )",playerId,gameId);
	query_stat = mysql_query(GMYSQLConnection, query);
	if( query_stat != 0)
	{
		printf( "Mysql query error : %s", mysql_error(GMYSQLConnection));
		return;
	}

	if( GGameManager->GetGames()[gameId] == nullptr )
	{
		GGameManager->NewGame(gameId,mapType);
	}
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
	GPlayerManager->GetPlayer(inPacket.mPlayerId)->SetName(playerName);
	outPacket.mMyPlayerInfo = GPlayerManager->GetPlayer(inPacket.mPlayerId)->GetPlayerInfo();

	outPacket.mKillLimit = GGameManager->GetKillLimit(gameId);
	outPacket.mKillScore[0] = GGameManager->GetKillScore(gameId)[0];
	outPacket.mKillScore[1] = GGameManager->GetKillScore(gameId)[1];
	if(!client->Write(&outPacket) )
		return;

	LoginBroadcastResult outPacketBroadCast;
	outPacketBroadCast.mMyPlayerInfo = GPlayerManager->GetPlayer(inPacket.mPlayerId)->GetPlayerInfo();
	if(!client->BroadcastWithoutSelf(&outPacketBroadCast) )
		return;
}