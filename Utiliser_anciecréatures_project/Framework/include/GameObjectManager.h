#pragma once

#include <memory>
#include <vector>

#include "GameObject.h"
#include "GameFrame.h"

template <typename T>
concept IsGameObject = std::is_base_of_v<GameObject, T>;

class GameObjectManager {
public:
	GameObjectManager() = default;
	~GameObjectManager() = default;

	/// <summary>
	/// 新しいゲームオブジェクトを更新サイクルに追加する
	/// </summary>
	void ProcessSpawn();

	/// <summary>
	/// ゲームオブジェクトを更新する
	/// </summary>
	void Update(const Time& time);

	/// <summary>
	/// ゲームオブジェクトを描画する
	/// </summary>
	void Draw();

	/// <summary>
	/// 破棄予定のゲームオブジェクトを更新サイクルから削除する
	/// </summary>
	void ProcessDestroy();

	/// <summary>
	/// 新しいゲームオブジェクトを生成する
	/// </summary>
	/// <returns>生成されたゲームオブジェクトのポインタ</returns>
	template<IsGameObject T, class... Args>
	T* Spawn(Args&&... args) {
		// 新しいゲームオブジェクトを生成
		auto gameObject = new T(std::forward<Args>(args)...);

		// 生成直後のゲームオブジェクトリストに追加
		m_spawnedRequests.push_back(gameObject);

		// 作成したゲームオブジェクトのポインタを返す
		return gameObject;
	}

	/// <summary>
	/// ゲームオブジェクトを破棄する
	/// </summary>
	void Destroy(GameObject* gameObject);

private:
	// シーン内のゲームオブジェクトリスト
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;
	// 生成直後のゲームオブジェクトリスト
	std::vector<GameObject*> m_spawnedRequests;
	// 破棄予定のゲームオブジェクトリスト
	std::vector<GameObject*> m_destroyRequests;
};