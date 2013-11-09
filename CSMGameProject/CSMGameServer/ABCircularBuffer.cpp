
#include "ABCircularBuffer.h"

ABCircularBuffer::ABCircularBuffer( int capacity )
	: m_Buffer(nullptr), m_IndexA(0), m_SizeA(0), m_IndexB(0), m_SizeB(0),
	  m_Capacity(capacity), m_IndexReserve(0), m_SizeReserve(0)
{
	m_Buffer = new char[m_Capacity];
}
ABCircularBuffer::~ABCircularBuffer()
{
	delete[] m_Buffer;
}

char* ABCircularBuffer::Reserve( int size, OUT int& reserved )
{
	if ( m_SizeB > 0 )
	{
		int freespace = GetBFreeSpace();

		if ( size < freespace )
		{
			freespace = size;
		}

		if ( freespace == 0 )
		{
			return nullptr;
		}

		m_SizeReserve = freespace;
		reserved = freespace;
		m_IndexReserve = m_IndexB + m_SizeB;

		return m_Buffer + m_IndexReserve;
	}
	else
	{
		int freespace = GetSpaceAfterA();

		if ( freespace >= m_IndexA )
		{
			if ( freespace == 0 )
			{
				return nullptr;
			}

			if ( size < freespace )
			{
				freespace = size;
			}

			m_SizeReserve = freespace;
			reserved = freespace;
			m_IndexReserve = m_IndexA + m_SizeA;

			return m_Buffer + m_IndexReserve;
		}
		else
		{
			if ( m_IndexA == 0 )
			{
				return nullptr;
			}

			int freespace = size;

			if ( m_IndexA < size )
			{
				freespace = m_IndexA;
			}

			m_SizeReserve = freespace;
			reserved = freespace;
			m_IndexReserve = 0;

			return m_Buffer;
		}
	}
}
void ABCircularBuffer::Commit( int size )
{
	if ( size == 0 )
	{
		m_SizeReserve = 0;
		m_IndexReserve = 0;
		return;
	}

	if ( size > m_SizeReserve )
	{
		assert(false);
		size = m_SizeReserve;
	}

	if ( m_SizeA == 0 && m_SizeB == 0 )
	{
		m_IndexA = m_IndexReserve;
		m_SizeA = size;
		m_IndexReserve = 0;
		m_SizeReserve = 0;
		return;
	}

	if ( m_IndexReserve == m_IndexA+m_SizeA )
	{
		m_SizeA += size;
	}
	else
	{
		m_SizeB += size;
	}

	m_IndexReserve = 0;
	m_SizeReserve = 0;
}

char* ABCircularBuffer::GetFirstDataBlock( OUT int& size )
{

}
void ABCircularBuffer::DecommitFirstDataBlock( int size )
{

}
int ABCircularBuffer::GetCommittedSize() const
{

}
int ABCircularBuffer::GetReservationSize() const
{

}
int ABCircularBuffer::GetCapacity() const
{

}


//////////////////////////////////////////////////////////////////////////
int ABCircularBuffer::GetSpaceAfterA() const
{

}
int ABCircularBuffer::GetBFreeSpace() const
{

}