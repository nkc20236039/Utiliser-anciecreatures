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
	// 初期化前のアプリ設定
#ifdef _DEBUG
	ChangeWindowMode(TRUE);
	SetOutApplicationLogValidFlag(TRUE);
#else
	ChangeWindowMode(FALSE);
	SetOutApplicationLogValidFlag(FALSE);
#endif

	UFramework::FrameworkRoot framework;
	framework.Run();
	return 0;

	// DxLibの初期化
	if (DxLib_Init() < 0) {
		// エラーが発生したら直ちに終了
		return false;
	}

	// Ｚバッファを有効にする
	SetUseZBuffer3D(TRUE);

	// Ｚバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);

	// マスターの読み込み
	MasterData::Load();

	// 最初のシーンをタイトルシーンに設定
	SceneManager::Get().ChangeScene<TitleScene>();

	// フレームマネージャーの生成
	FrameManager frame;
	// 最初の画面表示までのフレーム時間を計測
	Time time = frame.MeasurementStart();
	ScreenFlip();
	time = frame.MeasurementEnd();

	// ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		// フレーム時間の計測開始
		time = frame.MeasurementStart();

		// 画面をクリア
		ClearDrawScreen();

		// シーンの更新
		SceneManager::Get().Update(time);

#if _DEBUG
		// 0.1秒ごとにFPSを表示
		frame.ShowFPS(100);
#endif

		// 裏画面の内容を表画面に反映する
		ScreenFlip();

		// デバッグ用描画ログをクリア
		OUTPUT_LOG::ClearDisplayLog();

		// フレーム時間の計測終了
		time = frame.MeasurementEnd();
	}

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}