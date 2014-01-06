
#include <stdio.h>

#include "PacketHandler.h"
#include "PlayerManager.h"
#include "GameManager.h"

EmoticonHandler::EmoticonHandler()
{

}
EmoticonHandler::~EmoticonHandler()
{

}
void EmoticonHandler::HandlingPacket( short packetType, NNCircularBuffer* circularBuffer, NNPacketHeader* header )
{
	switch ( packetType )
	{
	case PKT_SC_EMOTICON:
		{
			if ( circularBuffer->Read((char*)&mEmoticonResult, header->mSize) )
			{

			}
			else
			{
			}
		}
		break;
	}
}
