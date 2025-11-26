#pragma once
#include "DxLib.h"

class GameObject {
public:
	GameObject()
		: m_isActive(true),
		m_position({ 0.0f, 0.0f, 0.0f }),
		m_scale({ 1.0f, 1.0f, 1.0f }),
		m_rotation({ 0.0f, 0.0f, 0.0f }) {}
	virtual ~GameObject() = default;

	virtual void Start() = 0;
	virtual void Tick() = 0;

	bool IsActive() const { return m_isActive; }

private:
	bool m_isActive;
	VECTOR m_position;
	VECTOR m_scale;
	VECTOR m_rotation;
};