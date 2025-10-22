/*********************************************************************
 * file   SceneStateMachine.cpp
 * brief
 *
 * author nkc20236039
 * created 2025/10/21
 * last_modified 2025/10/22
 *********************************************************************/

#include "SceneStateMachine.h"

SceneStateMachine::SceneStateMachine() : m_previousScene(), m_currentScene(), m_scenes() {}

template<IsScene T>
void SceneStateMachine::ChangeState() {
	// 前回のシーンを保存
	m_previousScene = m_currentScene;
	// 新しいシーンの設定
	// TODO:: 存在チェック
	m_currentScene = m_scenes[typeid(T)];
}

void SceneStateMachine::Update() {
	// ExitとEnterを実行する必要がある場合
	if (m_previousScene != m_currentScene) {
		// 前回のシーンが設定されている場合
		if (m_previousScene != nullptr) {
			// Exitを実行
			m_previousScene->Exit();
		}

		// 新しいシーンのEnterを実行
		m_currentScene->Enter();
	}

	// シーンの更新
	m_currentScene->Update();
}

template<IsScene T>
void SceneStateMachine::Register(std::unique_ptr<IScene> instance) {
	m_scenes[typeid(T)] = instance;
}

template<IsScene T>
void SceneStateMachine::Unregister(std::unique_ptr<IScene> instance) {

}
