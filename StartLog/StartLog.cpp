#include <iostream>

#include <iostream>
#include <fstream>
#include <span>

#include <nlohmann/json.hpp>

using json = nlohmann::json;

#include "..\MultiLogManager\Exports.hpp"
#include "..\MultiLogManager\Log\Log.hpp"

using namespace Log;

int main()
{
    pLog = new CLog();
    std::cout << "Hello World!\n";

    pLog->CreateFileSettings();

    pLog->CreateLog();

    pLog->Write("info", "~ %s", __FUNCTION__);

    pLog->Write("info", "~ %s", __FUNCTION__);
    pLog->Write("info", "~ %s", __FUNCTION__);
    pLog->Write("info", "~ %s", __FUNCTION__);
    //pLog->Write(0, "~ %s", __FUNCTION__);

    //CLog::Log(0, "~ %s", __FUNCTION__);

    pLog->Close();

    delete pLog;

    return 1;
}
