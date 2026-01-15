#include "TitleScene.h"

#include "Library/Wrapper.h"

// ゲームシーンに入ったときの初期化処理
void TitleScene::Enter() {
	Library::SetBackgroundColor(Library::Color(0.2f, 0.2f, 0.2f, 0.0f));
}

// ゲームシーンから出るときの終了処理
void TitleScene::Exit() {}