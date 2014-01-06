
#include "NNApplication.h"
#include "GameScene.h"
#include "StoryScene.h"
//#include "MainMenuScene.h"
#include "LoadScene.h"

#ifdef _DEBUG
#pragma comment(lib, "NNGameFramework_DEBUG.lib")
#else
#pragma comment(lib, "NNGameFramework.lib")
#endif
#define _CRT_SECURE_NO_WARNINGS
int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nShowCmd )
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF|_CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc( 155 );

	AllocConsole();
	FILE* console;
	freopen_s( &console, "CONOUT$", "wt", stdout );

	printf_s("Console Open \n");
#endif

	NNApplication* Application = NNApplication::GetInstance();

	Application->Init( L"CSM Project", 800, 600, D2D );

	//NNSceneDirector::GetInstance()->ChangeScene( MainMenuScene::Create() );
	NNSceneDirector::GetInstance()->ChangeScene( LoadScene::Create(L"resource/map/44.csm",0,0));
	//NNSceneDirector::GetInstance()->ChangeScene(CGameScene::Create(L"resource/map/44.csm"));

	Application->Run();
	Application->Release();

#ifdef _DEBUG
	FreeConsole();
#endif

	return 0;
}