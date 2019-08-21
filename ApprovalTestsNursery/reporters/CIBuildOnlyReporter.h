#ifndef APPROVALTESTS_CPP_CIBUILDONLYREPORTER_H
#define APPROVALTESTS_CPP_CIBUILDONLYREPORTER_H

#include "reporters/Reporter.h"
#include "SystemUtils.h"

#include <vector>
#include <memory>

// A reporter which uses the supplied reporter, if called on a supported Continuous Integration system
class CIBuildOnlyReporter : public Reporter
{
private:
    std::shared_ptr<Reporter> m_reporter;
public:
    explicit CIBuildOnlyReporter(std::shared_ptr<Reporter> reporter) : m_reporter(reporter)
    {
    }

    bool report(std::string received, std::string approved) const override
    {
        if (!isRunningUnderCI())
        {
            return false;
        }
        m_reporter->report(received, approved);
        // Return true regardless of whether our report succeeded or not,
        // so that no later reporters run.
        return true;
    }

    bool isRunningUnderCI() const
    {
        // Travis: https://docs.travis-ci.com/user/environment-variables/#default-environment-variables
        //  CI=true
        //  TRAVIS=true
        //  CONTINUOUS_INTEGRATION=true

        // AppVeyor: https://www.appveyor.com/docs/environment-variables/
        //  APPVEYOR - True (true on Ubuntu image) if build runs in AppVeyor environment
        //  CI - True (true on Ubuntu image) if build runs in AppVeyor environment

        // TeamCity: https://confluence.jetbrains.com/display/TCD18/Predefined+Build+Parameters
        //  TEAMCITY_VERSION
        std::vector<std::string> environmentVariablesForCI = { "CI", "TEAMCITY_VERSION" };
        for (const auto& variable : environmentVariablesForCI)
        {
            if (!SystemUtils::safeGetEnv(variable.c_str()).empty())
            {
                return true;
            }
        }
        return false;
    }
};

#endif //APPROVALTESTS_CPP_CIBUILDONLYREPORTER_H
