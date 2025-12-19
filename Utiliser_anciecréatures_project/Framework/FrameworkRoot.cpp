#include "FrameworkRoot.h"
#include "Library/Wrapper.h"

using namespace UFramework;

// public:
bool FrameworkRoot::Run() {
	// 初期化処理の実行
	if (!Initialize()) {
		return false;
	}

	while (Library::ProcessMessage()) {
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
	Library::ChangeWindowMode(true);
	Library::SetOutApplicationLogValidFlag(true);
#else
	Library::ChangeWindowMode(false);
	Library::SetOutApplicationLogValidFlag(false);
#endif

	// 初期化
	if (!Library::Init()) {
		// エラーが発生したら直ちに終了
		return false;
	}

	// 描画先画面を裏画面にセット
	Library::SetDrawScreen(Library::ScreenTarget::Back);

	return true;
}

bool FrameworkRoot::MainLoop() {
	// 処理メッセージ
	return true;
}

bool FrameworkRoot::Finalize() {
	// 終了処理
	return Library::Finalize();
}