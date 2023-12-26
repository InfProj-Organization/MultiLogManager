#include <iostream>

#include <iostream>
#include <fstream>
#include <span>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

#include "..\MultiLogManager\Data.hpp"
#include "..\MultiLogManager\Exports.hpp"
#include "..\MultiLogManager\Log\Log.hpp"

using namespace Log;

int main()
{
    pLog = new CLog();
    std::cout << "Hello World!\n";

    pLog->CreateFileSettings();

    pLog->CreateLog();

    delete pLog;

    return 1;
}
