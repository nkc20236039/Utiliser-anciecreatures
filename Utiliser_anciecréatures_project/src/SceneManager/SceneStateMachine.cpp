#include "SceneStateMachine.h"


SceneStateMachine::SceneStateMachine() : m_previousScene(nullptr), m_currentScene(nullptr), m_scenes() {}

void SceneStateMachine::Update() {
	// ExitとEnterを実行する必要がある場合
	if (m_previousScene != m_currentScene) {
		// 前回のシーンが設定されている場合
		if (m_previousScene != nullptr) {
			// Exitを実行
			m_previousScene->Exit();
		}
		else {	// 前回のシーンが未設定の場合
			// 前回のシーンに現在のシーンを入れる
			m_previousScene = m_currentScene;
		}

		// 新しいシーンのEnterを実行
		m_currentScene->Enter();
	}

	// シーンの更新
	m_currentScene->Update();
}