#include <memory>
#include <Windows.h>

#include "SceneManager.h"
#include "Scenes.h"
#include "FrameworkRoot.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd) {
	SceneManager::Get().ChangeScene<GameScene>();

	// フレームワークの起動
	UFramework::FrameworkRoot framework;
	framework.Run();

	// ソフトの終了
	return 0;
}