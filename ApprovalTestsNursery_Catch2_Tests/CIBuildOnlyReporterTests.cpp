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
//    auto devMachine =  (!SystemUtils::safeGetEnv("DEVMACHINE").empty());
//    REQUIRE(ApprovalTests::CIBuildOnlyReporter::isRunningUnderCI() == !devMachine);
}
