#pragma once

#include <DxLib.h>

inline int ToDxLibBool(bool flag) {
	return flag ? TRUE : FALSE;
}

inline bool IsSuccessful(int result) {
	return result == 0;
}
