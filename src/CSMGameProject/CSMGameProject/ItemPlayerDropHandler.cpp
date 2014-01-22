#include <stdio.h>

#include "PacketHandler.h"
#include "PlayerManager.h"

ItemPlayerDropHandler::ItemPlayerDropHandler()
{

}
ItemPlayerDropHandler::~ItemPlayerDropHandler()
{

}
void ItemPlayerDropHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
	case PKT_SC_ITEM_PLAYER_DROP:
		{
			if ( circularBuffer->Read((char*)&mItemPlayerDropResult, header->mSize) )
			{

			}
			else
			{
			}
		}
		break;
	}
}
