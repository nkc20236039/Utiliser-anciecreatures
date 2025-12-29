#include "Library/Wrapper.h"

#include <algorithm>

#include "Converter.h"

int ToDxLibDrawScreen(Library::ScreenTarget screenTarget) {
	switch (screenTarget) {
	case Library::ScreenTarget::Front:
		return DX_SCREEN_FRONT;
	case Library::ScreenTarget::Back:
		return DX_SCREEN_BACK;
	case Library::ScreenTarget::Work:
		return DX_SCREEN_WORK;
	case Library::ScreenTarget::TempFront:
		return DX_SCREEN_TEMPFRONT;
	default:
		return DX_SCREEN_BACK;
	}
}

Library::ChangeScreenResult ToChangeScreenResult(int result) {
	switch (result) {
	case DX_CHANGESCREEN_OK:
		return Library::ChangeScreenResult::Success;
	case DX_CHANGESCREEN_RETURN:
		return Library::ChangeScreenResult::Return;
	case DX_CHANGESCREEN_DEFAULT:
		return Library::ChangeScreenResult::Default;
	case DX_CHANGESCREEN_REFRESHNORMAL:
		return Library::ChangeScreenResult::RefreshNormal;
	default:
		return Library::ChangeScreenResult::Default;
	}
}

int ToDxLibChangeScreen(Library::ChangeScreenResult result) {
	switch (result) {
	case Library::ChangeScreenResult::Success:
		return DX_CHANGESCREEN_OK;
	case Library::ChangeScreenResult::Return:
		return DX_CHANGESCREEN_RETURN;
	case Library::ChangeScreenResult::Default:
		return DX_CHANGESCREEN_DEFAULT;
	case Library::ChangeScreenResult::RefreshNormal:
		return DX_CHANGESCREEN_REFRESHNORMAL;
	default:
		return DX_CHANGESCREEN_DEFAULT;
	}
}

/* Color構造体定義 */
Library::Color::Color(float r, float g, float b, float a) {
	// 0.0~1.0に収まるように入れる
	Library::Color::r = std::clamp(r, 0.0f, 1.0f);
	Library::Color::g = std::clamp(g, 0.0f, 1.0f);
	Library::Color::b = std::clamp(b, 0.0f, 1.0f);
	Library::Color::a = std::clamp(a, 0.0f, 1.0f);
}
Library::Color::Color(float r, float g, float b) {
	// 0.0~1.0に収まるように入れる
	Library::Color::r = std::clamp(r, 0.0f, 1.0f);
	Library::Color::g = std::clamp(g, 0.0f, 1.0f);
	Library::Color::b = std::clamp(b, 0.0f, 1.0f);
	Library::Color::a = 1.0f;
}
unsigned int Library::Color::GetColorCode() {
	// アルファが0であれば0を返す
	if (a <= 0) { return 0; }
	int rCode = static_cast<int>(r * 255.0f);
	int gCode = static_cast<int>(g * 255.0f);
	int bCode = static_cast<int>(b * 255.0f);

	return DxLib::GetColor(rCode, gCode, bCode);
}
/* Color構造体定義終了 */


bool Library::Init() {
	int result = DxLib::DxLib_Init();
	return IsSuccessful(result);
}

bool Library::Finalize() {
	int result = DxLib::DxLib_End();
	return IsSuccessful(result);
}

bool Library::ProcessMessage() {
	int result = DxLib::ProcessMessage();
	return IsSuccessful(result);
}

bool Library::DrawString(int x, int y, char* string, Color color, Color edgeColor) {
	int result = DxLib::DrawString(x, y, string, color.GetColorCode(), edgeColor.GetColorCode());
	return IsSuccessful(result);
}

bool Library::ClearDrawScreen() {
	int result = DxLib::ClearDrawScreen();
	return IsSuccessful(result);
}

bool Library::ScreenFlip() {
	int result = DxLib::ScreenFlip();
	return IsSuccessful(result);
}

bool Library::SetDrawScreen(Library::ScreenTarget screenTarget) {
	int result = DxLib::SetDrawScreen(ToDxLibDrawScreen(screenTarget));
	return IsSuccessful(result);
}

int Library::GetNowCount() {
	return DxLib::GetNowCount();
}

bool Library::SetUseZBuffer3D(bool flag) {
	int result = DxLib::SetUseZBuffer3D(ToDxLibBool(flag));
	return IsSuccessful(result);
}

bool Library::SetWriteZBuffer3D(bool flag) {
	int result = DxLib::SetWriteZBuffer3D(ToDxLibBool(flag));
	return IsSuccessful(result);
}

Library::ChangeScreenResult Library::ChangeWindowMode(bool flag) {
	int result = DxLib::ChangeWindowMode(ToDxLibBool(flag));
	return ToChangeScreenResult(result);
}

bool Library::SetOutApplicationLogValidFlag(bool flag) {
	int result = DxLib::SetOutApplicationLogValidFlag(ToDxLibBool(flag));
	return IsSuccessful(result);
}