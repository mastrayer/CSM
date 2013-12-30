
#include "PacketHandler.h"
#include <stdio.h>
#include <assert.h>
#include "EffectManager.h"
#include "TypeC.h"

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
				EffectManager::GetInstance()->AddEffect( new CTypeAttackEffect(mCTypeAttackShootResult.mAngle,mCTypeAttackShootResult.mStartPosition,mCTypeAttackShootResult.mIndex));
			}
			else
			{

			}
		}
		break;
	}
}
