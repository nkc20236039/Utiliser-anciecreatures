#include "TitleScene.h"

#include "Library/Wrapper.h"
#include "../GameScene/Player/PlayerMain.h"

// ゲームシーンに入ったときの初期化処理
void TitleScene::Enter() {
	Library::SetBackgroundColor(Library::Color(0.2f, 0.2f, 0.2f, 0.0f));
	std::shared_ptr<Transform> playerTransform = std::make_shared<Transform>(Library::float3(320.0f, 100.0f, 0.0f), Library::float3(100.0f, 100.0f, 100.0f), Library::float3(0.0f, 0.0f, 0.0f));
	m_gameObjectManager.Spawn<PlayerMain>(playerTransform, "Assets/Model/Player/PlayerModel.mv1");
}

// ゲームシーンから出るときの終了処理
void TitleScene::Exit() {}