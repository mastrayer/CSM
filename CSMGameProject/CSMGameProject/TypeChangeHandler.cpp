
#include "PacketHandler.h"
#include <stdio.h>
#include <assert.h>
#include "PlayerManager.h"

TypeChangeHandler::TypeChangeHandler()
{

}
TypeChangeHandler::~TypeChangeHandler()
{

}
void TypeChangeHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	/* 방어 코드 필요 */
	switch ( packetType )
	{
	case PKT_SC_TYPE_CHANGE_A:
		{
			if ( circularBuffer->Read((char*)&mTypeChangeToAResultPacket, header->mSize) )
			{
				CPlayerManager::GetInstance()->UpdatePlayerType( mTypeChangeToAResultPacket.mPlayerId, TYPE_A );
			}
		}
		break;
	case PKT_SC_TYPE_CHANGE_B:
		{
			if ( circularBuffer->Read((char*)&mTypeChangeToBResultPacket, header->mSize) )
			{
				CPlayerManager::GetInstance()->UpdatePlayerType( mTypeChangeToBResultPacket.mPlayerId, TYPE_B );
			}
		}
		break;
	case PKT_SC_TYPE_CHANGE_C:
		{
			if ( circularBuffer->Read((char*)&mTypeChangeToCResultPacket, header->mSize) )
			{
				CPlayerManager::GetInstance()->UpdatePlayerType( mTypeChangeToCResultPacket.mPlayerId, TYPE_C );
			}
		}
		break;
	case PKT_SC_TYPE_CHANGE_D:
		{
			if ( circularBuffer->Read((char*)&mTypeChangeToDResultPacket, header->mSize) )
			{
				// TODO Change Type D
			}
		}
		break;
	}
}
