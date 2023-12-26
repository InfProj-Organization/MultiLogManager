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

	std::string CLog::FinalPathToFileLog = "";

	CLog::CLog()
	{

	}

	CLog::~CLog()
	{
	
	}

	void CLog::WriteJsonToFile(const std::string& filename, const json& data)
	{
		std::ofstream file(filename);
		file << data;
		file.close();
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
			this->FinalPathToFileLog = path;

			std::cout << "Path to settings: " << this->FinalPathToFileLog << std::endl;
		}
		else
		{
			object["path"] = startPath;
			std::ofstream recordToFile(SETTINGS_FILE_NAME);
			recordToFile << std::setw(4) << object << std::endl;

			recordToFile.close();
		}
	}

	void CLog::CreateLog()
	{
		
	}
}