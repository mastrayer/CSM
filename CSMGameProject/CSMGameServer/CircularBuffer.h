
#pragma once

class CircularBuffer
{
public:
	CircularBuffer();
	~CircularBuffer();

	bool Peek( OUT char* destbuf, size_t bytes ) const;
	bool Read( OUT char* destbuf, size_t bytes );
	bool Write( const char* data, size_t bytes );

	void Remove( size_t len );

	size_t GetFreeSpaceSize();
	size_t GetStoredSize() const;

	size_t GetContiguiousBytes() const;

	void* GetBuffer() const;
	void Commit( size_t len );

	void* GetBufferStart() const;

private:
	void AllocateB();
	size_t GetAFreeSpace();
	size_t GetSpaceBeforeA();
	size_t GetBFreeSpace();

private:
	char* m_Buffer;
	char* m_BufferEnd;
	char* m_ARegionPointer;
	size_t m_ARegionSize;
	char* m_BRegionPointer;
	size_t m_BRegionSize;
};