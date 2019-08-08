#include "reporters/TextDiffReporter.h"
#include "namers/ApprovalTestNamer.h"

#include "Catch.hpp"

TEST_CASE("TextDiffReporter finds a differencing tool")
{
    ApprovalTestNamer namer;
    const auto directory = namer.getDirectory();
    const std::string inputFile = directory + "sample_file.txt";

    TextDiffReporter reporter;
    REQUIRE(reporter.report(inputFile, inputFile));
}
