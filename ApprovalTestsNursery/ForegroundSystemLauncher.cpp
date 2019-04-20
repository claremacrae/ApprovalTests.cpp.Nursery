#include "ForegroundSystemLauncher.h"

bool ForegroundSystemLauncher::launch(std::vector<std::string> argv)
{
    SystemLauncher temp_launcher;
    if (!temp_launcher.exists(argv.front()))
    {
        return false;
    }

    // Surround each of the arguments by double-quotes:
    const std::string command = std::accumulate(
        argv.begin(), argv.end(), std::string(""),
        [](std::string a, std::string b) {return a + " " + "\"" + b + "\""; });

    // See https://stackoverflow.com/a/9965141/104370 for why the Windows string is so complex:
    const std::string launch = SystemUtils::isWindowsOs() ?
                               (std::string("cmd /S /C ") + "\"" + command + "\"") :
                               (command);
    system(launch.c_str());
    return true;
}
