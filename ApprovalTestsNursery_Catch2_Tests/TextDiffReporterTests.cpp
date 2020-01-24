#include "reporters/TextDiffReporter.h"
#include "namers/ApprovalTestNamer.h"

#include "catch2/catch.hpp"

using namespace ApprovalTests;

TEST_CASE("TextDiffReporter finds a differencing tool")
{
    ApprovalTestNamer namer;
    const auto directory = namer.getDirectory();
    const std::string inputFile = directory + "sample_file.txt";

    ApprovalTests::TextDiffReporter reporter;
    REQUIRE(reporter.report(inputFile, inputFile));
}
