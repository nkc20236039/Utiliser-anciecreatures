#include "GameScene.h"
#include <DxLib.h>

// ゲームシーンに入ったときの初期化処理
void GameScene::Enter() {
	SetBackgroundColor(0, 255, 0);
}

// ゲームシーンの更新処理
void GameScene::Update() {
	DrawCapsule3D(VGet(320.0f, 100.0f, 0.0f), VGet(320.0f, 300.0f, 0.0f), 40.0f, 8, GetColor(0, 255, 0), GetColor(255, 255, 255), FALSE);
}

// ゲームシーンから出るときの終了処理
void GameScene::Exit() {}