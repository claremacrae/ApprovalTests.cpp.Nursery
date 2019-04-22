#include "TextDiffReporter.h"
#include "ApprovalTests/Approvals.h"

#include "Catch.hpp"

TEST_CASE("TextDiffReporter writes output to console")
{
    auto disposer = Approvals::useAsFrontLoadedReporter( std::make_shared<TextDiffReporter>() );
    try
    {
        // Test that we get text written to the console
        Approvals::verify("Test TextDiffReporter - Hello world");
    }
    catch(const ApprovalMismatchException&)
    {
        // We intend to arrive here
    }
}
