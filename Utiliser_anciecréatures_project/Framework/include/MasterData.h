#pragma once

#include <unordered_map>
#include <string>
#include <filesystem>

#include "nlohmann/json.hpp"
#include "Singleton.h"

class MasterData : public Singleton<MasterData> {
	friend class Singleton<MasterData>;
public:
	/// <summary>
	/// 対象のマスターデータを読み込む
	/// </summary>
	/// <param name="path">読み込むマスターデータのパス(ディレクトリを指定した場合、それ以下の全てのJSONファイルが読み込まれます。)</param>
	bool Initialize(std::string path);

	/// <summary>
	/// マスターデータを取得する
	/// </summary>
	/// <param name="MasterPath">マスターデータのファイルパス(ロードされていないファイルの場合、読み込みが発生します)</param>
	/// <returns>構造化されたデータを返す</returns>
	nlohmann::json Load(std::string masterPath);

	bool SetDefaultPath(std::string path);

private:
	MasterData() = default;
	~MasterData() = default;

	std::string m_defaultPath;
	std::unordered_map<std::string, nlohmann::json> m_masterDataMap;

	bool LoadMasterFile(std::string filePath);
};