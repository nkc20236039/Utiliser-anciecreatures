#include <memory>
#include <Windows.h>

#include "DxLib.h"
#include "SceneManager/SceneManager.h"
#include "InGame/Scenes/TitleScene.h"
#include "MasterData/MasterData.h"
#include "Frame/FrameManager.h"

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

	// ＤＸライブラリの初期化
	if (DxLib_Init() < 0) {
		// エラーが発生したら直ちに終了
		return -1;
	}

	// VSyncを無効にする
	//SetWaitVSyncFlag(FALSE);

	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

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
	Time time = frame.MeasurementStart();

	// ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		// フレーム時間の計測開始
		time = frame.MeasurementStart();

		// 画面をクリア
		ClearDrawScreen();

		// シーンの更新
		SceneManager::Get().Update(time);
		frame.ShowFPS(100);
		// 裏画面の内容を表画面に反映する
		ScreenFlip();

		// フレーム時間の計測終了
		time = frame.MeasurementEnd();
	}

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}