
#pragma once

#include "TinyXML/tinyxml.h"
#include <string>

class NNXML
{
public: 
	NNXML( char* path );
	NNXML();
	~NNXML();

	static NNXML* Create( char* path );
	static NNXML* Create();

	TiXmlString XPathToString( char* xpath );

private:
	TiXmlDocument m_Document;

	bool m_LoadSuccess;
};