#include "FreeCamera.h"

#include "InputSystem.h"

void FreeCamera::Start() {}

void FreeCamera::Update(const Time& time) {
	auto& input = InputSystem::Get();
	const float moveSpeed = 500.0f;      // 移動速度
	const float rotateSpeed = 0.01f;      // 回転速度

	// キーボード入力による移動
	Library::float3 moveDirection = Library::float3::Zero();

	moveDirection.z = input.GetAxis(Library::KeyCode::W, Library::KeyCode::S);
	moveDirection.x = input.GetAxis(Library::KeyCode::D, Library::KeyCode::A);
	moveDirection.y = input.GetAxis(Library::KeyCode::E, Library::KeyCode::Q);

	// 移動方向を正規化して速度を掛ける
	if (moveDirection.Length() > 0.0f) {
		moveDirection = moveDirection.Normalized() * moveSpeed * time.GetDeltaTime();
		m_transform->Position += moveDirection;
	}

	// マウス入力による回転
	Library::float2 mouseDelta = input.GetMouseDelta();
	m_transform->Rotation.y += mouseDelta.x * rotateSpeed;
	m_transform->Rotation.x += mouseDelta.y * rotateSpeed;
	m_transform->Rotation.z = 0.0f;
}