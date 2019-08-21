#include <ApprovalTests/Approvals.h>
#include "namers/ExtendApprovalTestName.h"
#include "Catch.hpp"

TEST_CASE( "It can add sections to file names" )
{
    {
        auto section_namer = addAdditionalApprovalTestInformation("case1");
        Approvals::verify("Some state to be verified .case1 will be in the filename");
    }
    {
        auto section_namer = addAdditionalApprovalTestInformation("case2");
        Approvals::verify("Some different state to be verified");
    }
}
