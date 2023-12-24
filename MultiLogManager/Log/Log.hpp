#pragma once

namespace Log
{
	enum DescriptionErrors
	{
		E_OK = 1,
	};

	class LOG_API CLog
	{
	protected:
		const std::string FilePathToSettings;

	public: 
		CLog();
		virtual ~CLog();

		int CreateFileSettings();
		int WriteJsonToFile(const std::string& filename, const json& data);

		json ReadJsonFromFile(const std::string& filename);

		inline std::string GetToFilePathToSettings() { return this->FilePathToSettings; }
	};

	extern LOG_API CLog* pLog;
}