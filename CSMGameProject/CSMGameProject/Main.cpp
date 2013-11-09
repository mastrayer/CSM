
#include "NNApplication.h"
#include "GameScene.h"

#include "AnimationSample.h"
#include "XMLSample.h"
#include "SpriteAtlasSample.h"
#include "CameraSample.h"
#include "FMODSoundSample.h"
#include "NetworkSample.h"

/*
void main()
{
	WinMain(0, 0, 0, 3);
}*/

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nShowCmd )
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc( );

	AllocConsole();
	FILE* console;
	freopen_s( &console, "CONOUT$", "wt", stdout );

	printf_s("Console Open \n");
#endif

	NNApplication* Application = NNApplication::GetInstance();

	Application->Init( L"D2D Test", 800, 600, D2D );

	// NNSceneDirector::GetInstance()->ChangeScene( CGameScene::Create() );
	// NNSceneDirector::GetInstance()->ChangeScene( AnimationSample::Create() );
	// NNSceneDirector::GetInstance()->ChangeScene( XMLSample::Create() );
	// NNSceneDirector::GetInstance()->ChangeScene( SpriteAtlasSample::Create() );
	// NNSceneDirector::GetInstance()->ChangeScene( CameraSample::Create() );
	// NNSceneDirector::GetInstance()->ChangeScene( FMODSoundSample::Create() );
	NNSceneDirector::GetInstance()->ChangeScene( NetworkSample::Create() );

	Application->Run();
	Application->Release();

#ifdef _DEBUG
	FreeConsole();
#endif

	return 0;
}