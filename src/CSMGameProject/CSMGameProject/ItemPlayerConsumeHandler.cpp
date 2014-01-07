#include <stdio.h>

#include "PacketHandler.h"
#include "PlayerManager.h"

ItemPlayerConsumeHandler::ItemPlayerConsumeHandler()
{

}
ItemPlayerConsumeHandler::~ItemPlayerConsumeHandler()
{

}
void ItemPlayerConsumeHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
	case PKT_SC_ITEM_PLAYER_CONSUME:
		{
			if ( circularBuffer->Read((char*)&mItemPlayerConsumeResult, header->mSize) )
			{
				Ga
			}
			else
			{
			}
		}
		break;
	}
}
