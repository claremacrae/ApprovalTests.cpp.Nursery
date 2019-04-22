#include "CatchReporter.h"
#include "FileUtilsAdditions.h"

// TODO Need to work out how to include this in a release, without
//      giving a compilation error for those using Google Test Framework
#include "Catch.hpp"

bool CatchReporter::report(std::string received, std::string approved) const
{
    const auto receivedText = FileUtilsAdditions::readFileReturnEmptyIfMissing(received);
    const auto approvedText = FileUtilsAdditions::readFileReturnEmptyIfMissing(approved);
    // By using CHECK instead of REQUIRE, program flow continues - Catch does not throw an exception
    CHECK( receivedText == approvedText );
    return true;
}