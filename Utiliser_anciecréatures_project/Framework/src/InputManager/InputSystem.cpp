#include "InputSystem.h"

bool InputSystem::IsKeyDown(Library::KeyCode key) {
	return m_pressedKeys.contains(key);
}

bool InputSystem::IsKeyPressing(Library::KeyCode key) {
	return m_pressingKeys.contains(key);
}

bool InputSystem::IsKeyUp(Library::KeyCode key) {
	return m_canceledKeys.contains(key);
}

int InputSystem::GetAxis(Library::KeyCode positive, Library::KeyCode negative) {
	int axis = 0;
	if (IsKeyPressing(positive)) {
		axis += 1;
	}
	if (IsKeyPressing(negative)) {
		axis -= 1;
	}
	return axis;
}

void InputSystem::Update() {
	// 押されたキーの取得
	auto hitKeys = Library::GetHitKeyStateAll();

	// 押されているキーの集合と現在押されているキーの集合を作成
	std::unordered_set<Library::KeyCode> newKeyState(hitKeys.begin(), hitKeys.end());

	// 前回の保存状態をクリア
	m_pressedKeys.clear();
	m_canceledKeys.clear();

	// 今回押されたキーの更新
	for (const auto& key : newKeyState) {
		// 現在押されているキーに存在しない場合はm_pressedKeysに追加
		if (!m_pressingKeys.contains(key)) {
			m_pressedKeys.emplace(key);
		}
	}

	// 今回離されたキーの更新
	for (const auto& key : m_pressingKeys) {
		if (!newKeyState.contains(key)) {
			m_canceledKeys.emplace(key);
		}
	}

	// 現在押されているキーの更新
	m_pressingKeys.clear();
	m_pressingKeys.insert(hitKeys.begin(), hitKeys.end());
}