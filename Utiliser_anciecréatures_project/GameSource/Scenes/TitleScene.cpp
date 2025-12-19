#include "TitleScene.h"
#include "DxLib.h"

#include "src/GameObject/DemoObject.h"	

// ゲームシーンに入ったときの初期化処理
void TitleScene::Enter() {
	SetBackgroundColor(0, 255, 255);
	m_gameObjectManager.Spawn<DemoObject>();
}

// ゲームシーンから出るときの終了処理
void TitleScene::Exit() {}