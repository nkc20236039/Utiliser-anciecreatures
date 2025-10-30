#pragma once
#include "DxLib.h"

class GameObject {
public:
	virtual ~GameObject() = default;

	virtual void Update() = 0;

private:
	VECTOR m_position;
	VECTOR m_scale;
	VECTOR m_rotation;
};