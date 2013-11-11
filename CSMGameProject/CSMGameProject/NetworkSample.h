
/**********************************************************************/
/**********************************************************************/
/*                                                                    */
/*                                                                    */
/*                       작업 중 건들지 말 것!                        */
/*                                                                    */
/*                                                                    */
/**********************************************************************/
/**********************************************************************/

#ifdef _DEBUG

#pragma once

#include "NNScene.h"

class NetworkSample : public NNScene
{
public:
	NetworkSample();
	virtual ~NetworkSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(NetworkSample);

private:
	float m_Time;
};

#endif