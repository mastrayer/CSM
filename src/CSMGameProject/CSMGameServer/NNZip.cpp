#include "stdafx.h"
#include "NNZip.h"
#include <string>


NNZip::NNZip(char *buf, int size)
{
	m_size = size;
	m_buf = new char[size];
	memcpy(m_buf, buf, size);
}
NNZip::~NNZip(void)
{
	if ( m_buf != nullptr )
	{
		delete m_buf;
		m_buf = nullptr;
	}
}
NNZip* NNZip::Create(char *buf, int size)
{
	NNZip* pInstacne = new NNZip(buf, size);

	return pInstacne;
}