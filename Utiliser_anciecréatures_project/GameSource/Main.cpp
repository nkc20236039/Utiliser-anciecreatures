#include <memory>
#include <Windows.h>

#include "src/SceneManager/SceneManager.h"
#include "../GameSource/Scenes/TitleScene.h"
#include "src/MasterData/MasterData.h"
#include "src/Frame/FrameManager.h"
#include "src/System/OutputLog.h"
#include "FrameworkRoot.h"

int WINAPI WinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nShowCmd) {

	UFramework::FrameworkRoot framework;
	framework.Run();

	// ソフトの終了
	return 0;
}