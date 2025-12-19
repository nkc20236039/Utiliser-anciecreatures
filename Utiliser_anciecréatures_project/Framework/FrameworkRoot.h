#pragma once

namespace UFramework {

class FrameworkRoot {
public:
	FrameworkRoot() = default;
	~FrameworkRoot() = default;

	bool Run();

private:
	bool Initialize();

	bool MainLoop();

	bool Finalize();
};
}