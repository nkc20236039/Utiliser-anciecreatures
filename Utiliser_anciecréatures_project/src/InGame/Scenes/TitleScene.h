#pragma once

#include "SceneManager/IScene.h"

class TitleScene final : public IScene {
public:
	TitleScene() = default;
	~TitleScene() override = default;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;
};