
#include "NNScene.h"

class TestScene : public NNScene
{
public:
public:
	TestScene();
	virtual ~TestScene();

	void Render();
	void Update( float dTime );
	NNCREATE_FUNC(TestScene);
};