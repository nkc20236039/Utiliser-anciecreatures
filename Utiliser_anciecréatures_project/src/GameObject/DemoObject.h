#pragma once

#include "DxLib.h"
#include "GameObject.h"

class DemoObject final : public GameObject {
	void Start() override {}

	void Tick() override {
		DrawSphere3D(VGet(320.0f, 100.0f, 0.0f), 80.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
		DrawSphere3D(VGet(320.0f, 150.0f, 100.0f), 80.0f, 32, GetColor(0, 255, 0), GetColor(255, 255, 255), TRUE);
	}
};
