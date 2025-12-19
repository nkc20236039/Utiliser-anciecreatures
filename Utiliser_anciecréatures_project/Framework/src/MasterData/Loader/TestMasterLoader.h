#pragma once

#include <string>

#include "src/MasterData/MasterLoader.h"
#include "src/MasterData/Struct/TestMaster.h"

class TestMasterLoader : public MasterLoader {
public:
	TestMasterLoader(std::string masterPath) : MasterLoader(masterPath) {}
	~TestMasterLoader() = default;

	std::any LoadMasterData() override {
		TestMaster data;
		nlohmann::json jsonData = GetJsonData();

		data.Id = GetJsonDataAs<int>(jsonData, "Id");

		return data;
	}

	std::type_index GetDataType() override {
		return typeid(TestMaster);
	}
};