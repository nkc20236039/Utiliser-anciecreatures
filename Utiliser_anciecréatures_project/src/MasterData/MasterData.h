#pragma once

#include <unordered_map>
#include <typeindex>
#include <memory>
#include <any>

#include "MasterData/Loader/MasterPathArray.h"

static class MasterData {
public:
	static void Load() {
		// 現在のマスターデータを削除
		m_masterDataMap.clear();

		// 全てのマスターをメモリに保存
		MasterLoaders loaders;
		for (auto& loader : loaders.MasterDatas) {
			m_masterDataMap[loader->GetDataType()] = loader->LoadMasterData();
		}
	}

	template<typename T>
	static const T* Get() {
		// マスターに指定のデータが存在しない場合 nullを返す
		if (!m_masterDataMap.contains(typeid(T))) {
			return nullptr;
		}

		// 指定されたデータを返す
		return std::any_cast<T>(&m_masterDataMap[typeid(T)]);
	}

private:
	MasterData() = delete;
	~MasterData() = delete;
	static inline std::unordered_map<std::type_index, std::any> m_masterDataMap;
};