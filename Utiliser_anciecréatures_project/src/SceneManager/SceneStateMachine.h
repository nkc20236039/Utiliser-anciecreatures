﻿#pragma once

#include <unordered_map>
#include <typeindex>
#include <memory>

#include "IScene.h"

template <typename T>
concept IsScene = std::is_base_of_v<IScene, T>;

class SceneStateMachine {
public:
	SceneStateMachine();

	/// <summary>
	/// シーンの変更をする
	/// </summary>
	/// <typeparam name="T">変更するシーン型</typeparam>
	template<IsScene T>
	void ChangeState();

	/// <summary>
	/// 現在のシーンを更新する
	/// </summary>
	void Update();

	/// <summary>
	/// シーンを登録する
	/// </summary>
	/// <typeparam name="T">登録するシーン型</typeparam>
	/// <param name="instance">登録するシーンのポインタ</param>
	template<IsScene T>
	void Register(std::unique_ptr<IScene> instance);
	/// <summary>
	/// シーンを登録解除する
	/// </summary>
	/// <typeparam name="T">登録解除するシーン型</typeparam>
	/// <param name="instance">登録解除するシーンのポインタ</param>
	template<IsScene T>
	void Unregister(std::unique_ptr<IScene> instance);

private:
	// 登録されているシーン
	std::unordered_map<std::type_index, std::unique_ptr<IScene>> m_scenes;

	// 現在のシーンインスタンス
	IScene* m_currentScene;
	// 前回のインスタンス(比較に使用)
	IScene* m_previousScene;
};