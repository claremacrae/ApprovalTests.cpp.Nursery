#include "CIBuildOnlyReporter.h"
#include "ApprovalTests/SystemUtils.h"

#include <vector>
#include <iostream>

CIBuildOnlyReporter::CIBuildOnlyReporter(std::shared_ptr<Reporter> reporter) : m_reporter(reporter)
{
}

bool CIBuildOnlyReporter::report(std::string received, std::string approved) const
{
    if ( ! isRunningUnderCI() )
    {
        return false;
    }
    m_reporter->report(received, approved);
    // Return true regardless of whether our report succeeded or not,
    // so that no later reporters run.
    return true;
}

bool CIBuildOnlyReporter::isRunningUnderCI() const
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
    for ( const auto& variable : environmentVariablesForCI )
    {
        std::cout << "Checking variable " << variable << '\n';
        if ( ! SystemUtils::safeGetEnv(variable.c_str()).empty() )
        {
            std::cout << "Found variable " << variable << '\n';
            return true;
        }
    }
    return false;
}
