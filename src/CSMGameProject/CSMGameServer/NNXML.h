
#pragma once

#include "tinyxml.h"
#include "xpath_static.h"
#include <string>

class NNXML
{
public: 
	NNXML( std::string path );
	NNXML( char *buf );
	NNXML();
	~NNXML();

	static NNXML* Create( std::string path );
	static NNXML* Create();
	static NNXML* CreateStream( char* buf );

	TiXmlString XPathToString( std::string xpath );
	TiXmlDocument *GetDoc() { return &m_Document; }
private:
	TiXmlDocument m_Document;

	bool m_LoadSuccess;
};