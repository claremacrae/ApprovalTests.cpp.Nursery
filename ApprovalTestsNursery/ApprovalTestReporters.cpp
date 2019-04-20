#include "ApprovalTestReporters.h"

#include "ApprovalTests/reporters/QuietReporter.h"
#include "ApprovalTests/reporters/CombinationReporter.h"
#include "ApprovalTests/reporters/WindowsReporters.h"
#include "ApprovalTests/reporters/ClipboardReporter.h"
#include "AutoApproveIfMissingReporter.h"
#include "AutoApproveReporter.h"
#include "FirstNFailuresReporter.h"

#include <memory>

namespace
{
}

std::shared_ptr<Reporter> ApprovalTestReporters::make_shared(Reporter* reporter)
{
    return std::shared_ptr<Reporter>(reporter);
}

Reporter* ApprovalTestReporters::araxisMergeReporter()
{
    return new Windows::AraxisMergeReporter();
}

Reporter* ApprovalTestReporters::beyondCompare4Reporter()
{
    return new Windows::BeyondCompare4Reporter();
}

Reporter* ApprovalTestReporters::autoApproveIfMissingReporter()
{
    return new AutoApproveIfMissingReporter();
}

Reporter* ApprovalTestReporters::autoApproveReporter()
{
    return new AutoApproveReporter;
}

Reporter* ApprovalTestReporters::combinationReporter(Reporter* rep1, Reporter* rep2)
{
    return new CombinationReporter({rep1, rep2});
}

Reporter* ApprovalTestReporters::firstWorkingReporter(Reporter* rep1, Reporter* rep2)
{
    return new FirstWorkingReporter({rep1, rep2});
}

Reporter* ApprovalTestReporters::araxisMergeAndBeyondCompare4Reporter()
{
    return combinationReporter(araxisMergeReporter(), beyondCompare4Reporter());
}

Reporter* ApprovalTestReporters::firstNFailuresReporter(int maximum_failures, Reporter* reporter)
{
    return new FirstNFailuresReporter(maximum_failures, reporter);
}

Reporter* ApprovalTestReporters::first30AraxisMergeAndBeyondCompare4Reporter()
{
    return firstNFailuresReporter(
        30, // Arbitrary limit, as BeyondCompare hangs with many image comparisons
        araxisMergeAndBeyondCompare4Reporter()
    );
}

Reporter* ApprovalTestReporters::first30BeyondCompare4Reporter()
{
    return firstNFailuresReporter(
        30, // Arbitrary limit, as BeyondCompare hangs with many image comparisons
        beyondCompare4Reporter()
    );
}

std::shared_ptr<Reporter> ApprovalTestReporters::currentReporter()
{
    //static std::shared_ptr<Reporter> reporter = make_shared(first30BeyondCompare4Reporter());
    //static std::shared_ptr<Reporter> reporter = make_shared(autoApproveIfMissingReporter());

    // Use a non-graphic reporter by default, in case these tests ever get run in a non-gui
    // environment, where they would throw up large numbers of Araxis Merge comparisons,
    // due to there being no approved files checked in to version control:
    static std::shared_ptr<Reporter> reporter = std::make_shared<QuietReporter>();
    return reporter;
}
