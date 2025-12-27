#pragma once

#include "SceneBase.h"

class GameScene final : public SceneBase {
public:
	GameScene() = default;
	~GameScene() override = default;

	virtual void Enter() override;
	virtual void Exit() override;
};