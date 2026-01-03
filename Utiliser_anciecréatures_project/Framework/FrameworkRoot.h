#pragma once

#include "src/Frame/FrameManager.h"
#include "src/InputManager/InputManager.h"

namespace UFramework {
class FrameworkRoot {
public:
	FrameworkRoot() = default;
	~FrameworkRoot() = default;

	bool Run();

private:
	InputManager m_inputManager;
	FrameManager m_frameManager;

	bool Initialize();
	bool MainLoop();
	bool Finalize();
};
}