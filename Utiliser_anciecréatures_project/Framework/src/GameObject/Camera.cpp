#include "Camera.h"

void Camera::UpdateGameObjectState() {
	Library::SetCameraPositionAndAngle(
		m_transform->Position,
		m_transform->Rotation);
}

void Camera::SetCameraSettings(float nearClip, float farClip, float fov) {
	m_near = nearClip;
	m_far = farClip;
	m_fov = fov;

	// カメラに設定を反映
	Library::SetCameraNearFar(m_near, m_far);
	Library::SetupCameraPerspective(m_fov);
}
