#ifndef APPROVALTESTS_CPP_CONSOLEDIFFREPORTER_H
#define APPROVALTESTS_CPP_CONSOLEDIFFREPORTER_H

#include "ApprovalTests/reporters/CommandReporter.h"
#include "ApprovalTests/reporters/DiffInfo.h"

#include "ForegroundSystemLauncher.h"

// Based on GenericDiffReporter, but using a different launcher
class ConsoleDiffReporter : public CommandReporter {
private:
    ForegroundSystemLauncher launcher;

public:
    explicit ConsoleDiffReporter(const std::string& program);
    explicit ConsoleDiffReporter(const DiffInfo& info);
};

#endif //APPROVALTESTS_CPP_CONSOLEDIFFREPORTER_H
