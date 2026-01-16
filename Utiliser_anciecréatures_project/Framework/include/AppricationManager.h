#pragma once

#include "Singleton.h"

class ApplicationManager : public Singleton<ApplicationManager> {
	friend class Singleton<ApplicationManager>;
public:

private:
	ApplicationManager() = default;
	~ApplicationManager() = default;

	bool m_isHideCursor = false;	// カーソルの非表示フラグ
	bool m_isLockCursor = false;	// カーソルのロックフラグ
};