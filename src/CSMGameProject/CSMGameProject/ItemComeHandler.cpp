#include <stdio.h>

#include "PacketHandler.h"
#include "PlayerManager.h"
#include "EffectManager.h"

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
				switch (mItemComeResult.mItemType)
				{
				case DAMAGEBUFF:
						EffectManager::GetInstance()->AddEffect( new ITEM_EFFECT::DamageBuff(mItemComeResult.mPosition,mItemComeResult.mItemId,mItemComeResult.mLifeTime), -1);
					break;
				case HPBUFF:
						EffectManager::GetInstance()->AddEffect( new ITEM_EFFECT::HPBuff(mItemComeResult.mPosition,mItemComeResult.mItemId,mItemComeResult.mLifeTime), -1);
					break;
				case FLAG:
						EffectManager::GetInstance()->AddEffect( new ITEM_EFFECT::Flag(mItemComeResult.mPosition,mItemComeResult.mItemId), -1);
					break;
				default:
					break;
				}
			}
			else
			{
			}
		}
		break;
	}
}
