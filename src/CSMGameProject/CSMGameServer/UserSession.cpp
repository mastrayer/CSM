
#include "stdafx.h"
#include "UserSession.h"

#include "PlayerManager.h"

void ClientKeyStatePacket( ClientSession* client, PacketHeader* header, CircularBuffer* buffer )
{
	GameKeyStatesUpdateRequest inPacket ;
	buffer->Read((char*)&inPacket, header->mSize);
	if(inPacket.mMyPlayerInfo.mGameKeyStates.leftDirectKey == KEYSTATE_PRESSED && inPacket.mMyPlayerInfo.mGameKeyStates.rightDirectKey == KEYSTATE_PRESSED)
	{
		printf("ok");
	}
	Player* _player = GPlayerManager->GetPlayer(inPacket.mMyPlayerInfo.mPlayerId);
	_player->SetGameKeyStates(inPacket.mMyPlayerInfo.mGameKeyStates);
	_player->SetRotation(inPacket.mMyPlayerInfo.mAngle);
}

void ClientMouseAnglePacket( ClientSession* client, PacketHeader* header, CircularBuffer* buffer )
{
	MouseAngleUpdateRequest inPacket ;
	buffer->Read((char*)&inPacket, header->mSize);

	Player* _player = GPlayerManager->GetPlayer(inPacket.mPlayerId);
	_player->SetRotation(inPacket.mAngle);
	MouseAngleUpdateResult outPacket = MouseAngleUpdateResult();
	outPacket.mPlayerId = inPacket.mPlayerId;
	outPacket.mAngle = inPacket.mAngle;

	if( !client->Broadcast(&outPacket) )
		return;
}

void EmoticonPacket( ClientSession* client, PacketHeader* header, CircularBuffer* buffer )
{
	EmoticonRequest inPacket;
	buffer->Read((char*)&inPacket, header->mSize);

	EmoticonResult outPacket = EmoticonResult();
	outPacket.mEmoticonNumber = inPacket.mEmoticonNumber;
	outPacket.mPlayerId = inPacket.mPlayerId;

	client->BroadcastWithoutSelf(&outPacket);
}