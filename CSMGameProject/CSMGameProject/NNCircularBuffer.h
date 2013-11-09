
#pragma once

// size_t == unsigned int

class NNCircularBuffer
{
public:
	NNCircularBuffer( size_t capacity );
	~NNCircularBuffer();

	size_t GetCurrentSize() const { return m_CurrentSize; }
	size_t GetCapacity() const { return m_Capacity; }

	bool Write( const char* data, size_t bytes );
	bool Read( char*, size_t bytes );

	void Peek( char* data );
	bool Peek( char* data, size_t bytes );

	bool Consume( size_t bytes );

private:
	size_t m_BeginIndex;
	size_t m_EndIndex;
	size_t m_CurrentSize;
	size_t m_Capacity;

	char* m_Data;
};