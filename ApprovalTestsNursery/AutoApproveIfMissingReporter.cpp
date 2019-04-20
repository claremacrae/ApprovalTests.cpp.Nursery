#include "AutoApproveIfMissingReporter.h"
#include "ApprovalTests/FileUtils.h"

#include <iostream>

bool AutoApproveIfMissingReporter::report(std::string received, std::string approved) const
{
    // if approved already exists, we do nothing
    if (FileUtils::fileExists(approved))
    {
        return false; // we did not handle this difference
    }
    else
    {
        // approved does not exist, move received to approved and return true
        // TODO actually move, not copy
        FileUtils::copyFile( received, approved );
        std::cout << "file " << approved << " automatically approved - next run should succeed\n";
        return true;
    }
}
