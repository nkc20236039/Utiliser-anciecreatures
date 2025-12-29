#include "GameScene.h"
#include <DxLib.h>

#include "SceneManager.h"
#include "../GameSource/Scenes.h"

// ゲームシーンに入ったときの初期化処理
void GameScene::Enter() {
	SetBackgroundColor(0, 255, 0);
}

// ゲームシーンから出るときの終了処理
void GameScene::Exit() {}