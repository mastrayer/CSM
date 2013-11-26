
#include "PacketType.h"
#include "CircularBuffer.h"
#include "ClientSession.h"

void ClientLoginPacket( ClientSession* client, PacketHeader* header, CircularBuffer* buffer );