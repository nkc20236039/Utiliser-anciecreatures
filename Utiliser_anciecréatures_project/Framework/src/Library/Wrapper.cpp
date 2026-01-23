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

// カメラ
bool Library::SetCameraNearFar(float nearClip, float farClip) {
	int result = DxLib::SetCameraNearFar(nearClip, farClip);
	return IsSuccessful(result);
}
bool Library::SetCameraPositionAndTarget(float3 position, float3 target) {
	int result = DxLib::SetCameraPositionAndTarget_UpVecY(
		ToDxLibVector(position),
		ToDxLibVector(target));
	return IsSuccessful(result);
}
bool Library::SetCameraPositionAndTarget(float3 position, float3 target, float3 up) {
	int result = DxLib::SetCameraPositionAndTargetAndUpVec(
		ToDxLibVector(position),
		ToDxLibVector(target),
		ToDxLibVector(up));
	return IsSuccessful(result);
}
bool Library::SetCameraPositionAndAngle(float3 position, Quaternion rotate) {
	float3 angle = rotate.Euler();
	int result = DxLib::SetCameraPositionAndAngle(
		ToDxLibVector(position),
		angle.x,
		angle.y,
		angle.z);
	return IsSuccessful(result);
}
bool Library::SetupCameraPerspective(float fov) {
	int ressult = DxLib::SetupCamera_Perspective(fov);
	return IsSuccessful(ressult);
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

// モデル描画関数
bool Library::DrawModel(int modelHandle) {
	int result = DxLib::MV1DrawModel(modelHandle);
	return IsSuccessful(result);
}

// モデル基本制御関数
bool Library::SetPosition(int handle, float3 position) {
	int result = DxLib::MV1SetPosition(handle, ToDxLibVector(position));
	return IsSuccessful(result);
}
bool Library::SetScale(int handle, float3 scale) {
	int result = DxLib::MV1SetScale(handle, ToDxLibVector(scale));
	return IsSuccessful(result);
}
bool Library::SetRotation(int handle, Quaternion rotation) {
	int result = DxLib::MV1SetRotationXYZ(handle, ToDxLibVector(rotation.Euler()));
	return IsSuccessful(result);
}
bool Library::SetVisible(int handle, bool isVisible) {
	int result = DxLib::MV1SetVisible(handle, ToDxLibBool(isVisible));
	return IsSuccessful(result);
}
bool Library::SetUseModelZBuffer(int handle, bool isUseZBuffer) {
	int result = DxLib::MV1SetUseZBuffer(handle, ToDxLibBool(isUseZBuffer));
	return IsSuccessful(result);
}
bool Library::SetWriteModelZBuffer(int handle, bool isWriteZBuffer) {
	int result = DxLib::MV1SetUseZBuffer(handle, ToDxLibBool(isWriteZBuffer));
	return IsSuccessful(result);
}

/* 一般関数 */
// グラフィックデータ制御
int Library::LoadGraph(std::string path) {
	return DxLib::LoadGraph(path.c_str());
}

// 文字描画関係関数
bool Library::DrawString(int x, int y, std::string string, Color color, Color edgeColor) {
	int result = DxLib::DrawString(x, y, string.c_str(), color.GetColorCode(), edgeColor.GetColorCode());
	return IsSuccessful(result);
}

// 画面操作系関数
Library::ChangeScreenResult Library::SetGraphMode(int sizeX, int sizeY, int colorBit) {
	int result = DxLib::SetGraphMode(sizeX, sizeY, colorBit);
	return ToChangeScreenResult(result);
}

bool Library::SetFullScreenResolutionMode(ResolutionMode mode) {
	int result = DxLib::SetFullScreenResolutionMode(ToDxLibResolutionMode(mode));
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

bool Library::SetMainWindowText(std::string title) {
	int result = DxLib::SetMainWindowText(title.c_str());
	return IsSuccessful(result);
}

bool Library::SetWindowIconId(int id) {
	int result = DxLib::SetWindowIconID(id);
	return IsSuccessful(result);
}

bool Library::SetWindowSize(int width, int height) {
	int result = DxLib::SetWindowSize(width, height);
	return IsSuccessful(result);
}

bool Library::SetWindowSizeExtendRate(double rateX, double rateY) {
	int result = DxLib::SetWindowSizeExtendRate(rateX);
	return IsSuccessful(result);
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

bool Library::SetUseDirectInputFlag(bool flag) {
	int result = DxLib::SetUseDirectInputFlag(ToDxLibBool(flag));
	return IsSuccessful(result);
}

bool Library::SetMouseDispFlag(bool flag) {
	int result = DxLib::SetMouseDispFlag(ToDxLibBool(flag));
	return IsSuccessful(result);
}

float2 Library::GetMousePoint() {
	int x, y;
	int result = DxLib::GetMousePoint(&x, &y);

	// ライブラリの戻り値が正常なら座標を返す
	if (IsSuccessful(result)) {
		return float2(static_cast<float>(x), static_cast<float>(y));
	}
	else {
		// 異常終了ならゼロベクトルを返す
		return float2::Zero();
	}
}

bool Library::SetMousePoint(float2 point) {
	int result = DxLib::SetMousePoint(static_cast<int>(point.x), static_cast<int>(point.y));
	return IsSuccessful(result);
}

std::vector<Library::MouseButton> Library::GetMouseInputAll() {
	int mouseState = DxLib::GetMouseInput();
	std::vector<Library::MouseButton> hitMouseButtons;

	// 各ビットをチェックして押されているボタンを格納
	for (int i = 0; i < static_cast<int>(Library::MouseButton::None); i++) {
		if ((mouseState & (1 << i)) != 0) {
			hitMouseButtons.push_back(static_cast<Library::MouseButton>(i));
		}
	}

	return hitMouseButtons;
}

// マイナー関数
bool Library::SetOutApplicationLogValidFlag(bool flag) {
	int result = DxLib::SetOutApplicationLogValidFlag(ToDxLibBool(flag));
	return IsSuccessful(result);
}

bool Library::SetWaitVSyncFlag(bool flag) {
	int result = DxLib::SetWaitVSyncFlag(ToDxLibBool(flag));
	return IsSuccessful(result);
}
