#include "ApplicationManager.h"

#include "Library/Wrapper.h"

void ApplicationManager::SetCursorState(bool isHide, bool isLock) {
	m_isHideCursor = isHide;
	m_isLockCursor = isLock;

	Library::SetMouseDispFlag(!isHide);
}

void ApplicationManager::SetCursorToCenter() {
	Library::SetMousePoint(GetWindowCenter());
}

void ApplicationManager::SetWindowSize(int width, int height, int colorBit) {
	// ウィンドウ設定
	Library::SetGraphMode(width, height, colorBit);
	Library::SetWindowSize(width, height);

	// 値を保存
	m_windowWidth = width;
	m_windowHeight = height;
}
