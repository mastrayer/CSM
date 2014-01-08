#include <stdio.h>

#include "PacketHandler.h"
#include "PlayerManager.h"
#include "EffectManager.h"
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
				ITEM_EFFECT::Item* item;
				item = EffectManager::GetInstance()->GetItemEffect(mItemPlayerDropResult.mItemId);
				if( mItemPlayerDropResult.mItemType == FLAG )
					item->BackToStartPosition();
			}
			else
			{
			}
		}
		break;
	}
}
