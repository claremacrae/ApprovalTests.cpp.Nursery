#ifndef APPROVALTESTS_CPP_CATCHREPORTER_H
#define APPROVALTESTS_CPP_CATCHREPORTER_H

#include "reporters/Reporter.h"
#include "FileUtilsAdditions.h"

#include <iostream>

// TODO Need to work out how to include this in a release, without
//      giving a compilation error for those using other test frameworks
// Could check if Catch header has already been included, by checking
// for the Catch version number #defines, but that would only work if
// the Catch header was #included before the Approval Tests single-header
// #include "Catch.hpp"
#ifdef CATCH_VERSION_MAJOR

namespace ApprovalTests
{
    // A reporter which uses Catch CHECK statement to check the output
    class CatchReporter : public Reporter
    {
    public:
        bool report(std::string received, std::string approved) const override
        {
            const auto receivedText =
                FileUtilsAdditions::readFileReturnEmptyIfMissing(received);
            const auto approvedText =
                FileUtilsAdditions::readFileReturnEmptyIfMissing(approved);
            // By using CHECK instead of REQUIRE, program flow continues - Catch does not throw an exception
            std::cout << "Checking content of files:" << std::endl;
            std::cout << "received: " << received << std::endl;
            std::cout << "approved: " << approved << std::endl;
            CHECK(receivedText == approvedText);
            return true;
        }
    };
} // namespace ApprovalTests

#endif // CATCH_VERSION_MAJOR

#endif //APPROVALTESTS_CPP_CATCHREPORTER_H
