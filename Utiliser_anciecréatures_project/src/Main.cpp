#include "DxLib.h"
#include "SceneManager/SceneStateMachine.h"
#include "Utility/OutputLog.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
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

	// 描画先画面を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	// Ｚバッファを有効にする
	SetUseZBuffer3D(TRUE);

	// Ｚバッファへの書き込みを有効にする
	SetWriteZBuffer3D(TRUE);

	// ゲームループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		
	}

	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}