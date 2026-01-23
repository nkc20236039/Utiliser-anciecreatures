#include "FreeCamera.h"

#include "InputSystem.h"
#include "Library/Wrapper.h"
#include "ApplicationManager.h"

void FreeCamera::Start() {
	ApplicationManager::GetInstance().SetCursorState(true, true);
}

void FreeCamera::Update(const Time& time) {
	auto& input = InputSystem::GetInstance();
	// TODO: JSONに定義を移動する
	const float moveSpeed = 500.0f;		// 移動速度
	const float rotateSpeed = 1.0f;	// 回転速度

	// マウス入力による回転
	float2 mouseDelta = input.GetMouseDelta();
	float yaw = mouseDelta.x * rotateSpeed * time.GetDeltaTime();
	float pitch = mouseDelta.y * rotateSpeed * time.GetDeltaTime();

	// 回転を適用
	Quaternion rotation = m_transform->Rotation;
	// マウスのX軸入力を適用
	rotation = Quaternion::FromAxisAngle(float3::Up(), yaw) * rotation;
	// マウスのY軸入力を適用
	rotation = rotation * Quaternion::FromAxisAngle(float3::Right(), pitch);

	m_transform->Rotation = rotation;

	// キーボード入力による移動
	float3 moveDirection = float3::Zero();

	// 前後移動
	moveDirection.z = input.GetAxis(Library::KeyCode::W, Library::KeyCode::S);
	// 左右移動
	moveDirection.x = input.GetAxis(Library::KeyCode::D, Library::KeyCode::A);
	// 上下移動
	moveDirection.y = input.GetAxis(Library::KeyCode::E, Library::KeyCode::Q);
	moveDirection = moveDirection.Normalized();

	// 移動方向を正規化して速度を掛ける
	if (moveDirection.Length() > 0.0f) {
		// カメラの向きに基づいて移動方向を変換
		float3 adjustedMoveDirection =
			m_transform->Forward() * moveDirection.z +
			m_transform->Right() * moveDirection.x +
			m_transform->Up() * moveDirection.y;
		m_transform->Position += adjustedMoveDirection.Normalized() * moveSpeed * time.GetDeltaTime();
	}
}