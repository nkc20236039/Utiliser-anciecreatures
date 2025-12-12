#pragma once

#include <cmath>

#include "DxLib.h"
#include "GameObject/GameObject.h"
//#include "../Scenes.h"

class GameDemoObject final : public GameObject {
	void Start() override {}

	void Update(const Time& time) override {
		// 円形に移動させる
		float x = std::cos(time.GetElapsedTime()) * 100.0f + 320.0f;
		float y = std::sin(time.GetElapsedTime()) * 100.0f + 200.0f;
		// 適当に球を作成
		DrawSphere3D(VGet(x, y, 0.0f), 80.0f, 32, GetColor(0, 0, 255), GetColor(255, 255, 255), TRUE);
	}
};
