#pragma once

#include "GameObject/GameObject.h"

class SceneBase {
public:
	virtual ~SceneBase() = default;
	/// <summary>
	/// シーンの初期化を行う
	/// </summary>
	virtual void Enter() = 0;
	/// <summary>
	/// シーンの更新を行う
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// シーンの終了処理を行う
	/// </summary>
	virtual void Exit() = 0;

private:
	
};