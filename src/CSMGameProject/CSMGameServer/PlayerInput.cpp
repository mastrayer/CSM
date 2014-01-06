
#include "stdafx.h"
#include "PlayerInput.h"

#include "PlayerManager.h"
#include "DatabaseJobManager.h"
#include "DatabaseJobContext.h"
#include "GameManager.h"

void ClientLoginPacket( ClientSession* client, PacketHeader* header, CircularBuffer* buffer )
{
	LoginRequest inPacket ;
	buffer->Read((char*)&inPacket, header->mSize) ;

	if( GGameManager->GetGames()[inPacket.mGameId] == nullptr )
	{
		//TODO
	}


	GPlayerManager->NewPlayer(inPacket.mPlayerId, inPacket.mGameId, client);

	/// 로그인은 DB 작업을 거쳐야 하기 때문에 DB 작업 요청한다.
	//LoadPlayerDataContext* newDbJob = new LoadPlayerDataContext(client->mSocket, id);
	//GDatabaseJobManager->PushDatabaseJobRequest(newDbJob) ;

	LoginResult outPacket ;
	outPacket.mMyPlayerInfo = GPlayerManager->GetPlayer(inPacket.mPlayerId)->GetPlayerInfo();
	outPacket.mNowPlayersLength = GPlayerManager->GetPlayersLength();
	std::map<int,Player*> players;
	GPlayerManager->GetPlayers(inPacket.mGameId,&players);
	int i=0;
	for( std::map<int,Player*>::iterator it = players.begin(); it != players.end(); ++it ) 
	{
		outPacket.mPlayerInfo[i] = it->second->GetPlayerInfo();
		i++;
	}
	outPacket.mKillLimit = GGameManager->GetKillLimit(inPacket.mGameId);
	outPacket.mKillScore[0] = GGameManager->GetKillScore(inPacket.mGameId)[0];
	outPacket.mKillScore[1] = GGameManager->GetKillScore(inPacket.mGameId)[1];
	if(!client->Write(&outPacket) )
		return;

	LoginBroadcastResult outPacketBroadCast;
	outPacketBroadCast.mMyPlayerInfo = GPlayerManager->GetPlayer(inPacket.mPlayerId)->GetPlayerInfo();
	if(!client->BroadcastWithoutSelf(&outPacketBroadCast) )
		return;
}