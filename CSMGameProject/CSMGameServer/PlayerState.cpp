
#include "stdafx.h"
#include "PlayerState.h"
#include "PlayerManager.h"

void PlayerTypeChangeA( ClientSession* client, PacketHeader* header, CircularBuffer* buffer )
{
	TypeChangeToARequest inPacket ;
	buffer->Read((char*)&inPacket, header->mSize);

	Player* _player = GPlayerManager->GetPlayer(inPacket.mPlayerId);
	_player->ChangeType( TYPE_A );
	/*
	TypeChangeToAResult outPacket;
	outPacket.mPlayerId = inPacket.mPlayerId;
	
	if( !client->Broadcast(&outPacket) )
		return;
	*/
}
void PlayerTypeChangeB( ClientSession* client, PacketHeader* header, CircularBuffer* buffer )
{
	TypeChangeToBRequest inPacket ;
	buffer->Read((char*)&inPacket, header->mSize);

	Player* _player = GPlayerManager->GetPlayer(inPacket.mPlayerId);
	_player->ChangeType( TYPE_B );
	/*
	TypeChangeToBResult outPacket;
	outPacket.mPlayerId = inPacket.mPlayerId;

	if( !client->Broadcast(&outPacket) )
		return;
	*/
}
void PlayerTypeChangeC( ClientSession* client, PacketHeader* header, CircularBuffer* buffer )
{
	TypeChangeToCRequest inPacket ;
	buffer->Read((char*)&inPacket, header->mSize);

	Player* _player = GPlayerManager->GetPlayer(inPacket.mPlayerId);
	_player->ChangeType( TYPE_C );
	/*
	TypeChangeToCResult outPacket;
	outPacket.mPlayerId = inPacket.mPlayerId;

	if( !client->Broadcast(&outPacket) )
		return;
	*/
}
void PlayerTypeChangeD( ClientSession* client, PacketHeader* header, CircularBuffer* buffer )
{
	TypeChangeToDRequest inPacket ;
	buffer->Read((char*)&inPacket, header->mSize);

	Player* _player = GPlayerManager->GetPlayer(inPacket.mPlayerId);
	_player->ChangeType( TYPE_D );
	/*
	TypeChangeToDResult outPacket;
	outPacket.mPlayerId = inPacket.mPlayerId;

	if( !client->Broadcast(&outPacket) )
		return;
		*/
}