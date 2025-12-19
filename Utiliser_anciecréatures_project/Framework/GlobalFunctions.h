#pragma once

#include <DxLib.h>

/// <summary>
/// DxLibの真偽値へ明示的に変換する
/// </summary>
int DxLibBool(bool flag) {
	return flag ? TRUE : FALSE;
}
