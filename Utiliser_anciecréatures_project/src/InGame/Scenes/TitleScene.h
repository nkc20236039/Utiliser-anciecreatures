#pragma once

#include "SceneManager/IScene.h"
#include "SceneManager/SceneStateMachine.h"

class TitleScene final : public IScene {
public:
	TitleScene(SceneStateMachine* sceneManager) : m_sceneManager(sceneManager) {}
	~TitleScene() override = default;

	virtual void Enter() override;
	virtual void Update() override;
	virtual void Exit() override;

private:
	SceneStateMachine* m_sceneManager;
};