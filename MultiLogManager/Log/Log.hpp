#pragma once

namespace Log
{
	enum DescriptionErrors
	{
		E_OK = 1,
		E_FILE_IO_ERROR = 805,
	};

	class LOG_API CLog
	{
	protected:
		std::string FilePathToSettings;

		std::filesystem::path dllPath;
		std::filesystem::path settingsPath;

	public: 
		CLog();
		virtual ~CLog();

		int CreateFileSettings();
		int ReadFileSettings();
		int WriteJsonToFile(const std::string& filename, const json& data);

		json ReadJsonFromFile(const std::string& filename);

		inline std::string GetToFilePathToSettings() { return this->FilePathToSettings; }
	};

	extern LOG_API CLog* pLog;
}