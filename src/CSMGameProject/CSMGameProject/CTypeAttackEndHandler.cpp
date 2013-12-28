#include "PacketHandler.h"
#include <stdio.h>
#include <assert.h>
#include "EffectManager.h"
#include "TypeB.h"

CTypeAttackEndHandler::CTypeAttackEndHandler()
{

}
CTypeAttackEndHandler::~CTypeAttackEndHandler()
{

}
void CTypeAttackEndHandler::HandlingPacket(short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header)
{
	switch (packetType)
	{
	case PKT_SC_C_TYPEATTACK_END:
		{
			if (circularBuffer->Read((char*)&mCTypeAttackEndResult, header->mSize))
			{

			}
			else
			{

			}
		}
		break;
	}
}
