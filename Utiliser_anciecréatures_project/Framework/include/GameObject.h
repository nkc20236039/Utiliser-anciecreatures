#pragma once

#include <memory>

#include "Mathex.h"
#include "Library/Wrapper.h"
#include "GameFrame.h"

class Transform {
public:
	Transform()
		: Position(float3::One()),
		Scale(float3::Zero()),
		Rotation(Quaternion::Identity()) {}
	Transform(float3 position, float3 scale, Quaternion rotation)
		: Position(position),
		Scale(scale),
		Rotation(rotation) {}

	float3 Position;
	float3 Scale;
	Quaternion Rotation;

	float3 Forward() const {
		return Rotation.Rotate(float3(0, 0, 1));
	}

	float3 Up() const {
		return Rotation.Rotate(float3(0, 1, 0));
	}

	float3 Right() const {
		return Rotation.Rotate(float3(1, 0, 0));
	}
};

class GameObject {
public:
	/// <summary>
	/// ゲームオブジェクトを完全な初期状態で生成する
	/// </summary>
	GameObject()
		: m_transform(std::make_shared<Transform>()) {}

	/// <summary>
	/// 位置情報を指定してゲームオブジェクトを生成する
	/// </summary>
	GameObject(float3 position, std::string modelPath, bool isActive = true)
		: m_transform(std::make_shared<Transform>(position, float3::One(), Quaternion::Identity())),	// scaleとrotationはデフォルト値
		m_modelHandle(Library::LoadModel(modelPath)) {}

	/// <summary>
	/// Transformを指定してゲームオブジェクトを生成する
	/// </summary>
	GameObject(std::shared_ptr<Transform> transform, std::string modelPath, bool isActive = true)
		: m_transform(transform),
		m_modelHandle(Library::LoadModel(modelPath)) {}

	/// <summary>
	/// モデルパスのみを指定してゲームオブジェクトを生成する
	/// </summary>
	GameObject(std::string modelPath, bool isActive = true)
		: m_transform(std::make_shared<Transform>()),
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

	int GetModelHandle() const { return m_modelHandle; }

	/// <summary>
	/// ゲームオブジェクトの状態を更新する
	/// </summary>
	virtual void UpdateGameObjectState();

protected:
	bool						m_isActive = true;
	bool						m_showModel = true;
	std::shared_ptr<Transform>	m_transform;

	void SetZBuffer(bool useZBuffer) { m_zBuffer = useZBuffer; }

private:
	int		m_modelHandle = -1;
	bool	m_zBuffer = true;
};