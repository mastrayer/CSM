
#include "NNXML.h"
#include "TinyXML/xpath_static.h"

NNXML::NNXML( char* path )
	: m_LoadSuccess(false)
{
	m_Document = TiXmlDocument( path );
	//m_Document.LoadFile(TIXML_ENCODING_UTF8);
	m_LoadSuccess = m_Document.LoadFile();
}
NNXML::NNXML()
{
	m_Document = TiXmlDocument();
}
NNXML::~NNXML()
{

}

NNXML* NNXML::Create( char* path )
{
	NNXML* pInstacne = new NNXML(path);
	return pInstacne;
}

NNXML* NNXML::Create()
{
	NNXML* pInstacne = new NNXML();
	return pInstacne;
}

TiXmlString NNXML::XPathToString( char* xpath )
{
	return TinyXPath::S_xpath_string(m_Document.RootElement(), xpath);
}