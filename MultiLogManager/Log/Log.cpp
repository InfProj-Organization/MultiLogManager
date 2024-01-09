#include "pch.h"

#include <iostream>
#include <fstream>
#include <span>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

#include "Log.hpp"

namespace Log
{
	CLog* pLog = nullptr;

	std::string SETTINGS_FILE_NAME = "Settings.json";

	class CLog::Impl
	{
	public:
		std::string FilePathToLog;
		std::filesystem::path dllPath;
		std::filesystem::path settingsPath;
		static std::string FinalPathToFileLog;

		struct tm* getCurrentTimeInfo()
		{
			__time64_t current_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
			return localtime(&current_time);
		}
	};

	std::string CLog::Impl::FinalPathToFileLog = "";

	CLog::CLog() : pImpl(new Impl)
	{

	}

	CLog::~CLog()
	{
		delete pImpl;
	}

	unsigned CLog::CreateLog()
	{
		std::filesystem::path path_to_log = CLog::Impl::FinalPathToFileLog + "\\log.txt";

		try 
		{
			if (!std::filesystem::exists(CLog::Impl::FinalPathToFileLog)) 
			{
				if (!std::filesystem::create_directory(CLog::Impl::FinalPathToFileLog)) 
				{
					return PositiveChecks::P_DIR_LOG_CREATED;
				}
			}

			if (!std::filesystem::exists(path_to_log)) 
			{
				std::ofstream recordFile(path_to_log);
				if (recordFile.is_open()) 
				{
					struct tm* time_info = pImpl->getCurrentTimeInfo();

					std::ostringstream logStream;
					logStream << "*** log created " << std::put_time(time_info, "(%T:%F)") << " ***\n";
					logStream << "\n";
					recordFile << logStream.str();

					recordFile.close();

					return PositiveChecks::P_FILE_LOG_CREATED;
				}
				else 
				{
					return NegativeChecks::E_FILE_LOG_NOT_OPEN;
				}
			}
			else 
			{
				return PositiveChecks::P_FILE_LOG_FOUND;
			}
		}
		catch (...)
		{
			return NegativeChecks::E_FILE_LOG_SYSTEM_ERROR;
		}
	}

	void CLog::CreateFileSettings()
	{
		json object{};
		std::string startPath = std::filesystem::current_path().string();

		std::string tempScanParh = startPath + "\\" + SETTINGS_FILE_NAME;

		auto ReadJson = [&](const std::string& filename) -> json
		{
			std::ifstream file(filename);
			json data;
			file >> data;
			file.close();
			return data;
		};

		if (std::filesystem::exists(tempScanParh))
		{
			object = ReadJson(tempScanParh);

			auto& path = object["path"];
			CLog::Impl::FinalPathToFileLog = path;

			std::cout << "Path to settings: " << CLog::Impl::FinalPathToFileLog << std::endl;
		}
		else
		{
			object["path"] = startPath;
			std::ofstream recordToFile(SETTINGS_FILE_NAME);
			recordToFile << std::setw(4) << object << std::endl;

			recordToFile.close();
		}
	}

	void CLog::Write(unsigned level, const char* format, ...)
	{
		std::string logLevelString;

		switch (level)
		{
			case LoggingLevels::LOG_WARN:
				logLevelString = "warn";
				break;
			case LoggingLevels::LOG_INFO:
				logLevelString = "info";
				break;
			case LoggingLevels::LOG_DEBUG:
				logLevelString = "debug";
				break;
			case LoggingLevels::LOG_ERROR:
				logLevelString = "error";
				break;
			case LoggingLevels::LOG_OPEN:
				logLevelString = "start";
				break;
			case LoggingLevels::LOG_CLOSE:
				logLevelString = "close";
				break;
		}

		struct tm* time_info = pImpl->getCurrentTimeInfo();

		std::ostringstream logStream;
		logStream << "[" << std::put_time(time_info, "%T:%F") << "] " << logLevelString << ": ";

		va_list args;
		va_start(args, format);

		char buffer[256];
		vsnprintf(buffer, sizeof(buffer), format, args);

		va_end(args);

		logStream << buffer << "\n";

		std::ofstream logFile(CLog::Impl::FinalPathToFileLog + "\\log.txt", std::ios::app);
		if (logFile.is_open())
		{
			logFile << logStream.str();
			logFile.close();
		}
		else
		{
			// Обработка ошибки открытия файла
		}
	}
}