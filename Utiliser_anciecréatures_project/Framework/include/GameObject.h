#pragma once

#include <memory>

#include "Library/Wrapper.h"
#include "GameFrame.h"

class Transform {
public:
	Transform()
		: m_position(Library::float3::One()),
		m_scale(Library::float3::Zero()),
		m_rotation(Library::float3::One()) {}
	Transform(Library::float3 position, Library::float3 scale, Library::float3 rotation)
		: m_position(position),
		m_scale(scale),
		m_rotation(rotation) {}

	Library::float3 m_position;
	Library::float3 m_scale;
	Library::float3 m_rotation;
};

class GameObject {
public:
	/// <summary>
	/// ゲームオブジェクトを完全な初期状態で生成する
	/// </summary>
	GameObject()
		: m_isActive(true),
		m_transform(std::make_shared<Transform>()),
		m_modelHandle(-1) {}

	/// <summary>
	/// 位置情報を指定してゲームオブジェクトを生成する
	/// </summary>
	GameObject(Library::float3 position, std::string modelPath, bool isActive = true)
		: m_isActive(isActive),
		m_transform(std::make_shared<Transform>(position, Library::float3::One(), Library::float3::Zero())),	// scaleとrotationはデフォルト値
		m_modelHandle(Library::LoadModel(modelPath)) {}

	/// <summary>
	/// Transformを指定してゲームオブジェクトを生成する
	/// </summary>
	GameObject(std::shared_ptr<Transform> transform, std::string modelPath, bool isActive = true)
		: m_isActive(isActive),
		m_transform(transform),
		m_modelHandle(Library::LoadModel(modelPath)) {}

	/// <summary>
	/// モデルパスのみを指定してゲームオブジェクトを生成する
	/// </summary>
	GameObject(std::string modelPath, bool isActive = true)
		: m_isActive(isActive),
		m_transform(std::make_shared<Transform>()),
		m_modelHandle(Library::LoadModel(modelPath)) {}

	virtual ~GameObject() {
		Library::DeleteModel(m_modelHandle);
	}

	// 初期化処理
	virtual void Start() = 0;
	// 毎フレームの更新処理
	virtual void Update(const Time& time) = 0;

	/// <summary>
	/// アクティブ状態の取得
	/// </summary>
	bool IsActive() const { return m_isActive; }

	/// <summary>
	/// アクティブ状態の設定
	/// </summary>
	void SetActive(bool isActive) { m_isActive = isActive; }

	/// <summary>
	/// Transformの取得
	/// </summary>
	Transform* GetTransform() { return m_transform.get(); }

	int GetModelHandle() const noexcept { return m_modelHandle; }

protected:
	bool						m_isActive;
	std::shared_ptr<Transform>	m_transform;


private:
	int m_modelHandle;
};