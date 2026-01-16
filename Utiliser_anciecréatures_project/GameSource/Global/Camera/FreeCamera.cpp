#include "FreeCamera.h"

#include "InputSystem.h"

void FreeCamera::Start() {}

void FreeCamera::Update(const Time& time) {
	auto& input = InputSystem::Get();
	const float moveSpeed = 500.0f;      // 移動速度
	const float rotateSpeed = 0.01f;      // 回転速度

	// マウス入力による回転
	Library::float2 mouseDelta = input.GetMouseDelta();
	m_transform->Rotation.y += mouseDelta.x * rotateSpeed;
	m_transform->Rotation.x += mouseDelta.y * rotateSpeed;
	m_transform->Rotation.z = 0.0f;

	// キーボード入力による移動
	Library::float3 moveDirection = Library::float3::Zero();

	moveDirection.z = input.GetAxis(Library::KeyCode::W, Library::KeyCode::S);
	moveDirection.x = input.GetAxis(Library::KeyCode::D, Library::KeyCode::A);
	moveDirection.y = input.GetAxis(Library::KeyCode::E, Library::KeyCode::Q);
	moveDirection = moveDirection.Normalized();  // メモ：こうこうのはNormalized(moveDirection)という書き方のほうがいいのか

	// 移動方向を正規化して速度を掛ける
	if (moveDirection.Length() > 0.0f) {
		// カメラの向きに基づいて移動方向を変換
		Library::float3 forward = m_transform->Forward();
		Library::float3 right = m_transform->Right();
		Library::float3 up = m_transform->Up();

		Library::float3 adjustedMoveDirection =
			m_transform->Forward() * moveDirection.z +
			m_transform->Right() * moveDirection.x +
			m_transform->Up() * moveDirection.y;
		m_transform->Position += adjustedMoveDirection.Normalized() * moveSpeed * time.GetDeltaTime();
	}
}