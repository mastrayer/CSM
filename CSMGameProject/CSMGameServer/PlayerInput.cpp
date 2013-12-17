
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

	int id = client->mPlayerId = GPlayerManager->GetNewPlayerId();
	GPlayerManager->NewPlayer(id, client);

	/// 로그인은 DB 작업을 거쳐야 하기 때문에 DB 작업 요청한다.
	//LoadPlayerDataContext* newDbJob = new LoadPlayerDataContext(client->mSocket, id);
	//GDatabaseJobManager->PushDatabaseJobRequest(newDbJob) ;

	LoginResult outPacket ;
	outPacket.mMyPlayerInfo = GPlayerManager->GetPlayer(id)->GetPlayerInfo();
	outPacket.mNowPlayersLength = GPlayerManager->GetPlayersLength();
	std::map<int,Player*> players = GPlayerManager->GetPlayers();
	int i=0;
	for( std::map<int,Player*>::iterator it = players.begin(); it != players.end(); ++it ) 
	{
		outPacket.mPlayerInfo[i] = it->second->GetPlayerInfo();
		i++;
	}
	outPacket.mKillLimit = 0;//GGameManager->GetKillLimit();
	outPacket.mKillScore[0] = 0;//GGameManager->GetKillScore()[0];
	outPacket.mKillScore[1] = 0;//GGameManager->GetKillScore()[1];
	if(!client->Send(&outPacket) )
		return;

	LoginBroadcastResult outPacketBroadCast;
	outPacketBroadCast.mMyPlayerInfo = GPlayerManager->GetPlayer(id)->GetPlayerInfo();
	if(!client->BroadcastWithoutSelf(&outPacketBroadCast) )
		return;
}