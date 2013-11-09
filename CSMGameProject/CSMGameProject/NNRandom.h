
#pragma once

class NNRandom
{
public:
	static int NextInt( int min, int max );
	static float NextFloat( float min, float max );
	static double NextDouble( double min, float max );

private:
	static NNRandom* m_pInstance;
	NNRandom();
	~NNRandom();
};