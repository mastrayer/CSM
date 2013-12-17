
#pragma once

#include "NNXML.h"
#include "NNZip.h"
#include "unzip.h"
#include "md5.h"
#include <map>


class NNResourceManager
{
private:
	NNResourceManager();
	~NNResourceManager();

private:
	std::map<std::string,NNXML*> m_XMLTable;
	std::map<std::wstring,NNZip*> m_ZipTable;

	//NNTexture* LoadTexture( std::string key );
	NNXML* LoadXMLFromFIle( std::string path );

	NNZip* UnzipFileToMemory( std::wstring zipPath, std::wstring FileName );
	NNXML* LoadXMLFromMemory( NNZip *buf );

protected:
	//char* CreateZipCode( char *buf ,int size);//, char *result );
	void CreateZipCode( char *buf ,int size, char *result );
};

extern NNResourceManager* GResourceManager;