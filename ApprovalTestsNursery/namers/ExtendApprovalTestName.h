#ifndef APPROVALTESTS_CPP_EXTENDAPPROVALTESTNAME_H
#define APPROVALTESTS_CPP_EXTENDAPPROVALTESTNAME_H

#include "namers/ApprovalTestNamer.h"

class ExtendApprovalTestName
{
public:
    ExtendApprovalTestName(TestName& currentTest, const std::string& scope_name) :
        currentTest(currentTest)
    {
        // Add extra section to output filename, to allow multiple files
        // to verified from a single test:
        currentTest.sections.push_back(scope_name);
    }

    ~ExtendApprovalTestName()
    {
        // Remove the extra section we added in the constructor
        currentTest.sections.pop_back();
    }
private:
    TestName& currentTest;
};

inline ExtendApprovalTestName addAdditionalApprovalTestInformation(std::string info)
{
    return ExtendApprovalTestName(ApprovalTestNamer::currentTest(), std::move(info));
}

#endif //APPROVALTESTS_CPP_EXTENDAPPROVALTESTNAME_H
