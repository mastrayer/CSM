
#include "NNCircularBuffer.h"
#include <memory.h>

NNCircleBuffer::NNCircleBuffer( size_t capacity )
	: m_BeginIndex(0), m_EndIndex(0), m_CurrentSize(0), m_Capacity(capacity)
{
	m_Data = new char[capacity];
}

NNCircleBuffer::~NNCircleBuffer()
{
	delete[] m_Data;
}

bool NNCircleBuffer::Write( const char* data, size_t bytes )
{
	if ( bytes == 0 )
	{
		return false;
	}

	// 용량이 부족할 경우
	if ( bytes > m_Capacity - m_CurrentSize )
	{
		return false;
	}

	// 버퍼에 바로 쓸 수 있을 경우
	if ( bytes <= m_Capacity - m_CurrentSize )
	{
		memcpy( m_Data+m_EndIndex, data, bytes );
		m_EndIndex += bytes;

		if ( m_EndIndex == m_Capacity )
		{
			m_EndIndex = 0;
		}
	}
	// 버퍼에 바로 못 넣어서 나눠서 넣어야 할 경우
	else
	{
		size_t size1 = m_Capacity - m_EndIndex;
		memcpy( m_Data+m_EndIndex, data, size1 );
		size_t size2 = bytes - m_EndIndex;
		memcpy( m_Data, data+size1, size2 );
		m_EndIndex = size2;
	}

	m_CurrentSize += bytes;

	return true;
}

bool NNCircleBuffer::Read( char* data, size_t bytes )
{
	if ( bytes == 0 )
	{
		return false;
	}

	if ( m_CurrentSize < bytes )
	{
		return false;
	}

	if ( bytes <= m_Capacity-m_BeginIndex )
	{
		memcpy( data, m_Data+m_BeginIndex, bytes );
		m_BeginIndex += bytes;

		if ( m_BeginIndex == m_Capacity )
		{
			m_BeginIndex = 0;
		}
	}
	else
	{
		size_t size1 = m_Capacity-m_BeginIndex;
		memcpy( data, m_Data+m_BeginIndex, size1 );

		size_t size2 = bytes - size1;
		memcpy( data+size1, m_Data, size2 );
		m_BeginIndex = size2;
	}

	m_CurrentSize -= bytes;

	return true;
}

void NNCircleBuffer::Peek( char* data )
{
	if ( m_CurrentSize <= m_Capacity-m_BeginIndex )
	{
		memcpy( data, m_Data+m_BeginIndex, m_CurrentSize );
	}
	else
	{
		size_t size1 = m_Capacity - m_BeginIndex;
		memcpy( data, m_Data+m_BeginIndex, size1 );
		size_t size2 = m_CurrentSize + size1;
		memcpy( data+size1, m_Data, size2 );
	}
}

bool NNCircleBuffer::Peek( char* data, size_t bytes )
{
	if ( bytes == 0 )
	{
		return false;
	}

	if ( m_CurrentSize < bytes )
	{
		return false;
	}

	if ( bytes <= m_Capacity - m_BeginIndex )
	{
		memcpy( data, m_Data+m_BeginIndex, bytes );
	}
	else
	{
		size_t size1 = m_Capacity - m_BeginIndex;
		memcpy( data, m_Data+m_BeginIndex, size1 );

		size_t size2 = bytes - size1;
		memcpy( data+size1, m_Data, size2 );
	}

	return true;
}

bool NNCircleBuffer::Consume( size_t bytes )
{
	if ( bytes == 0 )
	{
		return false;
	}

	if ( m_CurrentSize < bytes )
	{
		return false;
	}

	if ( bytes <= m_Capacity - m_BeginIndex )
	{
		m_BeginIndex += bytes;
		if ( m_BeginIndex == m_Capacity )
		{
			m_BeginIndex = 0;
		}
	}
	else
	{
		size_t size2 = bytes + m_BeginIndex - m_Capacity;
		m_BeginIndex = size2;
	}

	m_CurrentSize -= bytes;

	return true;
}