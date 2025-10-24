#pragma once

#include <unordered_map>
#include <typeindex>
#include <any>

static class MasterData {
public:
	template<typename T>
	static void Set(const T& data) {
		m_masterDataMap[typeid(T)] = data;
	}

	template<typename T>
	static const T* Get() {
		if (!m_masterDataMap.contains(typeid(T))) {
			return nullptr;
		}

		return std::any_cast<T>(&m_masterDataMap[typeid(T)]);
	}

private:
	MasterData() = delete;
	~MasterData() = delete;

	static inline std::unordered_map<std::type_index, std::any> m_masterDataMap;
};