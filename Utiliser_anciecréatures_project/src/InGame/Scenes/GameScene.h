#pragma once

#include "SceneManager/SceneBase.h"
#include "../GameObject/GameDemoObject.h"	

class GameScene final : public SceneBase {
public:
	GameScene() : m_gameDemo(nullptr) {}
	~GameScene() override = default;

	virtual void Enter() override;
	virtual void Exit() override;

private:
	GameDemoObject* m_gameDemo;
};