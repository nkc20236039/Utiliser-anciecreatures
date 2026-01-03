#pragma once

#include <vector>
#include <unordered_set>

#include "Library/Wrapper.h"
#include "src/System/Singleton.h"

class InputSystem : public Singleton<InputSystem> {
	friend class Singleton<InputSystem>;
	friend class InputManager;

public:
	/// <summary>
	/// 対象のキーが押した瞬間であるか判定する
	/// </summary>
	bool IsKeyDown(Library::KeyCode key);
	/// <summary>
	/// 対象のキーを押している状態であるか判定する
	/// </summary>
	bool IsKeyPressing(Library::KeyCode key);
	/// <summary>
	/// 対象のキーが離された瞬間であるか判定する
	/// </summary>
	bool IsKeyUp(Library::KeyCode key);
	/// <summary>
	/// 2つのキーから入力方向を取得する
	/// </summary>
	/// <param name="positive">プラス方向の入力キー</param>
	/// <param name="negative">マイナス方向の入力キー</param>
	/// <returns></returns>
	int GetAxis(Library::KeyCode positive, Library::KeyCode negative);
private:
	InputSystem() = default;
	~InputSystem() = default;

	std::unordered_set<Library::KeyCode> m_pressedKeys;
	std::unordered_set<Library::KeyCode> m_pressingKeys;
	std::unordered_set<Library::KeyCode> m_canceledKeys;

	/// <summary>
	/// 入力状態の更新を行う
	/// </summary>
	void Update();	// InputManagerから呼び出される
};