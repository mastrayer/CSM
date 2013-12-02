
#pragma once

#include "NNXML.h"
#include "NNZip.h"
#include "unzip.h"
#include "md5.h"
#include <map>
/* */
/* NNResourceManager
/* 파일 리소스를 관리하는 싱글톤 클래스
/* 현재 텍스쳐 파일만 관리함
/* */

class NNResourceManager
{
private:
	static NNResourceManager* m_pInstance;

private:
	std::map<std::string,NNXML*> m_XMLTable;
	std::map<std::wstring,NNZip*> m_ZipTable;
private:
	NNResourceManager();
	~NNResourceManager();

public:
	static NNResourceManager* GetInstance();
	static void ReleaseInstance();

	//NNTexture* LoadTexture( std::string key );
	NNXML* LoadXMLFromFIle( std::string path );

	NNZip* UnzipFileToMemory( std::wstring zipPath, std::wstring FileName );
	NNXML* LoadXMLFromMemory( NNZip *buf );

protected:
	//char* CreateZipCode( char *buf ,int size);//, char *result );
	void CreateZipCode( char *buf ,int size, char *result );
};


