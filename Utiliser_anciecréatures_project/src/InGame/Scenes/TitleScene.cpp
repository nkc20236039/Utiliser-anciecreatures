#include "TitleScene.h"
#include "DxLib.h"
#include "InGame/Scenes/GameScene.h"

// ゲームシーンに入ったときの初期化処理
void TitleScene::Enter() {
	SetBackgroundColor(0, 255, 255);
}

// ゲームシーンの更新処理
void TitleScene::Update() {
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		m_sceneManager->ChangeScene<GameScene>();
	}
}

// ゲームシーンから出るときの終了処理
void TitleScene::Exit() {}