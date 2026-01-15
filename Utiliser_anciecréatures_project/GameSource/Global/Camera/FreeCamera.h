#pragma once

#include "Camera.h"

class FreeCamera final : public Camera {
	void Start() override;
	void Update(const Time& time) override;
};