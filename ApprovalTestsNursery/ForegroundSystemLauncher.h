#ifndef APPROVALTESTS_CPP_FOREGROUNDSYSTEMLAUNCHER_H
#define APPROVALTESTS_CPP_FOREGROUNDSYSTEMLAUNCHER_H

#include "ApprovalTests/reporters/CommandLauncher.h"
#include "ApprovalTests/reporters/SystemLauncher.h"

// Based on SystemLauncher, and differs in that it runs the command in
// the foreground instead of the background, so that any text output is
// interleaved in with the output from the test framework.
class ForegroundSystemLauncher : public CommandLauncher
{
public:
    bool launch(std::vector<std::string> argv) override;
};

#endif //APPROVALTESTS_CPP_FOREGROUNDSYSTEMLAUNCHER_H
