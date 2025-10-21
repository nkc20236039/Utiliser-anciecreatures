// �V�[���̏�ԊǗ����s���X�e�[�g�}�V�[��
#pragma once

#include <unordered_map>
#include <typeindex>
#include <memory>

#include "IScene.h"

template <typename T>
concept IsScene = std::is_base_of_v<IScene, T>;

class SceneStateMachine {
public:
	SceneStateMachine(std::type_index firstSceneType, std::unique_ptr<IScene> firstSceneInstance);

	/// <summary>
	/// �V�[���̕ύX������
	/// </summary>
	/// <typeparam name="T">�ύX����V�[���^</typeparam>
	template<IsScene T>
	void ChangeState();

	/// <summary>
	/// ���݂̃V�[�����X�V����
	/// </summary>
	void Update();

	/// <summary>
	/// �V�[����o�^����
	/// </summary>
	/// <typeparam name="T">�o�^����V�[���^</typeparam>
	/// <param name="instance">�o�^����V�[���̃|�C���^</param>
	template<IsScene T>
	void Register(std::unique_ptr<IScene> instance);
	/// <summary>
	/// �V�[����o�^��������
	/// </summary>
	/// <typeparam name="T">�o�^��������V�[���^</typeparam>
	/// <param name="instance">�o�^��������V�[���̃|�C���^</param>
	template<IsScene T>
	void Unregister(std::unique_ptr<IScene> instance);

private:
	// �o�^����Ă���V�[��
	std::unordered_map<std::type_index, std::unique_ptr<IScene>> m_scenes;

	// ���݂̃V�[���C���X�^���X
	IScene* m_currentScene;
	// �O��̃C���X�^���X(��r�Ɏg�p)
	IScene* m_previousScene;
};