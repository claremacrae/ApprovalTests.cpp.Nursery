#ifndef APPROVALTESTS_CPP_FIRSTNFAILURESREPORTER_H
#define APPROVALTESTS_CPP_FIRSTNFAILURESREPORTER_H

#include "ApprovalTests/reporters/Reporter.h"

#include <memory>

namespace ApprovalTests
{
    // Handle only up to a given number of failures. After that, just do nothing and return false.
    // Example use case: a GUI comparison tool creaks after being asked to show more than a
    // certain number of image comparisons.
    class FirstNFailuresReporter : public Reporter
    {
    public:
        FirstNFailuresReporter(int maximum_failures, Reporter* reporter)
            : maximum_failures_(maximum_failures),
              reporter_(std::unique_ptr<Reporter>(reporter))
        {
        }

        bool report(std::string received, std::string approved) const override
        {
            failure_count_ += 1;
            if (failure_count_ > maximum_failures_)
            {
                return false;
            }
            return reporter_->report(received, approved);
        }

    private:
        mutable int failure_count_ = 0;
        int maximum_failures_ = 0;
        std::unique_ptr<Reporter> reporter_;
    };
} // namespace ApprovalTests

#endif //APPROVALTESTS_CPP_FIRSTNFAILURESREPORTER_H
