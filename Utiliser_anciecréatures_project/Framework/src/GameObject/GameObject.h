#pragma once

#include "include/Library/Wrapper.h"

#include "GameFrame.h"

class GameObject {
public:
	GameObject()
		: m_isActive(true),
		m_position({ 0.0f, 0.0f, 0.0f }),
		m_scale({ 1.0f, 1.0f, 1.0f }),
		m_rotation({ 0.0f, 0.0f, 0.0f }) {}
	virtual ~GameObject() = default;

	// 初期化処理
	virtual void Start() = 0;
	// 毎フレームの更新処理
	virtual void Update(const Time& time) = 0;

	// アクティブ状態の取得
	bool IsActive() const { return m_isActive; }

protected:
	bool   m_isActive;
	Library::float3 m_position;
	Library::float3 m_scale;
	Library::float3 m_rotation;
};