#pragma once

namespace Log
{
	enum PositiveChecks
	{
		P_FILE_LOG_CREATED = 0x201, //-' Файл успешно создан
		P_FILE_LOG_FOUND = 0x202, //-' Файл уже существует
	};

	enum NegativeChecks
	{
		E_FILE_LOG_NOT_OPEN = 0x601, //-' Ошибка открытия файла для записи
		E_FILE_LOG_SYSTEM_ERROR = 0x602, //-' Ошибка файловой системы
	};

	class LOG_API CLog
	{
	public: 
		CLog();
		virtual ~CLog();

		u32Type CreateLog();

		void CreateFileSettings();

	protected:
		class Impl;

		Impl* pImpl;
	};

	extern LOG_API CLog* pLog;
}