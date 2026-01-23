#include "GameObjectManager.h"

#include "Library/Wrapper.h"

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

void GameObjectManager::Update(const Time& time) {
	for (const auto& gameObject : m_gameObjects) {
		// 非アクティブなオブジェクトはスキップ
		if (!gameObject->IsActive()) { continue; }

		// ゲームオブジェクトの更新処理を実行
		gameObject->Update(time);
	}
}

void GameObjectManager::Draw() {
	for (const auto& gameObject : m_gameObjects) {
		// ゲームオブジェクトの状態を更新する
		gameObject->UpdateGameObjectState();

		// モデルハンドルを取得
		int handle = gameObject->GetModelHandle();
		// モデルハンドルが無効であれば描画をスキップ
		if (handle == -1) { continue; }
		// モデルを描画
		Library::DrawModel(handle);
	}
}

// 破棄予定のゲームオブジェクトを更新サイクルから削除する
void GameObjectManager::ProcessDestroy() {
	for (auto* gameObject : m_destroyRequests) {
		// 該当するゲームオブジェクトをリストから削除
		auto it = std::remove_if(
			m_gameObjects.begin(),
			m_gameObjects.end(),
			[gameObject](auto& objectPtr) {
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