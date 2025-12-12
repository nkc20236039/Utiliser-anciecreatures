#pragma once

#include "SceneManager/SceneBase.h"
#include "../GameObject/TitleDemoObject.h"	

class TitleScene final : public SceneBase {
public:
	TitleScene() : m_titleDemo(nullptr) {}
	~TitleScene() override = default;

	virtual void Enter() override;
	virtual void Exit() override;

private:
	TitleDemoObject* m_titleDemo;
};