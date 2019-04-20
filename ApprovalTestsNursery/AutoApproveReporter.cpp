#include "AutoApproveReporter.h"
#include "FileUtilsAdditions.h"

#include <iostream>

bool AutoApproveReporter::report(std::string received, std::string approved) const
{
    // TODO actually move, not copy
    FileUtilsAdditions::copyFile( received, approved);
    std::cout << "file " << approved << " automatically approved - next run should succeed\n";
    return true;
}
