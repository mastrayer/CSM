#include <stdio.h>

#include "PacketHandler.h"
#include "PlayerManager.h"

ItemComeHandler::ItemComeHandler()
{

}
ItemComeHandler::~ItemComeHandler()
{

}
void ItemComeHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
	case PKT_SC_ITEM_COME:
		{
			if ( circularBuffer->Read((char*)&mItemComeResult, header->mSize) )
			{

			}
			else
			{
			}
		}
		break;
	}
}
