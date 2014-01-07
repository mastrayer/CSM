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
				if(item == nullptr)
				{
					switch (mItemPlayerConsumeResult.mItemType)
					{
					case DAMAGEBUFF:
						item = new ITEM_EFFECT::DamageBuff(NNPoint(0,0),mItemPlayerConsumeResult.mItemId,mItemPlayerConsumeResult.mLifeTime);
						break;
					case HPBUFF:
						item = new ITEM_EFFECT::HPBuff(NNPoint(0,0),mItemPlayerConsumeResult.mItemId,mItemPlayerConsumeResult.mLifeTime);
						break;
					case FLAG:
						item = new ITEM_EFFECT::Flag(NNPoint(0,0),mItemPlayerConsumeResult.mItemId);
						break;
					default:
						break;
					}
					
					EffectManager::GetInstance()->AddEffect(item );
				}
				item->Follow(mItemPlayerConsumeResult.mPlayerId);
				item->SetLifeTime(mItemPlayerConsumeResult.mLifeTime);
			}
			else
			{
			}
		}
		break;
	}
}
