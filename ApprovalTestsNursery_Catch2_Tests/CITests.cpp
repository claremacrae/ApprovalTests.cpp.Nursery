#include "Catch.hpp"
#include "ApprovalTests/Approvals.h"
#include "ApprovalTests/namers/ApprovalNamer.h"
#include "ApprovalTests/reporters/QuietReporter.h"

#include <cstdio>

TEST_CASE("Fail with ApprovalMissingException")
{
    // For now, don't pop up a GUI reporter, as this is getting
    // pretty irritating on my PC, whilst running other tests
    auto disposer = Approvals::useAsDefaultReporter( std::make_shared<QuietReporter>());
    auto namer = Approvals::getDefaultNamer();

    // Delete auto-created Approved File, in case left over from previous run
    auto approved = namer->getApprovedFile(".txt");
    remove(approved.c_str());
    
    try
    {
        Approvals::verify("Do not approve me - approved file must not exist");
        // In Travis and Appveyor, neither finds a diffing tool
        // So neither blocks
        // However, they don't write out what the differences are.
    }
    catch(const ApprovalMissingException& e)
    {
        // We intend to arrive here
        std::cout << "\n\n" << e.what() << "\n\n";

        // Re-delete auto-created Approved File, so it doesn't get checked
        // in to git
        remove(approved.c_str());
    }
}

TEST_CASE("Fail with ApprovalMismatchException")
{
    // For now, don't pop up a GUI reporter, as this is getting
    // pretty irritating on my PC, whilst running other tests
    auto disposer = Approvals::useAsDefaultReporter( std::make_shared<QuietReporter>());

    try
    {
        Approvals::verify("I will fail - do not approve me");
    }
    catch(const ApprovalMismatchException& e)
    {
        std::cout << "\n\n" << e.what() << "\n\n";
        // We intend to arrive here
    }
}
