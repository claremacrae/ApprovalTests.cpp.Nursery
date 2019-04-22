#include "CatchReporter.h"
#include "ApprovalTests/Approvals.h"

#include "Catch.hpp"

TEST_CASE("CatchReporter logs failure", "[!shouldfail]")
{
    CatchReporter reporter;

    try
    {
       Approvals::verify("This test is expected to fail", reporter);
    }
    catch(const ApprovalException& e)
    {
        // We intend to arrive here
        SUCCEED("CatchReporter reported a failure, as intended");
    }
}
