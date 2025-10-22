#pragma once
#pragma execution_character_set("utf-8")

#include <string>
#include <source_location>

static class OutputLog {
public:
	static void Comment(std::string message, const std::source_location& location = std::source_location::current());
	static void Warning(std::string message, const std::source_location& location = std::source_location::current());
	static void Error(std::string message, const std::source_location& location = std::source_location::current());

private:
	static std::string GetDate();
	static std::string GetCallerInfo(const std::source_location& location);
	static std::wstring Utf8ToWide(const std::string& str);
	static void Output(char messageIcon, std::string message, const std::source_location& location);
};