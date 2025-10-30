#pragma once

#include <string>

#include "MasterData/MasterLoader.h"
#include "MasterData/Struct/TestMaster.h"

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