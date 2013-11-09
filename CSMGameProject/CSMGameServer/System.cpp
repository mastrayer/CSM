
#include "PreComfiled.h"
#include "System.h"

System* System::m_pInstance = nullptr;

System* System::GetInstance()
{
	if ( m_pInstance == nullptr )
	{
		m_pInstance = new System();
	}

	return m_pInstance;
}
void System::ReleaseInstance()
{
	if ( m_pInstance != nullptr )
	{
		delete m_pInstance;
	}
}

void System::AddClient( SOCKET sock )
{

}
void System::RemoveClient( SOCKET sock )
{

}

System::System()
	: m_ClientIndex(0)
{
	
}
System::~System()
{

}