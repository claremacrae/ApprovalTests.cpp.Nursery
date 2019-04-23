#include "FirstNFailuresReporter.h"

FirstNFailuresReporter::FirstNFailuresReporter(int maximum_failures, Reporter* reporter):
    maximum_failures_(maximum_failures),
    reporter_(std::unique_ptr<Reporter>(reporter))
{
}

bool FirstNFailuresReporter::report(std::string received, std::string approved) const
{
    failure_count_ += 1;
    if (failure_count_ > maximum_failures_)
    {
        return false;
    }
    return reporter_->report(received, approved);
}
