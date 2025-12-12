#include "TitleScene.h"
#include "DxLib.h"

// ゲームシーンに入ったときの初期化処理
void TitleScene::Enter() {
	SetBackgroundColor(0, 255, 255);
	m_titleDemo = m_gameObjectManager.Spawn<TitleDemoObject>();
}

// ゲームシーンから出るときの終了処理
void TitleScene::Exit() {
	m_gameObjectManager.Destroy(m_titleDemo);
}
