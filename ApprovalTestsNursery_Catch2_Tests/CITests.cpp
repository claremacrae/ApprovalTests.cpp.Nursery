#include "Catch.hpp"
#include "ApprovalTests/Approvals.h"
#include "ApprovalTests/namers/ApprovalNamer.h"

#include <cstdio>

TEST_CASE("Fail with ApprovalMissingException")
{
    auto namer = Approvals::getDefaultNamer();

    // Delete auto-created Approved File, in case left over from previous run
    auto approved = namer->getApprovedFile(".txt");
    remove(approved.c_str());
    
    try
    {
        Approvals::verify("Do not approve me - approved file must not exist");
        // See what behaviour is in Travis and Appveyor 
        // - do they block? 
        // - Is there meaningful output?
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
