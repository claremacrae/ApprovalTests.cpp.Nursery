#include "Catch.hpp"
#include <map>
#include <vector>
#include <string>
#include "PairUtilities.h"
#include "CombinationApprovalsNew.h"
#include <reporters/FakeReporter.h>
#include "CombinationTestHelpers.h"

TEST_CASE("YouCanVerifyCombinationsNewOf1") {
    std::vector<std::string> words{"hello", "world"};
    CombinationApprovalsNew::verifyAllCombinations( [](std::string s){return s + "!";}, words);
}

TEST_CASE("YouCanVerifyCombinationsNewOf1Reports") {
    std::cout << "YouCanVerifyCombinationsNewOf1Reports entered\n";
    std::vector<std::string> words{"hello", "world"};
    auto reporter = std::make_shared<FakeReporter>(); 
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
    CombinationApprovalsNew::verifyAllCombinations(
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
    auto inputs1 = {"a"};
    CombinationApprovalsNew::verifyAllCombinations([](
            std::string s1)
                              {return s1;}, inputs1);
}

TEST_CASE("CombinationNewOf2WithLambda") {
    auto inputs1 = {"a"};
    auto inputs2 = {"b"};
    CombinationApprovalsNew::verifyAllCombinations([](
            std::string s1,
            std::string s2)
                              {return s1 + s2;}, inputs1, inputs2);
}

TEST_CASE("CombinationNewOf3WithLambda") {
    auto inputs1 = {"a"};
    auto inputs2 = {"b"};
    auto inputs3 = {"c"};
    CombinationApprovalsNew::verifyAllCombinations([](
            std::string s1,
            std::string s2,
            std::string s3)
                              {return s1 + s2 + s3;}, inputs1, inputs2, inputs3);
}

TEST_CASE("CombinationNewOf1WithFunction") {
    // Inlining this gives "template argument deduction/substitution failed"
    // cannot convert 'concatenate1' (type 'std::string(std::string) 
    // {aka std::basic_string<char>(std::basic_string<char>)}')
    // to type 'std::vector<std::basic_string<char> >'
    // https://stackoverflow.com/questions/12431495/initializer-list-and-template-type-deduction
    auto inputs1 = {"a"};
    CombinationApprovalsNew::verifyAllCombinations(concatenate1, inputs1);
}

TEST_CASE("CombinationNewOf2WithFunction") {
    auto inputs1 = {"a"};
    auto inputs2 = {"b"};
    CombinationApprovalsNew::verifyAllCombinations(concatenate2, inputs1, inputs2);
}

TEST_CASE("CombinationNewOf3WithFunction") {
    auto inputs1 = {"a"};
    auto inputs2 = {"b"};
    auto inputs3 = {"c"};
    CombinationApprovalsNew::verifyAllCombinations(concatenate3, inputs1, inputs2, inputs3);
}

