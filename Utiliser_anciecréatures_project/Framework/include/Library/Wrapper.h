#pragma once

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

bool Init();
bool Finalize();
bool ProcessMessage();

bool SetDrawScreen(ScreenTarget);
bool SetUseZBuffer3D(bool);
bool SetWriteZBuffer3D(bool);

ChangeScreenResult ChangeWindowMode(bool);
bool SetOutApplicationLogValidFlag(bool);
}
