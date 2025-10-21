// �V�[���̏�ԊǗ����s���X�e�[�g�}�V�[��
#pragma once

#include <unordered_map>
#include <typeinfo>
#include <memory>

#include "IScene.h"

template <typename T>
concept IsScene = std::is_base_of_v<IScene, T>;

class SceneStateMachine {
public:
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
	void Register(std::unique_ptr<T> instance);
	/// <summary>
	/// �V�[����o�^��������
	/// </summary>
	/// <typeparam name="T">�o�^��������V�[���^</typeparam>
	/// <param name="instance">�o�^��������V�[���̃|�C���^</param>
	template<IsScene T>
	void Unregister(std::unique_ptr<T> instance);

private:
	// �o�^����Ă���V�[��
	std::unordered_map<std::type_info, std::unique_ptr<IScene>> m_scenes;

	// ���݂̃V�[���C���X�^���X
	IScene& m_currentScene;
};