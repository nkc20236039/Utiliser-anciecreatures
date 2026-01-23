#pragma once

#include <DxLib.h>
#include "Library/InputMap.h"

inline int ToDxLibBool(bool flag) {
	return flag ? TRUE : FALSE;
}

inline bool IsSuccessful(int result) {
	return result == 0;
}

inline DxLib::VECTOR ToDxLibVector(const float3& vec) {
	DxLib::VECTOR dxVec;
	dxVec.x = vec.x;
	dxVec.y = vec.y;
	dxVec.z = vec.z;
	return dxVec;
}

inline int ToDxLibDrawScreen(Library::ScreenTarget screenTarget) {
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

inline Library::ChangeScreenResult ToChangeScreenResult(int result) {
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

inline int ToDxLibCheckInput(Library::InputType inputType) {
	switch (inputType) {
	case Library::InputType::Keyboard:
		return DX_CHECKINPUT_KEY;
	case Library::InputType::Mouse:
		return DX_CHECKINPUT_MOUSE;
	case Library::InputType::Pad:
		return DX_CHECKINPUT_PAD;
	case Library::InputType::All:
		return DX_CHECKINPUT_ALL;
	default:
		return DX_CHECKINPUT_ALL;
	}
}

inline int ToDxLibResolutionMode(Library::ResolutionMode mode) {
	switch (mode) {
	case Library::ResolutionMode::Native:
		return DX_FSRESOLUTIONMODE_NATIVE;
	case Library::ResolutionMode::Desktop:
		return DX_FSRESOLUTIONMODE_DESKTOP;
	case Library::ResolutionMode::Maximum:
		return DX_FSRESOLUTIONMODE_MAXIMUM;
	default:
		return DX_FSRESOLUTIONMODE_NATIVE;
	}
}

inline int ToDxLibKeyCode(Library::KeyCode input) {
	switch (input) {
	case Library::KeyCode::Back:
		return KEY_INPUT_BACK;
	case Library::KeyCode::Tab:
		return KEY_INPUT_TAB;
	case Library::KeyCode::Return:
		return KEY_INPUT_RETURN;
	case Library::KeyCode::LShift:
		return KEY_INPUT_LSHIFT;
	case Library::KeyCode::RShift:
		return KEY_INPUT_RSHIFT;
	case Library::KeyCode::LControl:
		return KEY_INPUT_LCONTROL;
	case Library::KeyCode::RControl:
		return KEY_INPUT_RCONTROL;
	case Library::KeyCode::Escape:
		return KEY_INPUT_ESCAPE;
	case Library::KeyCode::Space:
		return KEY_INPUT_SPACE;
	case Library::KeyCode::PgUp:
		return KEY_INPUT_PGUP;
	case Library::KeyCode::PgDn:
		return KEY_INPUT_PGDN;
	case Library::KeyCode::End:
		return KEY_INPUT_END;
	case Library::KeyCode::Home:
		return KEY_INPUT_HOME;
	case Library::KeyCode::Left:
		return KEY_INPUT_LEFT;
	case Library::KeyCode::Up:
		return KEY_INPUT_UP;
	case Library::KeyCode::Right:
		return KEY_INPUT_RIGHT;
	case Library::KeyCode::Down:
		return KEY_INPUT_DOWN;
	case Library::KeyCode::Insert:
		return KEY_INPUT_INSERT;
	case Library::KeyCode::Delete:
		return KEY_INPUT_DELETE;
	case Library::KeyCode::Minus:
		return KEY_INPUT_MINUS;
	case Library::KeyCode::Yen:
		return KEY_INPUT_YEN;
	case Library::KeyCode::Prevtrack:
		return KEY_INPUT_PREVTRACK;
	case Library::KeyCode::Period:
		return KEY_INPUT_PERIOD;
	case Library::KeyCode::Slash:
		return KEY_INPUT_SLASH;
	case Library::KeyCode::LAlt:
		return KEY_INPUT_LALT;
	case Library::KeyCode::RAlt:
		return KEY_INPUT_RALT;
	case Library::KeyCode::Scroll:
		return KEY_INPUT_SCROLL;
	case Library::KeyCode::Semicolon:
		return KEY_INPUT_SEMICOLON;
	case Library::KeyCode::Colon:
		return KEY_INPUT_COLON;
	case Library::KeyCode::LBracket:
		return KEY_INPUT_LBRACKET;
	case Library::KeyCode::RBracket:
		return KEY_INPUT_RBRACKET;
	case Library::KeyCode::At:
		return KEY_INPUT_AT;
	case Library::KeyCode::BackSlash:
		return KEY_INPUT_BACKSLASH;
	case Library::KeyCode::Comma:
		return KEY_INPUT_COMMA;
	case Library::KeyCode::Kanji:
		return KEY_INPUT_KANJI;
	case Library::KeyCode::Convert:
		return KEY_INPUT_CONVERT;
	case Library::KeyCode::Noconvert:
		return KEY_INPUT_NOCONVERT;
	case Library::KeyCode::Kana:
		return KEY_INPUT_KANA;
	case Library::KeyCode::Apps:
		return KEY_INPUT_APPS;
	case Library::KeyCode::Capslock:
		return KEY_INPUT_CAPSLOCK;
	case Library::KeyCode::Sysrq:
		return KEY_INPUT_SYSRQ;
	case Library::KeyCode::Pause:
		return KEY_INPUT_PAUSE;
	case Library::KeyCode::LWin:
		return KEY_INPUT_LWIN;
	case Library::KeyCode::RWin:
		return KEY_INPUT_RWIN;
	case Library::KeyCode::Numlock:
		return KEY_INPUT_NUMLOCK;
	case Library::KeyCode::Numpad0:
		return KEY_INPUT_NUMPAD0;
	case Library::KeyCode::Numpad1:
		return KEY_INPUT_NUMPAD1;
	case Library::KeyCode::Numpad2:
		return KEY_INPUT_NUMPAD2;
	case Library::KeyCode::Numpad3:
		return KEY_INPUT_NUMPAD3;
	case Library::KeyCode::Numpad4:
		return KEY_INPUT_NUMPAD4;
	case Library::KeyCode::Numpad5:
		return KEY_INPUT_NUMPAD5;
	case Library::KeyCode::Numpad6:
		return KEY_INPUT_NUMPAD6;
	case Library::KeyCode::Numpad7:
		return KEY_INPUT_NUMPAD7;
	case Library::KeyCode::Numpad8:
		return KEY_INPUT_NUMPAD8;
	case Library::KeyCode::Numpad9:
		return KEY_INPUT_NUMPAD9;
	case Library::KeyCode::Multiply:
		return KEY_INPUT_MULTIPLY;
	case Library::KeyCode::Add:
		return KEY_INPUT_ADD;
	case Library::KeyCode::Subtract:
		return KEY_INPUT_SUBTRACT;
	case Library::KeyCode::Decimal:
		return KEY_INPUT_DECIMAL;
	case Library::KeyCode::Divide:
		return KEY_INPUT_DIVIDE;
	case Library::KeyCode::NumpadEnter:
		return KEY_INPUT_NUMPADENTER;
	case Library::KeyCode::F1:
		return KEY_INPUT_F1;
	case Library::KeyCode::F2:
		return KEY_INPUT_F2;
	case Library::KeyCode::F3:
		return KEY_INPUT_F3;
	case Library::KeyCode::F4:
		return KEY_INPUT_F4;
	case Library::KeyCode::F5:
		return KEY_INPUT_F5;
	case Library::KeyCode::F6:
		return KEY_INPUT_F6;
	case Library::KeyCode::F7:
		return KEY_INPUT_F7;
	case Library::KeyCode::F8:
		return KEY_INPUT_F8;
	case Library::KeyCode::F9:
		return KEY_INPUT_F9;
	case Library::KeyCode::F10:
		return KEY_INPUT_F10;
	case Library::KeyCode::F11:
		return KEY_INPUT_F11;
	case Library::KeyCode::F12:
		return KEY_INPUT_F12;
	case Library::KeyCode::A:
		return KEY_INPUT_A;
	case Library::KeyCode::B:
		return KEY_INPUT_B;
	case Library::KeyCode::C:
		return KEY_INPUT_C;
	case Library::KeyCode::D:
		return KEY_INPUT_D;
	case Library::KeyCode::E:
		return KEY_INPUT_E;
	case Library::KeyCode::F:
		return KEY_INPUT_F;
	case Library::KeyCode::G:
		return KEY_INPUT_G;
	case Library::KeyCode::H:
		return KEY_INPUT_H;
	case Library::KeyCode::I:
		return KEY_INPUT_I;
	case Library::KeyCode::J:
		return KEY_INPUT_J;
	case Library::KeyCode::K:
		return KEY_INPUT_K;
	case Library::KeyCode::L:
		return KEY_INPUT_L;
	case Library::KeyCode::M:
		return KEY_INPUT_M;
	case Library::KeyCode::N:
		return KEY_INPUT_N;
	case Library::KeyCode::O:
		return KEY_INPUT_O;
	case Library::KeyCode::P:
		return KEY_INPUT_P;
	case Library::KeyCode::Q:
		return KEY_INPUT_Q;
	case Library::KeyCode::R:
		return KEY_INPUT_R;
	case Library::KeyCode::S:
		return KEY_INPUT_S;
	case Library::KeyCode::T:
		return KEY_INPUT_T;
	case Library::KeyCode::U:
		return KEY_INPUT_U;
	case Library::KeyCode::V:
		return KEY_INPUT_V;
	case Library::KeyCode::W:
		return KEY_INPUT_W;
	case Library::KeyCode::X:
		return KEY_INPUT_X;
	case Library::KeyCode::Y:
		return KEY_INPUT_Y;
	case Library::KeyCode::Z:
		return KEY_INPUT_Z;
	case Library::KeyCode::Alpha0:
		return KEY_INPUT_0;
	case Library::KeyCode::Alpha1:
		return KEY_INPUT_1;
	case Library::KeyCode::Alpha2:
		return KEY_INPUT_2;
	case Library::KeyCode::Alpha3:
		return KEY_INPUT_3;
	case Library::KeyCode::Alpha4:
		return KEY_INPUT_4;
	case Library::KeyCode::Alpha5:
		return KEY_INPUT_5;
	case Library::KeyCode::Alpha6:
		return KEY_INPUT_6;
	case Library::KeyCode::Alpha7:
		return KEY_INPUT_7;
	case Library::KeyCode::Alpha8:
		return KEY_INPUT_8;
	case Library::KeyCode::Alpha9:
		return KEY_INPUT_9;
	default:
		return 0;
	}
}

inline Library::KeyCode ToLibraryKeyCode(int input) {
	switch (input) {
	case  KEY_INPUT_BACK:
		return Library::KeyCode::Back;
	case KEY_INPUT_TAB:
		return Library::KeyCode::Tab;
	case KEY_INPUT_RETURN:
		return Library::KeyCode::Return;
	case KEY_INPUT_LSHIFT:
		return Library::KeyCode::LShift;
	case KEY_INPUT_RSHIFT:
		return Library::KeyCode::RShift;
	case KEY_INPUT_LCONTROL:
		return Library::KeyCode::LControl;
	case KEY_INPUT_RCONTROL:
		return Library::KeyCode::RControl;
	case KEY_INPUT_ESCAPE:
		return Library::KeyCode::Escape;
	case KEY_INPUT_SPACE:
		return Library::KeyCode::Space;
	case KEY_INPUT_PGUP:
		return Library::KeyCode::PgUp;
	case KEY_INPUT_PGDN:
		return Library::KeyCode::PgDn;
	case KEY_INPUT_END:
		return Library::KeyCode::End;
	case KEY_INPUT_HOME:
		return Library::KeyCode::Home;
	case KEY_INPUT_LEFT:
		return Library::KeyCode::Left;
	case KEY_INPUT_UP:
		return Library::KeyCode::Up;
	case KEY_INPUT_RIGHT:
		return Library::KeyCode::Right;
	case KEY_INPUT_DOWN:
		return Library::KeyCode::Down;
	case KEY_INPUT_INSERT:
		return Library::KeyCode::Insert;
	case KEY_INPUT_DELETE:
		return Library::KeyCode::Delete;
	case KEY_INPUT_MINUS:
		return Library::KeyCode::Minus;
	case KEY_INPUT_YEN:
		return Library::KeyCode::Yen;
	case KEY_INPUT_PREVTRACK:
		return Library::KeyCode::Prevtrack;
	case KEY_INPUT_PERIOD:
		return Library::KeyCode::Period;
	case KEY_INPUT_SLASH:
		return Library::KeyCode::Slash;
	case KEY_INPUT_LALT:
		return Library::KeyCode::LAlt;
	case KEY_INPUT_RALT:
		return Library::KeyCode::RAlt;
	case KEY_INPUT_SCROLL:
		return Library::KeyCode::Scroll;
	case KEY_INPUT_SEMICOLON:
		return Library::KeyCode::Semicolon;
	case KEY_INPUT_COLON:
		return Library::KeyCode::Colon;
	case KEY_INPUT_LBRACKET:
		return Library::KeyCode::LBracket;
	case KEY_INPUT_RBRACKET:
		return Library::KeyCode::RBracket;
	case KEY_INPUT_AT:
		return Library::KeyCode::At;
	case KEY_INPUT_BACKSLASH:
		return Library::KeyCode::BackSlash;
	case KEY_INPUT_COMMA:
		return Library::KeyCode::Comma;
	case KEY_INPUT_KANJI:
		return Library::KeyCode::Kanji;
	case KEY_INPUT_CONVERT:
		return Library::KeyCode::Convert;
	case KEY_INPUT_NOCONVERT:
		return Library::KeyCode::Noconvert;
	case KEY_INPUT_KANA:
		return Library::KeyCode::Kana;
	case KEY_INPUT_APPS:
		return Library::KeyCode::Apps;
	case KEY_INPUT_CAPSLOCK:
		return Library::KeyCode::Capslock;
	case KEY_INPUT_SYSRQ:
		return Library::KeyCode::Sysrq;
	case KEY_INPUT_PAUSE:
		return Library::KeyCode::Pause;
	case KEY_INPUT_LWIN:
		return Library::KeyCode::LWin;
	case KEY_INPUT_RWIN:
		return Library::KeyCode::RWin;
	case KEY_INPUT_NUMLOCK:
		return Library::KeyCode::Numlock;
	case KEY_INPUT_NUMPAD0:
		return Library::KeyCode::Numpad0;
	case KEY_INPUT_NUMPAD1:
		return Library::KeyCode::Numpad1;
	case KEY_INPUT_NUMPAD2:
		return Library::KeyCode::Numpad2;
	case KEY_INPUT_NUMPAD3:
		return Library::KeyCode::Numpad3;
	case KEY_INPUT_NUMPAD4:
		return Library::KeyCode::Numpad4;
	case KEY_INPUT_NUMPAD5:
		return Library::KeyCode::Numpad5;
	case KEY_INPUT_NUMPAD6:
		return Library::KeyCode::Numpad6;
	case KEY_INPUT_NUMPAD7:
		return Library::KeyCode::Numpad7;
	case KEY_INPUT_NUMPAD8:
		return Library::KeyCode::Numpad8;
	case KEY_INPUT_NUMPAD9:
		return Library::KeyCode::Numpad9;
	case KEY_INPUT_MULTIPLY:
		return Library::KeyCode::Multiply;
	case KEY_INPUT_ADD:
		return Library::KeyCode::Add;
	case KEY_INPUT_SUBTRACT:
		return Library::KeyCode::Subtract;
	case KEY_INPUT_DECIMAL:
		return Library::KeyCode::Decimal;
	case KEY_INPUT_DIVIDE:
		return Library::KeyCode::Divide;
	case KEY_INPUT_NUMPADENTER:
		return Library::KeyCode::NumpadEnter;
	case KEY_INPUT_F1:
		return Library::KeyCode::F1;
	case KEY_INPUT_F2:
		return Library::KeyCode::F2;
	case KEY_INPUT_F3:
		return Library::KeyCode::F3;
	case KEY_INPUT_F4:
		return Library::KeyCode::F4;
	case KEY_INPUT_F5:
		return Library::KeyCode::F5;
	case KEY_INPUT_F6:
		return Library::KeyCode::F6;
	case KEY_INPUT_F7:
		return Library::KeyCode::F7;
	case KEY_INPUT_F8:
		return Library::KeyCode::F8;
	case KEY_INPUT_F9:
		return Library::KeyCode::F9;
	case KEY_INPUT_F10:
		return Library::KeyCode::F10;
	case KEY_INPUT_F11:
		return Library::KeyCode::F11;
	case KEY_INPUT_F12:
		return Library::KeyCode::F12;
	case KEY_INPUT_A:
		return Library::KeyCode::A;
	case KEY_INPUT_B:
		return Library::KeyCode::B;
	case KEY_INPUT_C:
		return Library::KeyCode::C;
	case KEY_INPUT_D:
		return Library::KeyCode::D;
	case KEY_INPUT_E:
		return Library::KeyCode::E;
	case KEY_INPUT_F:
		return Library::KeyCode::F;
	case KEY_INPUT_G:
		return Library::KeyCode::G;
	case KEY_INPUT_H:
		return Library::KeyCode::H;
	case KEY_INPUT_I:
		return Library::KeyCode::I;
	case KEY_INPUT_J:
		return Library::KeyCode::J;
	case KEY_INPUT_K:
		return Library::KeyCode::K;
	case KEY_INPUT_L:
		return Library::KeyCode::L;
	case KEY_INPUT_M:
		return Library::KeyCode::M;
	case KEY_INPUT_N:
		return Library::KeyCode::N;
	case KEY_INPUT_O:
		return Library::KeyCode::O;
	case KEY_INPUT_P:
		return Library::KeyCode::P;
	case KEY_INPUT_Q:
		return Library::KeyCode::Q;
	case KEY_INPUT_R:
		return Library::KeyCode::R;
	case KEY_INPUT_S:
		return Library::KeyCode::S;
	case KEY_INPUT_T:
		return Library::KeyCode::T;
	case KEY_INPUT_U:
		return Library::KeyCode::U;
	case KEY_INPUT_V:
		return Library::KeyCode::V;
	case KEY_INPUT_W:
		return Library::KeyCode::W;
	case KEY_INPUT_X:
		return Library::KeyCode::X;
	case KEY_INPUT_Y:
		return Library::KeyCode::Y;
	case KEY_INPUT_Z:
		return Library::KeyCode::Z;
	case KEY_INPUT_0:
		return Library::KeyCode::Alpha0;
	case KEY_INPUT_1:
		return Library::KeyCode::Alpha1;
	case KEY_INPUT_2:
		return Library::KeyCode::Alpha2;
	case KEY_INPUT_3:
		return Library::KeyCode::Alpha3;
	case KEY_INPUT_4:
		return Library::KeyCode::Alpha4;
	case KEY_INPUT_5:
		return Library::KeyCode::Alpha5;
	case KEY_INPUT_6:
		return Library::KeyCode::Alpha6;
	case KEY_INPUT_7:
		return Library::KeyCode::Alpha7;
	case KEY_INPUT_8:
		return Library::KeyCode::Alpha8;
	case KEY_INPUT_9:
		return Library::KeyCode::Alpha9;
	default:
		return Library::KeyCode::None;
	}
}

inline int ToDxLibMouseInput(Library::MouseButton input) {
	switch (input) {
	case Library::MouseButton::Left:
		return MOUSE_INPUT_LEFT;
	case Library::MouseButton::Right:
		return MOUSE_INPUT_RIGHT;
	case Library::MouseButton::Middle:
		return MOUSE_INPUT_MIDDLE;
	case Library::MouseButton::Button4:
		return MOUSE_INPUT_4;
	case Library::MouseButton::Button5:
		return MOUSE_INPUT_5;
	case Library::MouseButton::Button6:
		return MOUSE_INPUT_6;
	case Library::MouseButton::Button7:
		return MOUSE_INPUT_7;
	case Library::MouseButton::Button8:
		return MOUSE_INPUT_8;
	default:
		return 0;
	}
}

inline Library::MouseButton ToLibraryMouseInput(int input) {
	switch (input) {
	case  MOUSE_INPUT_LEFT:
		return Library::MouseButton::Left;
	case MOUSE_INPUT_RIGHT:
		return Library::MouseButton::Right;
	case MOUSE_INPUT_MIDDLE:
		return Library::MouseButton::Middle;
	case MOUSE_INPUT_4:
		return Library::MouseButton::Button4;
	case MOUSE_INPUT_5:
		return Library::MouseButton::Button5;
	case MOUSE_INPUT_6:
		return Library::MouseButton::Button6;
	case MOUSE_INPUT_7:
		return Library::MouseButton::Button7;
	case MOUSE_INPUT_8:
		return Library::MouseButton::Button8;
	default:
		return Library::MouseButton::None;
	}
}

inline int ToDxLibPadInput(Library::PadButton input) {
	switch (input) {
	case Library::PadButton::Down:
		return PAD_INPUT_DOWN;
	case Library::PadButton::Left:
		return PAD_INPUT_LEFT;
	case Library::PadButton::Right:
		return PAD_INPUT_RIGHT;
	case Library::PadButton::Up:
		return PAD_INPUT_UP;
	case Library::PadButton::Button1:
		return PAD_INPUT_1;
	case Library::PadButton::Button2:
		return PAD_INPUT_2;
	case Library::PadButton::Button3:
		return PAD_INPUT_3;
	case Library::PadButton::Button4:
		return PAD_INPUT_4;
	case Library::PadButton::Button5:
		return PAD_INPUT_5;
	case Library::PadButton::Button6:
		return PAD_INPUT_6;
	case Library::PadButton::Button7:
		return PAD_INPUT_7;
	case Library::PadButton::Button8:
		return PAD_INPUT_8;
	case Library::PadButton::Button9:
		return PAD_INPUT_9;
	case Library::PadButton::Button10:
		return PAD_INPUT_10;
	case Library::PadButton::Button11:
		return PAD_INPUT_11;
	case Library::PadButton::Button12:
		return PAD_INPUT_12;
	case Library::PadButton::Button13:
		return PAD_INPUT_13;
	case Library::PadButton::Button14:
		return PAD_INPUT_14;
	case Library::PadButton::Button15:
		return PAD_INPUT_15;
	case Library::PadButton::Button16:
		return PAD_INPUT_16;
	case Library::PadButton::Button17:
		return PAD_INPUT_17;
	case Library::PadButton::Button18:
		return PAD_INPUT_18;
	case Library::PadButton::Button19:
		return PAD_INPUT_19;
	case Library::PadButton::Button20:
		return PAD_INPUT_20;
	case Library::PadButton::Button21:
		return PAD_INPUT_21;
	case Library::PadButton::Button22:
		return PAD_INPUT_22;
	case Library::PadButton::Button23:
		return PAD_INPUT_23;
	case Library::PadButton::Button24:
		return PAD_INPUT_24;
	case Library::PadButton::Button25:
		return PAD_INPUT_25;
	case Library::PadButton::Button26:
		return PAD_INPUT_26;
	case Library::PadButton::Button27:
		return PAD_INPUT_27;
	case Library::PadButton::Button28:
		return PAD_INPUT_28;
	default:
		return 0;
	}
}