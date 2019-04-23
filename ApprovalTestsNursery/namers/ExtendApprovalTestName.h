#ifndef APPROVALTESTS_CPP_EXTENDAPPROVALTESTNAME_H
#define APPROVALTESTS_CPP_EXTENDAPPROVALTESTNAME_H

#include "ApprovalTests/namers/ApprovalTestNamer.h"

// TODO Move to approvals
class ExtendApprovalTestName
{
public:
    ExtendApprovalTestName(TestName& currentTest, const std::string& scope_name);

    ~ExtendApprovalTestName();
private:
    TestName& currentTest;
};

// TODO Move to approvals
ExtendApprovalTestName addAdditionalApprovalTestInformation(std::string info);

#endif //APPROVALTESTS_CPP_EXTENDAPPROVALTESTNAME_H
