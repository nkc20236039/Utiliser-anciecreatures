/*********************************************************************
 * file   IScene.h
 * brief  
 * 
 * author nkc20236039
 * created 2025/10/21
 * last_modified 2025/10/22
 *********************************************************************/

﻿#pragma once

class IScene {
public:
	virtual ~IScene() = default;
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
};