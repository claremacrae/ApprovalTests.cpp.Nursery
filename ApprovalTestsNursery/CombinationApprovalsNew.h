#ifndef APPROVALTESTS_CPP_COMBINATIONAPPROVALSNEW_H
#define APPROVALTESTS_CPP_COMBINATIONAPPROVALSNEW_H

#include <functional>
#include <vector>
#include <ostream>
#include "reporters/DefaultReporter.h"
#include "reporters/Reporter.h"
#include "Approvals.h"

#include "CombinationApprovals.h" // For Empty

// TODO Fix the calling of this when a reporter is supplied
// TODO Fix the test for supplying of reporter - it's not supplying a reporter,
//      so not actually testing what it was originally intended to do.
// TODO Can I use variadic templates to simplify code
// TODO Can I reduce copying - read up on rvalue references
// TODO Review Jonathan's ranges cartesian_product.hpp
// TODO Understand if it's always valid to pass function as template type?
// TODO If not variadic, bump back up to 9 arguments
// TODO Can I combine this with the old code, which requires template types

class CombinationApprovalsNew
{
public:
    CombinationApprovalsNew() = delete;
    ~CombinationApprovalsNew() = delete;

    template <
        typename Function,
        typename Container1,
        typename Container2,
        typename Container3,
        // prevent compilation failure from user-supplied reporter being treated as a container:
        typename std::enable_if<! std::is_base_of<Reporter, Container3>::value, int>::type = 0>
    static void verifyAllCombinations(
        Function converter,
        const Container1& inputs1,
        const Container2& inputs2,
        const Container3& inputs3,
        const Reporter& reporter = DefaultReporter())
    {
        Empty empty;
        std::stringstream s;
        for (auto input1 : inputs1)
        {
            for (auto input2 : inputs2)
            {
                for (auto input3 : inputs3)
                {
                    s << "(" << input1;
                    if (empty != input2) { s << ", " << input2; }
                    if (empty != input3) { s << ", " << input3; }
                    s << ") => " << converter(input1, input2, input3) << '\n';
                }
            }
        }
        Approvals::verify(s.str(), reporter);
    }

    template <
        typename Function,
        typename Container1,
        typename Container2,
        // prevent compilation failure from user-supplied reporter being treated as a container:
        typename std::enable_if<! std::is_base_of<Reporter, Container2>::value, int>::type = 0>
    static void verifyAllCombinations(
        Function converter,
        const Container1& inputs1,
        const Container2& inputs2,
        const Reporter& reporter = DefaultReporter())
    {
        verifyAllCombinations(
            [&](typename Container1::value_type i1,
                typename Container2::value_type i2,
                Empty){return converter(i1, i2);},
            inputs1,
            inputs2,
            empty(),
            reporter);
    }

    template <
        typename Function,
        typename Container1,
        // prevent compilation failure from user-supplied reporter being treated as a container:
        typename std::enable_if<! std::is_base_of<Reporter, Container1>::value, int>::type = 0>
    static void verifyAllCombinations(
        Function converter,
        const Container1& inputs1,
        const Reporter& reporter = DefaultReporter())
    {
        verifyAllCombinations(
            [&](typename Container1::value_type i1,
                Empty){return converter(i1);},
            inputs1,
            empty(),
            reporter);
    }

    // Implementation details: these are left public to allow users
    // to write additional verifyAllCombinations overloads that take more
    // than 9 arguments - unlikely though that may be.
    using EmptyContainer = std::vector<Empty>;
    static EmptyContainer empty()
    {
        return EmptyContainer{Empty()};
    }
};

#endif
