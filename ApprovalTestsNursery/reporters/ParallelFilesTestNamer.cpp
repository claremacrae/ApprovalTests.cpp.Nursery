#include "ParallelFilesTestNamer.h"

namespace
{
}

std::string ParallelFilesTestNamer::getFullFileNameWithExtraDirectory(string approved, string extensionWithDot)
{
    std::string outputDirectory = getDirectory() +  approved;
    SystemUtils::ensureDirectoryExists(outputDirectory);

    std::string outputFile = getFileName() + "." + getTestName() + extensionWithDot;

    return outputDirectory + SystemUtils::getDirectorySeparator() + outputFile;
}

std::string ParallelFilesTestNamer::getApprovedFile(string extensionWithDot)
{
    return getFullFileNameWithExtraDirectory("approved", extensionWithDot);
}

std::string ParallelFilesTestNamer::getReceivedFile(string extensionWithDot)
{
    return getFullFileNameWithExtraDirectory("received", extensionWithDot);
}
