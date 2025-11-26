#include "GameObjectManager.h"

// 新しいゲームオブジェクトを更新サイクルに追加する
void GameObjectManager::ProcessSpawn() {
	// 更新サイクルへ移動する
	for (auto* gameObject : m_spawnedRequests) {
		m_gameObjects.emplace_back(gameObject);
		// Startを実行
		gameObject->Start();
	}
	// リストをクリア
	m_spawnedRequests.clear();
}

void GameObjectManager::Update() {
	for (auto& gameObject : m_gameObjects) {
		// 非アクティブなオブジェクトはスキップ
		if (!gameObject->IsActive()) { continue; }
		// ゲームオブジェクトを更新
		gameObject->Tick();
	}
}

// 破棄予定のゲームオブジェクトを更新サイクルから削除する
void GameObjectManager::ProcessDestroy() {
	for (auto* gameObject : m_destroyRequests) {
		// 該当するゲームオブジェクトをリストから削除
		auto it = std::remove_if(
			m_gameObjects.begin(),
			m_gameObjects.end(),
			[&](auto& objectPtr) {
				return objectPtr.get() == gameObject;
			}
		);
		m_gameObjects.erase(it, m_gameObjects.end());
	}

	// リストをクリア
	m_destroyRequests.clear();
}

// 破棄予定のゲームオブジェクトを更新サイクルから削除する
void GameObjectManager::Destroy(GameObject* gameObject) {
	// 破棄予定リストに追加
	m_destroyRequests.push_back(gameObject);
}