#pragma once

#include <DxLib.h>

int ToDxLibBool(bool flag) {
	return flag ? TRUE : FALSE;
}

bool IsSuccessful(int result) {
	return result == 0;
}
