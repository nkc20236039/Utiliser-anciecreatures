#pragma once

#include <memory>

#include "MathWrapper.h"

namespace Library {
enum class ScreenTarget {
	Front,
	Back,
	Work,
	TempFront,
	Other
};

enum class ChangeScreenResult {
	Success,
	Return,
	Default,
	RefreshNormal,
};

struct Color {
public:
	float r, g, b, a;

	Color(int r, int g, int b, int a)
		: r(static_cast<float>(r) / 255.0f),
		g(static_cast<float>(g) / 255.0f),
		b(static_cast<float>(b) / 255.0f),
		a(static_cast<float>(a) / 255.0f) {}
	Color(int r, int g, int b)
		: r(static_cast<float>(r) / 255.0f),
		g(static_cast<float>(g) / 255.0f),
		b(static_cast<float>(b) / 255.0f),
		a(1.0f) {}
	Color(float r, float g, float b, float a);
	Color(float r, float g, float b);

	unsigned int GetColorCode();
};

// 使用必須関数
bool Init();
bool Finalize();
bool ProcessMessage();

/* 3D関数 */
//  3D図形描画関係関数
bool SetUseZBuffer3D(bool);
bool SetWriteZBuffer3D(bool);

// 文字描画関係関数
bool DrawString(int, int, char*, Color, Color = Color(0.0f, 0.0f, 0.0f, 0.0f));

// 画面操作系関数
bool ClearDrawScreen();
bool ScreenFlip();
bool SetDrawScreen(ScreenTarget);

// 時間関係の関数
int GetNowCount();

// ウインドウモード関係
ChangeScreenResult ChangeWindowMode(bool);

// マイナー関数
bool SetOutApplicationLogValidFlag(bool);
}
