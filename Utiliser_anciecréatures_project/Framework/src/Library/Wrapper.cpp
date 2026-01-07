#include "Library/Wrapper.h"

#include <algorithm>

#include "Converter.h"

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

// 使用必須関数
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

/* 3D関数 */
// 3D図形描画関係関数
bool Library::SetUseZBuffer3D(bool flag) {
	int result = DxLib::SetUseZBuffer3D(ToDxLibBool(flag));
	return IsSuccessful(result);
}

bool Library::SetWriteZBuffer3D(bool flag) {
	int result = DxLib::SetWriteZBuffer3D(ToDxLibBool(flag));
	return IsSuccessful(result);
}

// モデルの読み込み・複製関係の関数
int Library::LoadModel(std::string fileName) {
	return DxLib::MV1LoadModel(fileName.c_str());
}

int Library::DuplicateModel(int modelHandle) {
	return DxLib::MV1DuplicateModel(modelHandle);
}

bool Library::DeleteModel(int modelHandle) {
	int result = DxLib::MV1DeleteModel(modelHandle);
	return IsSuccessful(result);
}

bool Library::DrawModel(int modelHandle) {
	int result = DxLib::MV1DrawModel(modelHandle);
	return IsSuccessful(result);
}

/* 一般関数 */
// 文字描画関係関数
bool Library::DrawString(int x, int y, std::string string, Color color, Color edgeColor) {
	int result = DxLib::DrawString(x, y, string.c_str(), color.GetColorCode(), edgeColor.GetColorCode());
	return IsSuccessful(result);
}

// 画面操作系関数
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

bool Library::SetBackgroundColor(Library::Color color) {
	int result = DxLib::SetBackgroundColor(
		static_cast<int>(color.r * 255.0f),
		static_cast<int>(color.g * 255.0f),
		static_cast<int>(color.b * 255.0f));
	return IsSuccessful(result);
}

// 時間関係の関数
int Library::GetNowCount() {
	return DxLib::GetNowCount();
}

// ウインドウモード関係
Library::ChangeScreenResult Library::ChangeWindowMode(bool flag) {
	int result = DxLib::ChangeWindowMode(ToDxLibBool(flag));
	return ToChangeScreenResult(result);
}

// 入力関係
bool Library::CheckHitKeyAll(Library::InputType inputType) {
	int result = DxLib::CheckHitKeyAll(ToDxLibCheckInput(inputType));
	return IsSuccessful(result);
}

bool Library::CheckHitKey(Library::KeyCode keyCode) {
	int result = DxLib::CheckHitKey(ToDxLibKeyCode(keyCode));
	return IsSuccessful(result);
}

constexpr int KEY_BUFFER_SIZE = 256;
std::vector<Library::KeyCode> Library::GetHitKeyStateAll() {
	// 出力用の押されているキーを格納するベクター
	std::vector<Library::KeyCode> hitKeys;
	hitKeys.reserve(KEY_BUFFER_SIZE);
	// DXライブラリー用のキーを格納する配列
	char keyBuffer[KEY_BUFFER_SIZE];

	// 全てのキーの状態を取得
	DxLib::GetHitKeyStateAll(keyBuffer);

	for (int key = 0; key < KEY_BUFFER_SIZE; ++key) {
		// 押されているキーだけを格納
		if (keyBuffer[key] == 1) {
			hitKeys.push_back(ToLibraryKeyCode(key));
		}
	}

	return hitKeys;
}

// マイナー関数
bool Library::SetOutApplicationLogValidFlag(bool flag) {
	int result = DxLib::SetOutApplicationLogValidFlag(ToDxLibBool(flag));
	return IsSuccessful(result);
}
