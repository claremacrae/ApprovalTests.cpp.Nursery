#ifndef APPROVALTESTS_CPP_NURSERY_CIBUILDONLYREPORTER_H
#define APPROVALTESTS_CPP_NURSERY_CIBUILDONLYREPORTER_H

#include "reporters/Reporter.h"

#include <memory>

// A reporter which uses the supplied reporter, if called on a supported Continuous Integration system
class CIBuildOnlyReporter : public Reporter
{
private:
    std::shared_ptr<Reporter> m_reporter;
public:
    explicit CIBuildOnlyReporter(std::shared_ptr<Reporter> reporter);
    bool report(std::string received, std::string approved) const override;
    bool isRunningUnderCI() const;
};

#endif //APPROVALTESTS_CPP_NURSERY_CIBUILDONLYREPORTER_H
