
#include "stdafx.h"
#include "NNResourceManager.h"

NNResourceManager::NNResourceManager()
{
}
NNResourceManager::~NNResourceManager()
{
	for (auto& iter=m_XMLTable.begin(); iter!=m_XMLTable.end(); iter++ )
	{
		if ( iter->second != nullptr )
		{
			delete iter->second;
			iter->second = nullptr;
		}
	}
	m_XMLTable.clear();

	for (auto& iter=m_ZipTable.begin(); iter!=m_ZipTable.end(); iter++ )
	{	
		if ( iter->second != nullptr )
		{
			delete iter->second;
			iter->second = nullptr;
		}
	}
	m_ZipTable.clear();
}
NNXML* NNResourceManager::LoadXMLFromFIle( std::string path )
{
	if ( !m_XMLTable[path] )
	{
		m_XMLTable[path] = NNXML::Create( path );
	}
	return m_XMLTable[path];
}

NNZip* NNResourceManager::UnzipFileToMemory( std::wstring zipPath, std::wstring FileName)
{
	if(! m_ZipTable[zipPath + FileName])
	{
		HZIP hz = OpenZip(zipPath.c_str(),0);
		ZIPENTRY ze;
		int index=0;

		FindZipItem(hz,FileName.c_str() ,true , &index , &ze);
		//add error handle code here
		char *buf = new char[ze.unc_size];
		UnzipItem(hz,index, buf, ze.unc_size);

		m_ZipTable[zipPath + FileName] = NNZip::Create(buf, ze.unc_size);

		if( buf != nullptr )
		{
			delete buf;
			buf = nullptr;
		}
		CloseZip(hz);
	}	
	return m_ZipTable[zipPath + FileName];
}

void NNResourceManager::CreateZipCode( char *buf, int size, char *result)
{
	md5_state_t state;
	md5_byte_t digest[16];
	int di;

	md5_init(&state);
	md5_append(&state, (const md5_byte_t *)buf, size);
	md5_finish(&state, digest);

	for (di = 0; di < 16; ++di)
		sprintf(result + di * 2, "%02x", digest[di]);
}
NNXML* NNResourceManager::LoadXMLFromMemory( NNZip *buf )
{
	//char *result = CreateZipCode( buf->GetBuffer(), buf->GetSize());

	char result[33];
	CreateZipCode( buf->GetBuffer(), buf->GetSize(), result);

	if ( !m_XMLTable[result] )
		m_XMLTable[result] = NNXML::CreateStream( buf->GetBuffer() );

	return m_XMLTable[result];
}

NNResourceManager* GResourceManager = new NNResourceManager();