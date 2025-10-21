#pragma once

class IScene {
public:
	virtual ~IScene() = default;
	virtual void Enter() = 0;
	virtual void Update() = 0;
	virtual void Exit() = 0;
};