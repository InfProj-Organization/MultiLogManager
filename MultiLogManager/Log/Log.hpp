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

		void CreateLog();
		void CreateFileSettings();

	protected:
		class Impl;

		Impl* pImpl;
	};

	extern LOG_API CLog* pLog;
}