#ifndef APPROVALTESTS_CPP_APPROVALTESTREPORTERS_H
#define APPROVALTESTS_CPP_APPROVALTESTREPORTERS_H

#include "reporters/Reporter.h"

#include <memory>

namespace ApprovalTestReporters
{
    //-----------------------------------------------------------------------------

    std::shared_ptr<Reporter> make_shared(Reporter* reporter);

    Reporter* araxisMergeReporter();

    Reporter* beyondCompare4Reporter();

    Reporter* autoApproveIfMissingReporter();

    Reporter* autoApproveReporter();

    Reporter* combinationReporter(Reporter* rep1, Reporter* rep2);

    Reporter* firstWorkingReporter(Reporter* rep1, Reporter* rep2);

    Reporter* araxisMergeAndBeyondCompare4Reporter();

    Reporter* firstNFailuresReporter(int maximum_failures, Reporter* reporter);

    Reporter* first30AraxisMergeAndBeyondCompare4Reporter();

    Reporter* first30BeyondCompare4Reporter();

    std::shared_ptr<Reporter> currentReporter();
}

#endif // APPROVALTESTS_CPP_APPROVALTESTREPORTERS_H
