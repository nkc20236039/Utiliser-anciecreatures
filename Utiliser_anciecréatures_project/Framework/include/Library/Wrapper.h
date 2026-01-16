#pragma once

#include <vector>
#include <string>

#include "InputMap.h"
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

enum class ResolutionMode {
	Native,
	Desktop,
	Maximum,
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

	static const Color White() { return Color(1.0f, 1.0f, 1.0f, 1.0f); }
	static const Color Black() { return Color(0.0f, 0.0f, 0.0f, 1.0f); }
	static const Color Red() { return Color(1.0f, 0.0f, 0.0f, 1.0f); }
	static const Color Green() { return Color(0.0f, 1.0f, 0.0f, 1.0f); }
	static const Color Blue() { return Color(0.0f, 0.0f, 1.0f, 1.0f); }
	static const Color Cyan() { return Color(0.0f, 1.0f, 1.0f, 1.0f); }
	static const Color Magenta() { return Color(1.0f, 0.0f, 1.0f, 1.0f); }
	static const Color Yellow() { return Color(1.0f, 1.0f, 0.0f, 1.0f); }
};

// 使用必須関数
bool Init();
bool Finalize();
bool ProcessMessage();

/* 3D関数 */
// 3D図形描画関係関数
bool SetUseZBuffer3D(bool);
bool SetWriteZBuffer3D(bool);

// カメラ
bool SetCameraNearFar(float, float);
bool SetCameraPositionAndTarget(float3, float3);
bool SetCameraPositionAndTarget(float3, float3, float3);
bool SetCameraPositionAndAngle(float3, float3);
bool SetupCameraPerspective(float);

// モデルの読み込み・複製関係の関数
int LoadModel(std::string);
int DuplicateModel(int);
bool DeleteModel(int);

// モデル描画関数
bool DrawModel(int);

// モデル基本制御関数
bool SetPosition(int, float3);
bool SetScale(int, float3);
bool SetRotation(int, float3);
bool SetVisible(int, bool);
bool SetUseModelZBuffer(int, bool);
bool SetWriteModelZBuffer(int, bool);

/* 一般関数 */
// グラフィックデータ制御
int LoadGraph(std::string);

// 文字描画関係関数
bool DrawString(int, int, std::string, Color, Color = Color(0.0f, 0.0f, 0.0f, 0.0f));

// 画面操作系関数
ChangeScreenResult SetGraphMode(int, int, int);
bool SetFullScreenResolutionMode(ResolutionMode);
bool ClearDrawScreen();
bool ScreenFlip();
bool SetDrawScreen(ScreenTarget);
bool SetBackgroundColor(Color);

// 時間関係の関数
int GetNowCount();

// ウインドウモード関係
ChangeScreenResult ChangeWindowMode(bool);
bool SetMainWindowText(std::string);
bool SetWindowIconId(int);
bool SetWindowSize(int, int);
bool SetWindowSizeExtendRate(double, double rateY = -1.0);

// 入力関係
bool CheckHitKeyAll(InputType);
bool CheckHitKey(KeyCode);
std::vector<KeyCode> GetHitKeyStateAll();
bool SetUseDirectInputFlag(bool);
bool SetMouseDispFlag(bool);
Library::float2 GetMousePoint();
std::vector<MouseButton> GetMouseInputAll();

// マイナー関数
bool SetOutApplicationLogValidFlag(bool);
bool SetWaitVSyncFlag(bool);
}
