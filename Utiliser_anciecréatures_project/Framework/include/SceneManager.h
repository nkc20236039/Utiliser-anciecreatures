#pragma once

#include <memory>
#include <functional>

#include "Singleton.h"
#include "GameFrame.h"
#include "SceneBase.h"

template<typename T>
concept IsScene = std::is_base_of_v<SceneBase, T>;

class SceneManager : public Singleton<SceneManager> {
	friend class Singleton<SceneManager>;	// シングルトンでは生成を許可

public:
	/// <summary>
	/// シーンを変更する
	/// </summary>
	/// <typeparam name="T">次のシーン</typeparam>
	template<IsScene T>
	void ChangeScene() {
		m_nextSceneFactory = []() {
			return std::make_unique<T>();
			};
	}

	/// <summary>
	/// シーンの更新を行う
	/// </summary>
	void Update(const Time& time);

private:
	SceneManager() = default;
	~SceneManager() = default;

	std::unique_ptr<SceneBase> m_currentScene;				// 現在のシーン
	std::function<std::unique_ptr<SceneBase>()> m_nextSceneFactory;	// 次のシーンを生成する関数
};