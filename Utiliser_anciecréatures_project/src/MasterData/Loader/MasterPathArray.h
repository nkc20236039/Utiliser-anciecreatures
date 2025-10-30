#pragma once

#include <array>

#include "MasterData/MasterLoader.h"

#include "TestMasterLoader.h"

class MasterLoaders {
public:
	MasterLoaders() = default;
	~MasterLoaders() = default;
	std::array<std::unique_ptr<MasterLoader>, 1> MasterDatas = {
		std::make_unique<TestMasterLoader>("assets/MasterData/TestMaster.json"),
	};
};
