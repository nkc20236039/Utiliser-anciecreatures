#pragma once

#include "src/Frame/FrameManager.h"

namespace UFramework {
class FrameworkRoot {
public:
	FrameworkRoot() = default;
	~FrameworkRoot() = default;

	bool Run();

private:
	FrameManager m_frameManager;

	bool Initialize();

	bool MainLoop();

	bool Finalize();
};
}