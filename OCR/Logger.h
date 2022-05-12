#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <time.h>
#include <filesystem>
class Logger
{
public:
	static std::ofstream fileStream;
	enum class LOGGING_LEVEL {
		LOG_INFORMATION = 0,
		LOG_WARNING = 1,
		LOG_ERROR = 2,
		LOG_DEBUG = 3
	};
	static std::string getLevelPrefix(LOGGING_LEVEL level);
	static void log(std::string message, LOGGING_LEVEL level = LOGGING_LEVEL::LOG_INFORMATION);
	static void endFile();
	static std::string getTimeString();
};

