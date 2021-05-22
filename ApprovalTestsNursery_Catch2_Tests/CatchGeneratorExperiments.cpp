#include <iostream>
#include "catch2/catch.hpp"

#include "Approvals.h"
#include "reporters/AutoApproveReporter.h"

using namespace ApprovalTests;

// A place to experiment with Catch2' generators, and debug them,
// to get ideas for alternative implementations of our CombinationApprovals

TEST_CASE("Generator1")
{
    auto i = GENERATE(1, 2, 3);
    SECTION(std::to_string(i))
    {
        auto j = GENERATE(-3, -2, -1);
        std::cout << i << ", " << j << '\n';
        SECTION(std::to_string(j))
        {
            Approvals::verify(std::to_string(i) + " " + std::to_string(j));
        }
    }
}

TEST_CASE("Generator2")
{
    // Interesting: sections are not needed - the following does print out all
    // combinations of i, j and k
    auto i = GENERATE(1, 2);

    // auto j = GENERATE(std::string("hello"), std::string("world"));
    auto j = GENERATE(as<std::string>{}, "hello", "world");

    // TODO Check docs for range - is it clear that last value is not included?
    // TODO Docs don't make it clear that step can be negative
    auto k = GENERATE(range(7, 10));
    std::cout << i << ", " << j << ", " << k << '\n';
}
