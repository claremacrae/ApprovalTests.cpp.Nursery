#include "reporters/CIBuildOnlyReporter.h"
#include "Approvals.h"
#include "reporters/QuietReporter.h"
#include "SystemUtils.h"

#include "Catch.hpp"

namespace
{
}

TEST_CASE("CIBuildOnlyReporter reports correctly")
{
    auto fakeReporter = std::make_shared<QuietReporter>();

    CIBuildOnlyReporter reporter( fakeReporter );

    auto machineName = SystemUtils::getMachineName();
    if (machineName == "CLARESPC" )
    {
        REQUIRE(! reporter.isRunningUnderCI());
    }
    else
    {
        // Assume the only other run of this code will be on CI machines, for now.
        REQUIRE(reporter.isRunningUnderCI());
    }
}
