#include "GameScene.h"
#include <DxLib.h>

// ゲームシーンに入ったときの初期化処理
void GameScene::Enter() {
	SetBackgroundColor(0, 255, 0);
	m_gameDemo = m_gameObjectManager.Spawn<GameDemoObject>();
}

// ゲームシーンから出るときの終了処理
void GameScene::Exit() {
	m_gameObjectManager.Destroy(m_gameDemo);
}
