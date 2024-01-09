#pragma once

namespace Log
{
	enum PositiveChecks
	{
		P_FILE_LOG_CREATED = 0x201, //-' Файл успешно создан
		P_FILE_LOG_FOUND = 0x202, //-' Файл уже существует
		P_DIR_LOG_CREATED = 0x203, //-' Файл для сохранения лога не нашел папку, создаем ее
	};

	enum NegativeChecks
	{
		E_FILE_LOG_NOT_OPEN = 0x601, //-' Ошибка открытия файла для записи
		E_FILE_LOG_SYSTEM_ERROR = 0x602, //-' Ошибка файловой системы
	};

	enum LoggingLevels
	{
		LOG_WARN = 0,
		LOG_INFO,
		LOG_DEBUG,
		LOG_ERROR,
		LOG_OPEN,
		LOG_CLOSE,
	};

	class LOG_API CLog
	{
	public: 
		CLog();
		virtual ~CLog();

		char logFileName[256];
		unsigned CreateLog();

		void CreateFileSettings();
		void Write(unsigned level, const char* format, ...);

	protected:
		class Impl;

		Impl* pImpl;
	};

	extern LOG_API CLog* pLog;
}