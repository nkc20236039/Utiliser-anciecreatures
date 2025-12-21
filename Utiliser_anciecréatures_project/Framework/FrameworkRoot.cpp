#include "FrameworkRoot.h"

#include "Library/Wrapper.h"
#include "src/System/OutputLog.h"
#include "src/SceneManager/SceneManager.h"

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

	// フレームマネージャーの生成
	// 最初の画面表示までのフレーム時間を計測
	m_frameManager.MeasurementStart();
	Library::ScreenFlip();
	m_frameManager.MeasurementEnd();

	return true;
}

bool FrameworkRoot::MainLoop() {
	// フレーム時間の計測開始
	Time time = m_frameManager.MeasurementStart();

	// 画面をクリア
	Library::ClearDrawScreen();

	// シーンの更新
	SceneManager::Get().Update(time);

#if _DEBUG
	// 0.1秒ごとにFPSを表示
	m_frameManager.ShowFPS(100);
#endif

	// 裏画面の内容を表画面に反映する
	Library::ScreenFlip();

	// デバッグ用描画ログをクリア
	OUTPUT_LOG::ClearDisplayLog();

	// フレーム時間の計測終了
	time = m_frameManager.MeasurementEnd();

	return true;
}

bool FrameworkRoot::Finalize() {
	// 終了処理
	return Library::Finalize();
}