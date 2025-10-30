#pragma once

#include "SceneManager/SceneBase.h"

class GameScene final : public SceneBase {
public:
	GameScene() = default;
	~GameScene() override = default;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;
};