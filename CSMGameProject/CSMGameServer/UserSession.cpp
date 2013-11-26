
#include "stdafx.h"
#include "UserSession.h"

#include "PlayerManager.h"

void ClientKeyStatePacket( ClientSession* client, PacketHeader* header, CircularBuffer* buffer )
{
	GameKeyStatesUpdateRequest inPacket ;
	buffer->Read((char*)&inPacket, header->mSize);

	Player* _player = GPlayerManager->GetPlayer(inPacket.mMyPlayerInfo.mPlayerId);
	_player->SetGameKeyStates(inPacket.mMyPlayerInfo.mGameKeyStates);
	//_player->SetPosition(Point(inPacket.mMyPlayerInfo.mX, inPacket.mMyPlayerInfo.mY));
	_player->SetRotation(inPacket.mMyPlayerInfo.mAngle);
	GameKeyStatesUpdateResult outPacket = GameKeyStatesUpdateResult();
	outPacket.mMyPlayerInfo = _player->GetPlayerInfo();

	if( !client->Broadcast(&outPacket) )
		return;
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