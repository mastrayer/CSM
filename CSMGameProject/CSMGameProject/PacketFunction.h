
#pragma once

#include "Packet.h"
#include "NNCircularBuffer.h"
#include "NNNetworkSystem.h"
#include <iostream>


void TestChatResultPacketFunction( NNPacketHeader& header );
void KeyStateUpdateResultPacketFunction( NNPacketHeader& header )