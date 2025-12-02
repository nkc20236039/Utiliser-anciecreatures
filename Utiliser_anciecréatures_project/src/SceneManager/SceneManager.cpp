#include "SceneManager.h"

void SceneManager::Update() {
	// シーン切り替えが要求されている場合
	if (m_nextSceneFactory) {
		// 現在のシーンが存在すれば終了処理を行う
		if (m_currentScene) {
			m_currentScene->Exit();
		}

		// 新しいシーンを生成して現在のシーンに設定
		m_currentScene = m_nextSceneFactory();
		m_nextSceneFactory = nullptr;

		// 新しいシーンの初期化を行う
		if (m_currentScene) {
			m_currentScene->Enter();
		}
	}

	// 現在のシーンが存在しなければ更新処理を行わない
	if (!m_currentScene) { return; }

	// ゲームオブジェクトの更新
	m_currentScene->UpdateGameObjects();
}
