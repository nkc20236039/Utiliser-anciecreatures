#pragma once

#include "SceneBase.h"

class TitleScene final : public SceneBase {
public:
	TitleScene() {}
	~TitleScene() override = default;

	virtual void Enter() override;
	virtual void Exit() override;

private:
};