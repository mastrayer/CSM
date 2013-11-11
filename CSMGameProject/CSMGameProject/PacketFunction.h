
#pragma once

#include "Packet.h"
#include "NNCircularBuffer.h"
#include "NNNetworkSystem.h"
#include <iostream>


void ChatResultPacketFunction( NNPacketHeader& header );
void KeyStateUpdateResultPacketFunction( NNPacketHeader& header );