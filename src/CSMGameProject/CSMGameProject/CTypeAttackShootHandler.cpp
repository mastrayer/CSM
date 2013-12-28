
#include "PacketHandler.h"
#include <stdio.h>
#include <assert.h>
#include "EffectManager.h"
#include "TypeB.h"

CTypeAttackShootHandler::CTypeAttackShootHandler()
{

}
CTypeAttackShootHandler::~CTypeAttackShootHandler()
{

}
void CTypeAttackShootHandler::HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header)
{
	switch (packetType)
	{
	case PKT_SC_C_TYPEATTACK_SHOOT:
		{
			if (circularBuffer->Read((char*)&mCTypeAttackShootResult, header->mSize))
			{

			}
			else
			{

			}
		}
		break;
	}
}
