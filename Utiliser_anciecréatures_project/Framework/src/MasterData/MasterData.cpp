#include "MasterData.h"

#include <filesystem>
#include <format>
#include <fstream>

#include "OutputLog.h"

namespace fileSystem = std::filesystem;

bool MasterData::Initialize(std::string path) {
	// ファイルの場合
	if (fileSystem::is_regular_file(path)) {
		// そのまま読み込み
		return LoadMasterFile(path);
	}
	else if (fileSystem::is_directory(path)) {
		bool isSuccess = true;
		// ディレクトリの場合、再帰的に探索して全てのJSONファイルを読み込み
		for (const auto& entry : fileSystem::recursive_directory_iterator(path)) {
			bool tempSuccess = true;
			// JSONファイルの場合のみ読み込み
			if (entry.is_regular_file() && entry.path().extension() == ".json") {
				tempSuccess = LoadMasterFile(entry.path().string());
			}

			// 読み込みに失敗した場合は失敗フラグにする
			if (tempSuccess == false) {
				isSuccess = false;
			}
		}

		return isSuccess;
	}

	// 読み込みに失敗
	return false;
}

nlohmann::json MasterData::Load(std::string filePath) {
	// 保存されているパスか調べる
	fileSystem::path fullPath = fileSystem::path(filePath);
	if (!m_masterDataMap.contains(fullPath.string())) {
		// 読み込まれていない場合は新たに読み込み
		LoadMasterFile(filePath);
	}

	// 読み込んだうえで見つからなければ空のJsonを返す
	if (!m_masterDataMap.contains(fullPath.string())) {
		return nlohmann::json();
	}

	// 登録できている場合データを返す
	return m_masterDataMap[fullPath.string()];
}

bool MasterData::LoadMasterFile(std::string filePath) {
	// ファイルを読み込む
	fileSystem::path fullPath = fileSystem::path(filePath);
	std::ifstream masterFile(fullPath);
	auto test = fullPath.string();
	// 既に読み込まれている場合は即時終了
	if (m_masterDataMap.contains(fullPath.string())) { return true; }

	// ファイルが開けなかった場合は例外を投げる
	if (!masterFile.is_open()) {
		OutputLog::Error(std::format("{}: ファイルを開けませんでした。", fullPath.string()));
		return false;
	}
	// 不正なJSON形式の場合は例外を投げる
	if (!nlohmann::json::accept(masterFile)) {
		OutputLog::Error(std::format("{}: 不正なJSONの形式です。", fullPath.string()));
		return false;
	}

	// フォーマットチェックで進んだpositionを元に戻す
	masterFile.seekg(0, std::ios::beg);

	// Jsonデータの読み込み
	nlohmann::json jsonData = nlohmann::json::parse(masterFile);

	// マスターデータを保存
	m_masterDataMap[fullPath.string()] = jsonData;

	return true;
}