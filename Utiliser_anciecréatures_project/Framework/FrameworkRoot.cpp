#include "FrameworkRoot.h"

#include "MasterData.h"
#include "Library/Wrapper.h"
#include "OutputLog.h"
#include "SceneManager.h"
#include "ApplicationManager.h"

using namespace UFramework;
using json = nlohmann::json;

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
	// マスターデータの読み込み
	if (!MasterData::GetInstance().Initialize("Assets/MasterData")) {
		return false;
	}
	MasterData::GetInstance().SetDefaultPath("Assets/MasterData");

	/* アプリ設定 */
	// データの取得
	json appConfig = MasterData::GetInstance().Load("AppConfig.json");

	// ログ出力
	Library::SetOutApplicationLogValidFlag(appConfig.at("LogOutput").get<bool>());

	// 画面の設定
	// フルスクリーン設定
	int width = appConfig.at("WindowWidth").get<int>();
	int height = appConfig.at("WindowHeight").get<int>();
	int colorBit = appConfig.at("ColorBit").get<int>();
	ApplicationManager::GetInstance().SetWindowSize(width, height, colorBit);

	bool isFullScreen = appConfig.at("FullScreen").get<bool>();
	Library::ChangeWindowMode(!isFullScreen);

	if (isFullScreen) {
		Library::SetFullScreenResolutionMode(Library::ResolutionMode::Native);
	}
	else {
		Library::SetWindowSizeExtendRate(1);
	}

	Library::SetMainWindowText(appConfig.at("AppName").get<std::string>());

	// アイコンパスが指定されていればアイコンを設定
	if (!appConfig.at("IconPath").is_null()) {
		int iconId = Library::LoadGraph(appConfig.at("IconPath").get<std::string>());
		Library::SetWindowIconId(iconId);
	}

	// 描画先画面を裏画面にセット
	Library::SetDrawScreen(Library::ScreenTarget::Back);
	Library::SetUseZBuffer3D(true);
	Library::SetWriteZBuffer3D(true);
	Library::SetWaitVSyncFlag(appConfig.at("VSync").get<bool>());

	// 初期化
	if (!Library::Init()) {
		// エラーが発生したら直ちに終了
		return false;
	}

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


	// 入力の更新
	m_inputManager.Update();


	// シーンの更新
	SceneManager::GetInstance().Update(time);

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

	// カーソルロック
	if (ApplicationManager::GetInstance().GetCursorLockFlag()) {
		ApplicationManager::GetInstance().SetCursorToCenter();
	}

	return true;
}

bool FrameworkRoot::Finalize() {
	// 終了処理
	return Library::Finalize();
}