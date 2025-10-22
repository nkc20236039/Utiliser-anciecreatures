#include "OutputLog.h"

#include <windows.h>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <codecvt>
#include <locale>

using namespace std::chrono;

void OutputLog::Comment(std::string message, const std::source_location& location) {
	// 通常メッセージを送信
	Output('-', message, location);
}

void OutputLog::Warning(std::string message, const std::source_location& location) {
	// 警告メッセージを送信
	Output('!', message, location);
}

void OutputLog::Error(std::string message, const std::source_location& location) {
	// エラーメッセージを送信
	Output('x', message, location);
}

std::string OutputLog::GetDate() {
	auto now = system_clock::now();

	// 時間を文字列で取得できるように変換
	std::time_t time = system_clock::to_time_t(now);
	std::tm localTime{};
	localtime_s(&localTime, &time);

	// フォーマットしてstringにする
	std::ostringstream oss;
	oss << std::put_time(&localTime, "%Y/%m/%d %H:%M:%S");
	return oss.str();
}

std::string OutputLog::GetCallerInfo(const std::source_location& location) {
	std::string info = std::string(location.file_name()) +
		":" + std::to_string(location.line()) +
		" " + std::string(location.function_name());
	return info;
}

std::wstring OutputLog::Utf8ToWide(const std::string& str) {
	if (str.empty()) { return std::wstring(); }

	int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, nullptr, 0);
	std::wstring wstr(size_needed - 1, 0);
	MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, wstr.data(), size_needed);

	return wstr;
}

void OutputLog::Output(char messageIcon, std::string message, const std::source_location& location) {
	// 文字の作成
	std::string log = std::format("<{}>[{}] {}\n{} (at {}:{})\n",
		messageIcon,
		GetDate(),
		message,
		std::string(location.function_name()),
		std::string(location.file_name()),
		std::to_string(location.line()));

	// wstringに変換
	std::wstring wideLog = Utf8ToWide(log);
	OutputDebugStringW(wideLog.c_str());
}