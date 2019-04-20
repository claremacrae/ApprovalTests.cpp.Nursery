#include "AutoApproveReporter.h"
#include "ApprovalTests/FileUtils.h"

#include <iostream>

bool AutoApproveReporter::report(std::string received, std::string approved) const
{
    // TODO actually move, not copy
    FileUtils::copyFile( received, approved);
    std::cout << "file " << approved << " automatically approved - next run should succeed\n";
    return true;
}
