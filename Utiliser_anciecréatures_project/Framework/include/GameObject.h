#pragma once

#include <memory>

#include "Library/Wrapper.h"
#include "GameFrame.h"

class Transform {
public:
	Transform()
		: Position(Library::float3::One()),
		Scale(Library::float3::Zero()),
		Rotation(Library::float3::One()) {}
	Transform(Library::float3 position, Library::float3 scale, Library::float3 rotation)
		: Position(position),
		Scale(scale),
		Rotation(rotation) {}

	Library::float3 Position;
	Library::float3 Scale;
	Library::float3 Rotation;

	Library::float3 Forward() const {
		// ラジアンの回転を取得
		Library::float3 radians = GetRadianRotation();

		// 前方向ベクトルを計算して返す
		return Library::float3(
			std::sin(Rotation.y) * std::cos(Rotation.x),
			-std::sin(Rotation.x),
			std::cos(Rotation.y) * std::cos(Rotation.x))
			.Normalized();
	}

	Library::float3 Up() const {
		// ラジアンの回転を取得
		Library::float3 radians = GetRadianRotation();

		// 上方向ベクトルを計算して返す
		return Library::float3(
			-std::cos(Rotation.y) * std::sin(Rotation.z) + std::sin(Rotation.y) * std::sin(Rotation.x) * std::sin(Rotation.z),
			std::cos(Rotation.x) * std::cos(Rotation.z),
			std::sin(Rotation.y) * std::sin(Rotation.z) + std::cos(Rotation.y) * std::sin(Rotation.x) * std::cos(Rotation.z))
			.Normalized();
	}

	Library::float3 Right() const {
		// ラジアンの回転を取得
		Library::float3 radians = GetRadianRotation();
		// 右方向ベクトルを計算して返す
		return Library::float3(
			std::cos(Rotation.y) * std::cos(Rotation.z) + std::sin(Rotation.y) * std::sin(Rotation.x) * std::sin(Rotation.z),
			-std::cos(Rotation.x) * std::sin(Rotation.z),
			-std::sin(Rotation.y) * std::cos(Rotation.z) + std::cos(Rotation.y) * std::sin(Rotation.x) * std::sin(Rotation.z))
			.Normalized();
	}

private:
	Library::float3 GetRadianRotation() const {
		return Library::float3(
			Rotation.x * UMath::Deg2Rad,
			Rotation.y * UMath::Deg2Rad,
			Rotation.z * UMath::Deg2Rad);
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
	GameObject(Library::float3 position, std::string modelPath, bool isActive = true)
		: m_transform(std::make_shared<Transform>(position, Library::float3::One(), Library::float3::Zero())),	// scaleとrotationはデフォルト値
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