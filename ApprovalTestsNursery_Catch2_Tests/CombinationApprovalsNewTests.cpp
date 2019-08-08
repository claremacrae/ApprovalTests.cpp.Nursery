#include "Catch.hpp"
#include <map>
#include <vector>
#include <string>
#include "PairUtilities.h"
#include "CombinationApprovalsNew.h"
#include "DuplicateFakeReporter.h"
#include "CombinationTestHelpers.h"

TEST_CASE("YouCanVerifyCombinationsNewOf1") {
    std::vector<std::string> words{"hello", "world"};
    CombinationApprovalsNew::verifyAllCombinations( [](std::string s){return s + "!";}, words);
}

TEST_CASE("YouCanVerifyCombinationsNewOf1WithTemplateParameters") {
    std::vector<std::string> words{"hello", "world"};
    CombinationApprovalsNew::verifyAllCombinations<std::vector<std::string>, std::string>( [](std::string s){return s + "!";}, words);
}

TEST_CASE("YouCanVerifyCombinationsNewOf1Reports") {
    std::cout << "YouCanVerifyCombinationsNewOf1Reports entered\n";
    std::vector<std::string> words{"hello", "world"};
    auto reporter = std::make_shared<DuplicateFakeReporter>(); 
    auto frontLoadReporter = Approvals::useAsFrontLoadedReporter(reporter);
    try
    {
        CombinationApprovalsNew::verifyAllCombinations( [](std::string s){return s + "!";}, words);
    }
    catch(const ApprovalException&)
    {
        // ignore
    }
    REQUIRE(reporter->called == true);
}

// begin-snippet: YouCanVerifyCombinationsNewOf2
TEST_CASE("YouCanVerifyCombinationsNewOf2") {
    std::vector<std::string> v{"hello", "world"};
    std::vector<int> numbers{1, 2, 3};
    CombinationApprovalsNew::verifyAllCombinations<
        std::vector<std::string>, std::vector<int>, std::pair<std::string, int>>(
            [](std::string s, int i){return std::make_pair(s, i);},
            v,
            numbers);
}
// end-snippet

#if 0
TEST_CASE("YouCanVerifyCombinationsNewOf9") {
    std::vector<std::string> letters{"a", "b"};
    CombinationApprovalsNew::verifyAllCombinations<
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

TEST_CASE("CombinationNewOf1WithLambda") {
    CombinationApprovalsNew::verifyAllCombinations<
            std::vector<std::string>,
            std::string>( [](
            std::string s1)
                              {return s1;}, {"a"});
}

TEST_CASE("CombinationNewOf2WithLambda") {
    CombinationApprovalsNew::verifyAllCombinations<
            std::vector<std::string>,
            std::vector<std::string>,
            std::string>( [](
            std::string s1,
            std::string s2)
                              {return s1 + s2;}, {"a"}, {"b"});
}

TEST_CASE("CombinationNewOf3WithLambda") {
    CombinationApprovalsNew::verifyAllCombinations<
            std::vector<std::string>,
            std::vector<std::string>,
            std::vector<std::string>,
            std::string>( [](
            std::string s1,
            std::string s2,
            std::string s3)
                              {return s1 + s2 + s3;}, {"a"}, {"b"}, {"c"});
}

TEST_CASE("CombinationNewOf1WithFunction") {
    CombinationApprovalsNew::verifyAllCombinations<
            std::vector<std::string>,
            std::string>(concatenate1, {"a"});
}

TEST_CASE("CombinationNewOf2WithFunction") {
    CombinationApprovalsNew::verifyAllCombinations<
            std::vector<std::string>,
            std::vector<std::string>,
            std::string>(concatenate2, {"a"}, {"b"});
}

TEST_CASE("CombinationNewOf3WithFunction") {
    CombinationApprovalsNew::verifyAllCombinations<
            std::vector<std::string>,
            std::vector<std::string>,
            std::vector<std::string>,
            std::string>(concatenate3, {"a"}, {"b"}, {"c"});
}

