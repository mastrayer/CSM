#include "PacketHandler.h"
#include <stdio.h>
#include <assert.h>
#include "EffectManager.h"
#include "TypeD.h"

DTypeAttackShootHandler::DTypeAttackShootHandler()
{

}
DTypeAttackShootHandler::~DTypeAttackShootHandler()
{

}
void DTypeAttackShootHandler::HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header)
{
	switch (packetType)
	{
	case PKT_SC_D_TYPEATTACK_SHOOT:
		{
			if (circularBuffer->Read((char*)&mDTypeAttackShootResult, header->mSize))
			{
				EffectManager::GetInstance()->AddEffect( new DTypeAttackEffect(mDTypeAttackShootResult.mPlayerId));
			}
			else
			{

			}
		}
		break;
	}
}
