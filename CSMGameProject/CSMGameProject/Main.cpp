
#include "NNApplication.h"
#include "GameScene.h"
#include "StoryScene.h"
#include "MainMenuScene.h"

#ifdef _DEBUG
#pragma comment(lib, "NNGameFramework_DEBUG.lib")
#else
#pragma comment(lib, "NNGameFramework.lib")
#endif

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nShowCmd )
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEmDF|_CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc( 155 );

	AllocConsole();
	FILE* console;
	freopen_s( &console, "CONOUT$", "wt", stdout );

	printf_s("Console Open \n");
#endif

	NNApplication* Application = NNApplication::GetInstance();

	Application->Init( L"CSM Project", 800, 600, D2D );

	NNSceneDirector::GetInstance()->ChangeScene( MainMenuScene::Create() );

	Application->Run();
	Application->Release();

#ifdef _DEBUG
	FreeConsole();
#endif

	return 0;
}