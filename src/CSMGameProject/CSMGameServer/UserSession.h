
#pragma once

#include "PacketType.h"
#include "CircularBuffer.h"
#include "ClientSession.h"

void ClientKeyStatePacket( ClientSession* client, PacketHeader* header, CircularBuffer* buffer );
void ClientMouseAnglePacket( ClientSession* client, PacketHeader* header, CircularBuffer* buffer );