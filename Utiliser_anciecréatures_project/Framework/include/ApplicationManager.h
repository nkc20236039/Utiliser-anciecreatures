#pragma once

#include "Singleton.h"
#include "UMath/Structs.h"

class ApplicationManager : public Singleton<ApplicationManager> {
	friend class Singleton<ApplicationManager>;
public:
	void SetCursorToCenter();

	bool GetCursorLockFlag() const { return m_isLockCursor; }

	float2 GetWindowCenter() { return float2(m_windowWidth * 0.5f, m_windowHeight * 0.5f); }

	void SetCursorState(bool isHide = false, bool isLock = false);

	void SetWindowSize(int width, int height, int colorBit);

private:
	ApplicationManager() = default;
	~ApplicationManager() = default;

	int m_windowWidth = 0;
	int m_windowHeight = 0;

	bool m_isHideCursor = false;	// カーソルの非表示フラグ
	bool m_isLockCursor = false;	// カーソルのロックフラグ
};