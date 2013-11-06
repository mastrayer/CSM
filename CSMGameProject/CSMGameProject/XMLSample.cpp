
#ifdef _DEBUG

#pragma once

#include "XMLSample.h"

XMLSample::XMLSample()
{

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