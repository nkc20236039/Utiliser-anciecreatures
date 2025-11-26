#pragma once

#include "GameObject/Manager/GameObjectManager.h"

class SceneBase {
public:
	virtual ~SceneBase() = default;
	/// <summary>
	/// シーンの初期化を行う
	/// </summary>
	virtual void Enter() = 0;
	/// <summary>
	/// シーンの終了処理を行う
	/// </summary>
	virtual void Exit() = 0;
	/// <summary>
	/// シーン内のゲームオブジェクトを更新する
	/// </summary>
	void UpdateGameObjects();

protected:
	// シーン内のゲームオブジェクトリスト
	GameObjectManager m_gameObjectManager;
};