
#include "NNRandom.h"
#include <time.h>
#include <stdlib.h>

NNRandom* NNRandom::m_pInstance = nullptr;

int NNRandom::NextInt( int min, int max )
{
	if ( max == 0 ) 
	{
		return 0;
	}
	return (rand()%(max-min))+min;
}
float NNRandom::NextFloat( float min, float max )
{
	if ( max == 0 )
	{
		return 0;
	}
	float point = float(rand()/rand());
	if ( point > 1 )
	{
		point -= 1;
	}
	return (rand()%int(max-min))+min + point;
}
double NNRandom::NextDouble( double min, float max )
{
	if ( max == 0 )
	{
		return 0;
	}
	double point = double(rand()/rand());
	if ( point > 1 )
	{
		point -= 1;
	}
	return (rand()%int(max-min))+min + point;
}

NNRandom::NNRandom()
{
	srand((unsigned int)time(NULL));
}
NNRandom::~NNRandom()
{

}