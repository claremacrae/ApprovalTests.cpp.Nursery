#ifndef APPROVALTESTS_CPP_COMBINATIONAPPROVALSOLD_H
#define APPROVALTESTS_CPP_COMBINATIONAPPROVALSOLD_H

#include <functional>
#include <vector>
#include <ostream>
#include "reporters/DefaultReporter.h"
#include "reporters/Reporter.h"
#include "Approvals.h"

class Empty
{
public:
    template< typename Other>
    bool operator!=(const Other &/*rhs*/) const {
        return true;
    }

    bool operator!=(const Empty &/*rhs*/) const {
        return false;
    }

    friend std::ostream &operator<<(std::ostream &os, const Empty&) {
        os << "This should never be written - see Empty\n";
        return os;
    }

};

class CombinationApprovalsOld
{
public:
    CombinationApprovalsOld() = delete;
    ~CombinationApprovalsOld() = delete;

    template <
            typename Container1,
            typename Container2,
            typename Container3,
            typename ReturnType>
    static void verifyAllCombinations(
            std::function<ReturnType (
                    typename Container1::value_type,
                    typename Container2::value_type,
                    typename Container3::value_type)> converter,
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
                    ReturnType result = converter(input1, input2, input3);
                    s << "(" << input1;
                    if (empty != input2) { s << ", " << input2; }
                    if (empty != input3) { s << ", " << input3; }
                    s << ") => " << result << '\n';
                }
            }
        }
        Approvals::verify(s.str(), reporter);
    }

    template <
            typename Container1,
            typename Container2,
            typename ReturnType>
    static void verifyAllCombinations(
            std::function<ReturnType (
                    typename Container1::value_type,
                    typename Container2::value_type)> converter,
            const Container1& inputs1,
            const Container2& inputs2,
            const Reporter& reporter = DefaultReporter())
    {
        verifyAllCombinations<
                Container1,
                Container2,
                std::vector<Empty>, ReturnType>([&](
                                                      typename Container1::value_type i1,
                                                      typename Container2::value_type i2,
                                                      Empty){return converter(i1, i2);},
                                              inputs1,
                                              inputs2,
                                              empty(),
                                              reporter);
    }

    template <
        typename Function,
        typename Container1
        >
    static void verifyAllCombinations(
            Function converter,
            const Container1& inputs1,
            const Reporter& reporter = DefaultReporter())
    {
        verifyAllCombinations<
            Container1,
                std::vector<Empty>, typename std::result_of<Function(typename Container1::value_type)>::type >([&](
                                                      typename Container1::value_type i1,
                                                      Empty){return converter(i1);},
                                              inputs1,
                                              empty(),
                                              reporter);
    }

    template <
        typename Container1,
        typename ReturnType>
    static void verifyAllCombinations(
        std::function<ReturnType (
            typename Container1::value_type)> converter,
        const Container1& inputs1,
        const Reporter& reporter = DefaultReporter())
    {
        verifyAllCombinations<decltype(converter)>(converter, inputs1, reporter);
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
