#ifndef APPROVALTESTS_CPP_CONSOLEDIFFREPORTER_H
#define APPROVALTESTS_CPP_CONSOLEDIFFREPORTER_H

#include "ApprovalTests/reporters/CommandReporter.h"
#include "ApprovalTests/reporters/DiffInfo.h"

#include "ForegroundSystemLauncher.h"

// Based on GenericDiffReporter, but using a different launcher, namely 
// ForegroundSystemLauncher so that the console output from the diff
// tool is visible in CI logs.
// Use TextDiffReporter if you just want reports of differences 
// to be sent to the console on any platform. 
class ConsoleDiffReporter : public CommandReporter {
private:
    ForegroundSystemLauncher launcher;

public:
    explicit ConsoleDiffReporter(const std::string& program);
    explicit ConsoleDiffReporter(const DiffInfo& info);
};

#endif //APPROVALTESTS_CPP_CONSOLEDIFFREPORTER_H
