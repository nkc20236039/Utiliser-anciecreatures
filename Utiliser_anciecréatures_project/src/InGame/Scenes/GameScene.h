#pragma once

#include "SceneManager/IScene.h"

class GameScene final : public IScene {
public:
	GameScene() = default;
	~GameScene() override = default;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;
};