#include "reporters/CatchReporter.h"
#include "ApprovalTests/Approvals.h"

#include "Catch.hpp"

TEST_CASE("CatchReporter logs failure", "[!shouldfail]")
{
    // Force this reporter to be used, by overriding any existing
    // front-loaded-reporter:
    auto reporter = std::make_shared<CatchReporter>();
    auto disposer = Approvals::useAsFrontLoadedReporter( reporter );

    try
    {
       Approvals::verify("Test CatchReporter - CatchReporter will report 'Failure', but this test will pass");
    }
    catch(const ApprovalException&)
    {
        // We intend to arrive here
        SUCCEED("CatchReporter reported a failure, as intended");
    }
}
