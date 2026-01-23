#include "InputSystem.h"

#include "ApplicationManager.h"

InputSystem::InputSystem() {
	Library::SetUseDirectInputFlag(true);
}

bool InputSystem::IsKeyDown(Library::KeyCode key) {
	return IsButtonStateMatch(InputData::GetData(key), InputState::Down);
}

bool InputSystem::IsKeyPressing(Library::KeyCode key) {
	return IsButtonStateMatch(InputData::GetData(key), InputState::Pressing);
}

bool InputSystem::IsKeyUp(Library::KeyCode key) {
	return IsButtonStateMatch(InputData::GetData(key), InputState::Up);
}

float InputSystem::GetAxis(Library::KeyCode positive, Library::KeyCode negative) {
	float axis = 0.0f;
	// プラス方向の入力
	if (IsKeyPressing(positive)) {
		axis = 1.0f;
	}
	// マイナス方向の入力
	if (IsKeyPressing(negative)) {
		axis = -1.0f;
	}
	return axis;
}

bool InputSystem::IsMouseButtonDown(Library::MouseButton button) {
	return IsButtonStateMatch(InputData::GetData(button), InputState::Down);
}
bool InputSystem::IsMouseButtonPressing(Library::MouseButton button) {
	return IsButtonStateMatch(InputData::GetData(button), InputState::Pressing);
}
bool InputSystem::IsMouseButtonUp(Library::MouseButton button) {
	return IsButtonStateMatch(InputData::GetData(button), InputState::Up);
}

void InputSystem::Update() {
	// 作業vectorをクリア
	m_newInputTempData.clear();

	// 今回押されているキーボードボタンを作業vectorに入れる
	auto hitKeys = Library::GetHitKeyStateAll();
	for (const auto& key : hitKeys) {
		m_newInputTempData.push_back((InputData::GetData(key)));
	}
	// 今回押されているマウスボタンを作業vectorに入れる
	auto hitMouseButtons = Library::GetMouseInputAll();
	for (const auto& mouseButton : hitMouseButtons) {
		m_newInputTempData.push_back((InputData::GetData(mouseButton)));
	}

	// 以前まで押されていたキーを削除
	std::erase_if(
		m_pressingButtonData,
		[](const InputData& data) {
			return data.GetState() == InputState::Up;
		});

	// 押されているキーの集合と現在押されているキーの集合を作成
	for (auto keyIt = m_pressingButtonData.begin(); keyIt != m_pressingButtonData.end(); keyIt++)	// It = iterator
	{
		// 該当のキーが今回の更新で押されたボタンリストからなくなった場合
		auto upStateIt = std::find_if(
			m_newInputTempData.begin(),
			m_newInputTempData.end(),
			[&keyIt](const InputData& data) {
				return data == *keyIt;
			});
		if (upStateIt == m_newInputTempData.end())
		{
			// ボタンを離した状態へ変更
			keyIt->SetState(InputState::Up);
			continue;	// 次のキーへ
		}

		// InputState::DownをPressingに変更して保存
		if (keyIt->GetState() == InputState::Down)
		{
			keyIt->SetState(InputState::Pressing);
		}

		// 既に押されているキーを作業vectorから削除
		// * この行ではm_pressingButtonDataに存在しているデータが
		// * m_newInputTempDataにも存在することが保証されるため削除可能
		std::erase(m_newInputTempData, *keyIt);
	}

	// 新たに押されたキーを追加
	for (const auto& newInput : m_newInputTempData)
	{
		// 新たに押されたキーを追加
		m_pressingButtonData.push_back(newInput);
	}
}
bool InputSystem::IsButtonStateMatch(InputData id, InputState state) {
	// 現在押されているキーの中から該当するものを線形探索
	// * 要素が少ないことが想定されるため線形探索で十分と判断
	for (auto& pressingData : m_pressingButtonData) {
		if (pressingData.IsStateMatch(id, state)) {
			return true;
		}
	}
	return false;
}

float2 InputSystem::GetMouseDelta() {
	// 現在のマウス座標を取得する
	float2 currentMousePoint = Library::GetMousePoint();

	if (ApplicationManager::GetInstance().GetCursorLockFlag()) {
		// マウスカーソルがロックされていない場合
		float2 delta = currentMousePoint - ApplicationManager::GetInstance().GetWindowCenter();
		return delta;
	}
	else {
		// マウスカーソルがロックされていない場合
		float2 delta = currentMousePoint - m_previousMousePoint;
		m_previousMousePoint = currentMousePoint;
		return delta;
	}
}