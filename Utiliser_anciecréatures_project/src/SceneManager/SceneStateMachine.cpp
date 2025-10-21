#include "SceneStateMachine.h"

SceneStateMachine::SceneStateMachine(std::type_index firstSceneType, std::unique_ptr<IScene> firstSceneInstance) :
	m_currentScene(firstSceneInstance.get()),
	m_scenes{ {firstSceneType, std::move(firstSceneInstance)} } {
	// 初期化

}

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
