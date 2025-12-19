#pragma once

#include <array>

#include "src/MasterData/MasterLoader.h"

#include "TestMasterLoader.h"

class MasterLoaders {
public:
	MasterLoaders() = default;
	~MasterLoaders() = default;
	std::array<std::unique_ptr<MasterLoader>, 1> MasterDatas = {
		std::make_unique<TestMasterLoader>("Assets/MasterData/TestMaster.json"),
	};
};
