#include "Logger.h"
std::ofstream Logger::fileStream;
std::string Logger::getLevelPrefix(LOGGING_LEVEL level)
{
	switch (level) {
	case LOGGING_LEVEL::LOG_INFORMATION:
		return "[Info]";
	case LOGGING_LEVEL::LOG_WARNING:
		return "[Warn]";
	case LOGGING_LEVEL::LOG_ERROR:
		return "[Error]";
	case LOGGING_LEVEL::LOG_DEBUG:
		return "[Debug]";
		
	}
	return "";
}
void Logger::log(std::string message, LOGGING_LEVEL level) {
#ifndef _DEBUG
	if (level == Logger::LOGGING_LEVEL::LOG_DEBUG) {
		return;
	}
#endif
	if (!fileStream.is_open()) {
		auto t = std::time(nullptr);
		auto tm = *std::localtime(&t);

		std::ostringstream oss;
		//oss << "log.txt";
		oss << "logs\\" << std::put_time(&tm, "%Y-%m-%d %H.%M.%S") << " log.txt";
		auto str = oss.str();
		if (!std::filesystem::is_directory("logs") || !std::filesystem::exists("logs")) {
			std::filesystem::create_directory("logs");
		}
		fileStream.open(str, std::ios::app);
		log("Opened Stream");
	}
	fileStream << Logger::getLevelPrefix(level) << "\t" << Logger::getTimeString() << ":\t" << message << "\n";
	fileStream.flush();
}

void Logger::endFile()
{
	if (fileStream.is_open()) {
		log("Closed Stream");
		fileStream.close();
	}
}
std::string Logger::getTimeString()
{
	auto t = std::time(nullptr);
	auto tm = *std::localtime(&t);

	std::ostringstream oss;
	oss << std::put_time(&tm, "%H:%M:%S");
	return oss.str();
}

