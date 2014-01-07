#include <stdio.h>

#include "PacketHandler.h"
#include "PlayerManager.h"
#include "EffectManager.h"

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
				ITEM_EFFECT::Item* item;
				item = EffectManager::GetInstance()->GetItemEffect(mItemPlayerConsumeResult.mItemId);
				item->Follow(mItemPlayerConsumeResult.mPlayerId);
			}
			else
			{
			}
		}
		break;
	}
}
