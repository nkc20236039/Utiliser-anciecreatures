#pragma once

#include <any>
#include <string>
#include <fstream>
#include <filesystem>
#include <typeindex>

#include "nlohmann/json.hpp"

class MasterLoader {
public:
	MasterLoader(std::string masterPath) : m_masterPath(masterPath) {}
	virtual ~MasterLoader() = default;

	/// <summary>
	/// マスターデータを読み取る
	/// </summary>
	virtual std::any LoadMasterData() = 0;
	/// <summary>
	/// メモリに保存するデータの型を取得する
	/// </summary>
	virtual std::type_index GetDataType() = 0;

protected:
	std::string m_masterPath;

	nlohmann::json GetJsonData() {
		// ファイルを読み込む
		std::filesystem::path basePath = std::filesystem::current_path();
		std::filesystem::path filePath = m_masterPath;
		std::ifstream masterFile(basePath / filePath);

		// ファイルが開けなかった場合は例外を投げる
		if (!masterFile.is_open()) {
			throw "ファイルが開けませんでした";
		}
		// 不正なJson形式の場合は例外を投げる
		if (!nlohmann::json::accept(masterFile)) {
			throw "不正なJson形式です";
		}

		// フォーマットチェックで進んだpositionを元に戻す
		masterFile.seekg(0, std::ios::beg);

		// Jsonデータの読み込み
		nlohmann::json jsonData = nlohmann::json::parse(masterFile);
		return jsonData;
	}

	template<typename TData>
	TData GetJsonDataAs(const nlohmann::json& master, std::string key, TData defaultValue = TData()) {
		// キーが見つからない場合デフォルトを返す
		if (!master.contains(key)) { return defaultValue; }
		// データ取得
		auto data = master.at(key);
		// キーがnullの場合デフォルトを返す
		if (data.is_null()) { return defaultValue; }

		// データを型変換して返す
		return data.get<TData>();
	}
};