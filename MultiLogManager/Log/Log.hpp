#pragma once

namespace Log
{
	enum DescriptionErrors
	{
		//-' ?
	};

	class LOG_API CLog
	{
	public: 
		CLog();
		virtual ~CLog();

		void CreateFileSettings();
		void WriteJsonToFile(const std::string& filename, const json& data);
		void CreateLog();

	protected:
		std::string FilePathToLog;

		std::filesystem::path dllPath;
		std::filesystem::path settingsPath;

		static std::string FinalPathToFileLog;
	};

	extern LOG_API CLog* pLog;
}