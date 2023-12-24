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

	CLog::CLog()
	{

	}

	CLog::~CLog()
	{
	
	}

	int CLog::WriteJsonToFile(const std::string& filename, const json& data)
	{
		std::ofstream file(filename);
		file << data;
		file.close();

		return DescriptionErrors::E_OK;
	}

	json CLog::ReadJsonFromFile(const std::string& filename)
	{
		std::ifstream file(filename);
		json data;
		file >> data;
		file.close();
		return data;
	}

	int CLog::CreateFileSettings()
	{
		json myJson;

		myJson["path"] = "path test";

		std::ofstream outputFile("Settings.json");

		outputFile << std::setw(4) << myJson << std::endl;

		outputFile.close();

		// move it
		json readJson = ReadJsonFromFile("Settings.json");

		std::string message = readJson["path"];

		std::cout << "Read from JSON file: " << message << std::endl;

		return DescriptionErrors::E_OK;
	}
}