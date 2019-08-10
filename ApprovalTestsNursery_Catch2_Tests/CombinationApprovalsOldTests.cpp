#include "Catch.hpp"
#include <map>
#include <vector>
#include <string>
#include "PairUtilities.h"
#include "CombinationApprovalsOld.h"
#include <reporters/FakeReporter.h>
#include "CombinationTestHelpers.h"

TEST_CASE("YouCanVerifyCombinationsOf1") {
    std::vector<std::string> words{"hello", "world"};
    CombinationApprovalsOld::verifyAllCombinations<std::vector<std::string>, std::string>( [](std::string s){return s + "!";}, words);
}

TEST_CASE("YouCanVerifyCombinationsOf1Reports") {
    std::vector<std::string> words{"hello", "world"};
    auto reporter = std::make_shared<FakeReporter>(); 
    auto frontLoadReporter = Approvals::useAsFrontLoadedReporter(reporter);
    try
    {
        CombinationApprovalsOld::verifyAllCombinations<std::vector<std::string>, std::string>( [](std::string s){return s + "!";}, words);
    }
    catch(const ApprovalException&)
    {
        // ignore
    }
    REQUIRE(reporter->called == true);
}

// begin-snippet: YouCanVerifyCombinationsOf2
TEST_CASE("YouCanVerifyCombinationsOf2") {
    std::vector<std::string> v{"hello", "world"};
    std::vector<int> numbers{1, 2, 3};
    CombinationApprovalsOld::verifyAllCombinations<
        std::vector<std::string>, std::vector<int>, std::pair<std::string, int>>(
            [](std::string s, int i){return std::make_pair(s, i);},
            v,
            numbers);
}
// end-snippet

#if 0
TEST_CASE("YouCanVerifyCombinationsOf9") {
    std::vector<std::string> letters{"a", "b"};
    CombinationApprovalsOld::verifyAllCombinations<
            std::vector<std::string>,
            std::vector<std::string>,
            std::vector<std::string>,
            std::vector<std::string>,
            std::vector<std::string>,
            std::vector<std::string>,
            std::vector<std::string>,
            std::vector<std::string>,
            std::vector<std::string>,
            std::string>( [](
            std::string s1,
            std::string s2,
            std::string s3,
            std::string s4,
            std::string s5,
            std::string s6,
            std::string s7,
            std::string s8,
            std::string s9)
                              {return s1 + s2 + s3 + s4 + s5 + s6 + s7 + s8 + s9;}, letters, letters, letters, letters, letters, letters, letters, letters, letters);
}
#endif

TEST_CASE("CombinationOf1WithLambda") {
    CombinationApprovalsOld::verifyAllCombinations<
            std::vector<std::string>,
            std::string>( [](
            std::string s1)
                              {return s1;}, {"a"});
}

TEST_CASE("CombinationOf2WithLambda") {
    CombinationApprovalsOld::verifyAllCombinations<
            std::vector<std::string>,
            std::vector<std::string>,
            std::string>( [](
            std::string s1,
            std::string s2)
                              {return s1 + s2;}, {"a"}, {"b"});
}

TEST_CASE("CombinationOf3WithLambda") {
    CombinationApprovalsOld::verifyAllCombinations<
            std::vector<std::string>,
            std::vector<std::string>,
            std::vector<std::string>,
            std::string>( [](
            std::string s1,
            std::string s2,
            std::string s3)
                              {return s1 + s2 + s3;}, {"a"}, {"b"}, {"c"});
}

TEST_CASE("CombinationOf1WithFunction") {
    CombinationApprovalsOld::verifyAllCombinations<
            std::vector<std::string>,
            std::string>(concatenate1, {"a"});
}

TEST_CASE("CombinationOf2WithFunction") {
    CombinationApprovalsOld::verifyAllCombinations<
            std::vector<std::string>,
            std::vector<std::string>,
            std::string>(concatenate2, {"a"}, {"b"});
}

TEST_CASE("CombinationOf3WithFunction") {
    CombinationApprovalsOld::verifyAllCombinations<
            std::vector<std::string>,
            std::vector<std::string>,
            std::vector<std::string>,
            std::string>(concatenate3, {"a"}, {"b"}, {"c"});
}
