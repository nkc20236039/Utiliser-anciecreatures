#pragma once

#include "DxLib.h"
#include "GameObject/GameObject.h"
#include "../Scenes.h"

class TitleDemoObject final : public GameObject {
	void Start() override {}

	void Update(const Time& time) override {
		// 適当に球を作成(デモ用だから数値は直接入力)
		DrawSphere3D(VGet(320.0f, 200.0f, 0.0f), 80.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);

		// キー入力の案内
		DrawString(230, 400, "Spaceキーでシーン移動", GetColor(0, 0, 0));

		if (CheckHitKey(KEY_INPUT_SPACE)) {
			SceneManager::Get().ChangeScene<GameScene>();
		}
	}
};
