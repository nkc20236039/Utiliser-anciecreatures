#pragma once

#include <unordered_map>
#include <typeindex>
#include <memory>

#include <format>

#include "SceneBase.h"
#include "Utility/OutputLog.h"

template <typename T>
concept IsScene = std::is_base_of_v<SceneBase, T>;

class SceneStateMachine {
public:
	SceneStateMachine();
	~SceneStateMachine() = default;

	/// <summary>
	/// 現在のシーンを更新する
	/// </summary>
	void Update();

	/// <summary>
	/// シーンの変更をする
	/// </summary>
	/// <typeparam name="T">変更するシーン型</typeparam>
	template<IsScene T>
	void ChangeScene() {
		// 対象のシーンが存在するかチェック
		if (!m_scenes.contains(typeid(T))) {
			OutputLog::Error(std::format("登録していないシーンへアクセスを試みました。\n{}は登録されていません。", typeid(T).name()));
			return;
		}

		// 前回のシーンを保存
		m_previousScene = m_currentScene;
		// 新しいシーンの設定
		m_currentScene = m_scenes[typeid(T)].get();
	}

	/// <summary>
	/// シーンを登録する
	/// </summary>
	/// <typeparam name="T">登録するシーン型</typeparam>
	/// <param name="instance">登録するシーンのポインタ</param>
	template<IsScene T>
	void Register(std::unique_ptr<SceneBase> instance) {
		// シーンの登録
		m_scenes.try_emplace(typeid(T), std::move(instance));

		// 現在進行中のシーンが未定義の場合
		if (m_currentScene == nullptr) {
			// 登録するシーンを現在のシーンに設定
			m_currentScene = m_scenes[typeid(T)].get();
		}
	}

	/// <summary>
	/// シーンを登録解除する
	/// </summary>
	/// <typeparam name="T">登録解除するシーン型</typeparam>
	template<IsScene T>
	void Unregister() {
		// シーンの登録解除
		m_scenes.erase(typeid(T));
	}

private:
	// 登録されているシーン
	std::unordered_map<std::type_index, std::unique_ptr<SceneBase>> m_scenes;

	// 現在のシーンインスタンス
	SceneBase* m_currentScene;
	// 前回のインスタンス(比較に使用)
	SceneBase* m_previousScene;
};