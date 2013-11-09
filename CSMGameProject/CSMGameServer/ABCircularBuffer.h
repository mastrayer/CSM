
#pragma once

#include "PreComfiled.h"
#include <assert.h>

class ABCircularBuffer
{
public:
	ABCircularBuffer( int capacity );
	~ABCircularBuffer();

	char* Reserve( int size, OUT int& reserved );
	void Commit( int size );

	char* GetFirstDataBlock( OUT int& size );
	void DecommitFirstDataBlock( int size );
	int GetCommittedSize() const;
	int GetReservationSize() const;
	int GetCapacity() const;

private:
	int GetSpaceAfterA() const;
	int GetBFreeSpace() const;

private:
	char* m_Buffer;
	int m_IndexA;
	int m_SizeA;
	int m_IndexB;
	int m_SizeB;
	int m_Capacity;
	int m_IndexReserve;
	int m_SizeReserve;
};