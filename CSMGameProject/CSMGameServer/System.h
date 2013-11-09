
#pragma once

#include "Packet.h"

class System
{
public:
	static System* GetInstance();
	static void ReleaseInstance();

	void AddClient( SOCKET sock );
	void RemoveClient( SOCKET sock );


private:
	int m_ClientIndex;

private:
	static System* m_pInstance;

	System();
	~System();
};