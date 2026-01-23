#include "InputManager.h"

#include "InputSystem.h"

void InputManager::Update() {
	// InputSystemの更新を行う
	InputSystem::GetInstance().Update();
}
