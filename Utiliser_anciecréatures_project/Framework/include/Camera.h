#pragma once

#include "GameObject.h"

class Camera : public GameObject {
public:
	Camera() : GameObject() {}
	Camera(std::shared_ptr<Transform> transform, float near, float far, float fov = 60.0f, bool isActive = true)
		: GameObject(transform, "", isActive),
		m_near(near),
		m_far(far),
		m_fov(fov) {}

	void UpdateGameObjectState() override;
protected:
	void SetCameraSettings(float nearClip, float farClip, float fov);

private:
	float m_near = 100.0f;
	float m_far = 15000.0f;
	float m_fov = 60.0f;
};