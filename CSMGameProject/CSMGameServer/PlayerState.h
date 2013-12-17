
#pragma once

#include "PacketType.h"
#include "CircularBuffer.h"
#include "ClientSession.h"

void PlayerTypeChangeA( ClientSession* client, PacketHeader* header, CircularBuffer* buffer );
void PlayerTypeChangeB( ClientSession* client, PacketHeader* header, CircularBuffer* buffer );
void PlayerTypeChangeC( ClientSession* client, PacketHeader* header, CircularBuffer* buffer );
void PlayerTypeChangeD( ClientSession* client, PacketHeader* header, CircularBuffer* buffer );