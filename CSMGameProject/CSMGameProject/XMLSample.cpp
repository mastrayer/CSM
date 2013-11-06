
#ifdef _DEBUG

#pragma once

#include "XMLSample.h"
#include <iostream>

XMLSample::XMLSample()
{
	m_TestXML = NNXML::Create( "Resource/XML/test2.xml" );
	std::cout << m_TestXML->XPathToString("/MyApp/Messages/Welcome/text()").c_str() << std::endl;
	std::cout << "xml end" << std::endl;
}
XMLSample::~XMLSample()
{

}

void XMLSample::Render()
{
	NNObject::Render();
}
void XMLSample::Update( float dTime )
{
	NNObject::Update(dTime);
}

#endif