#include "FrameworkRoot.h"
using namespace UFramework;

#include <DxLib.h>

// public:
bool FrameworkRoot::Run() {
	// 初期化処理の実行
	if (!Initialize()) {
		return false;
	}

	while (ProcessMessage() == 0) {
		// メインループの実行
		if (!MainLoop()) {
			break;
		}
	}

	Finalize();
	return true;
}

// private:
bool FrameworkRoot::Initialize() {
	// 初期化前のアプリ設定
#ifdef _DEBUG
	ChangeWindowMode(TRUE);
	SetOutApplicationLogValidFlag(TRUE);
#else
	ChangeWindowMode(FALSE);
	SetOutApplicationLogValidFlag(FALSE);
#endif

	// DxLibの初期化
	if (DxLib_Init() < 0) {
		// エラーが発生したら直ちに終了
		return false;
	}

	return true;
}

bool FrameworkRoot::MainLoop() {
	// 処理メッセージ
	return true;
}

void FrameworkRoot::Finalize() {
	// DxLibの終了処理
	DxLib_End();
}