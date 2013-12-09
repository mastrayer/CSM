
#ifdef _DEBUG

#include "NNScene.h"
#include "NNSound.h"

class FMODSoundSample : public NNScene
{
public:
	FMODSoundSample();
	virtual ~FMODSoundSample();

	void Render();
	void Update( float dTime );

	NNCREATE_FUNC(FMODSoundSample);

private:
	NNSound* mSound;
	NNSound* mBackground;
};

#endif