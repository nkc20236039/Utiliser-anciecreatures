#include "SceneStateMachine.h"

SceneStateMachine::SceneStateMachine(std::type_index firstSceneType, std::unique_ptr<IScene> firstSceneInstance) :
	m_currentScene(firstSceneInstance.get()),
	m_scenes{ {firstSceneType, std::move(firstSceneInstance)} } {
	// ������

}

template<IsScene T>
void SceneStateMachine::ChangeState() {
	// �O��̃V�[����ۑ�
	m_previousScene = m_currentScene;
	// �V�����V�[���̐ݒ�
	// TODO:: ���݃`�F�b�N
	m_currentScene = m_scenes[typeid(T)];
}

void SceneStateMachine::Update() {
	// Exit��Enter�����s����K�v������ꍇ
	if (m_previousScene != m_currentScene) {
		// �O��̃V�[�����ݒ肳��Ă���ꍇ
		if (m_previousScene != nullptr) {
			// Exit�����s
			m_previousScene->Exit();
		}

		// �V�����V�[����Enter�����s
		m_currentScene->Enter();
	}

	// �V�[���̍X�V
	m_currentScene->Update();
}

template<IsScene T>
void SceneStateMachine::Register(std::unique_ptr<IScene> instance) {
	m_scenes[typeid(T)] = instance;
}

template<IsScene T>
void SceneStateMachine::Unregister(std::unique_ptr<IScene> instance) {

}
