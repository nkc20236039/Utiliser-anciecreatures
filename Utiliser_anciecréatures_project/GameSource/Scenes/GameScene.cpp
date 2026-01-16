#include "GameScene.h"

#include "Library/Wrapper.h"
#include "../GameScene/Player/PlayerMain.h"
#include "../Global/Camera/FreeCamera.h"

// ゲームシーンに入ったときの初期化処理
void GameScene::Enter() {
	Library::SetBackgroundColor(Library::Color(0.2f, 0.8f, 0.8f, 1.0f));

	// カメラの作成
	m_gameObjectManager.Spawn<FreeCamera>();

	std::shared_ptr<Transform> playerTransform = std::make_shared<Transform>(
		Library::float3(0.0f, 0.0f, 0.0f),		// position
		Library::float3(100.0f, 100.0f, 100.0f),	// scale
		Library::float3(0.0f, 0.0f, 0.0f));			// rotation
	m_gameObjectManager.Spawn<PlayerMain>(playerTransform, "Assets/Model/Player/PlayerModel.mv1");
}

// ゲームシーンから出るときの終了処理
void GameScene::Exit() {}