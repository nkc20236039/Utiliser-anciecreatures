#pragma once
#pragma execution_character_set("utf-8")

#include <string>
#include <source_location>
#include <windows.h>

#if _DEBUG
#define OUTPUT_LOG OutputLog
#else
#define OUTPUT_LOG FakeOutputLog
#endif

class OutputLog {
public:
	static void Comment(std::string message, const std::source_location& location = std::source_location::current());
	static void Warning(std::string message, const std::source_location& location = std::source_location::current());
	static void Error(std::string message, const std::source_location& location = std::source_location::current());
	static void DrawDisplayLog(unsigned int color, const TCHAR* formatString, ...);
	static void ClearDisplayLog();

private:
	static std::string GetDate();
	static std::string GetCallerInfo(const std::source_location& location);
	static std::wstring Utf8ToWide(const std::string& str);
	static void Output(char messageIcon, std::string message, const std::source_location& location);

	constexpr static int LINE_SPACING = 20;
	static int d_logDisplayPosY;
};

class FakeOutputLog {
public:
	static void Comment(...) {}
	static void Warning(...) {}
	static void Error(...) {}
	static void DrawDisplayLog(...) {}
	static void ClearDisplayLog() {}
};
