#include <ApprovalTests/Approvals.h>
#include "namers/SectionNameDisposer.h"
#include "Catch.hpp"

TEST_CASE( "It can add sections to file names" )
{
    // begin-snippet: verify_multiple_files
    // ... code inside a test case
    {
        auto section_namer = addAdditionalApprovalTestInformation("case1");
        Approvals::verify("Some state to be verified .case1 will be in the filename");
        // Approved file will be 'path_to_test_file/FileName.TestName.case1.approved.txt'
    }
    {
        auto section_namer = addAdditionalApprovalTestInformation("case2");
        Approvals::verify("Some different state to be verified");
        // Approved file will be 'path_to_test_file/FileName.TestName.case2.approved.txt'
    }
    // end-snippet
}
