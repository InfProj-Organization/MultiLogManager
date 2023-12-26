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
		class Impl;

		Impl* pImpl;
	};

	extern LOG_API CLog* pLog;
}