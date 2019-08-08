#include "Catch.hpp"
#include "FileUtilsAdditions.h"
#include "namers/ApprovalTestNamer.h"
#include "Approvals.h"
#include "reporters/DiffReporter.h"

#include <iostream>

TEST_CASE("It reads sample_file.txt correctly")
{
    ApprovalTestNamer namer;
    const auto directory = namer.getDirectory();
    const std::string inputFile = directory + "sample_file.txt";
    
    Approvals::verify( FileUtilsAdditions::readFileThrowIfMissing(inputFile), DiffReporter());
}

TEST_CASE("readFileThrowIfMissing() throws if file is missing")
{
    bool exceptionThrown = false;
    try
    {
        FileUtilsAdditions::readFileThrowIfMissing("some file name that does not exist 1234567890.txt");
    }
    catch( const std::exception&)
    {
        exceptionThrown = true;
    }
    REQUIRE(exceptionThrown);
}

TEST_CASE("readFileReturnEmptyIfMissing() returns empty string if file is missing")
{
    REQUIRE( "" == FileUtilsAdditions::readFileReturnEmptyIfMissing("some file name that does not exist 1234567890.txt") );
}
