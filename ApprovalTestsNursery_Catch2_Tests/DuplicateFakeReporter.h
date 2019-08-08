#ifndef APPROVALTESTS_CPP_DUPLICATEFAKEREPORTER_H
#define APPROVALTESTS_CPP_DUPLICATEFAKEREPORTER_H

#include "ApprovalTests/reporters/Reporter.h"

// This is a duplicate copy of ApprovalTests.cpp/ApprovalTests_Catch2_Tests/reporters/FakeReporter.h
// the build failures I get in CI only, when using that original file here.
// e.g.
// https://ci.appveyor.com/project/claremacrae/approvaltests-cpp-nursery/builds/26566643
// https://travis-ci.com/claremacrae/ApprovalTests.cpp.Nursery/builds/122477125
class DuplicateFakeReporter : public Reporter {
public:
    bool working;
    mutable bool called = false;

    inline DuplicateFakeReporter(bool working = true) : working(working) {
    }

    inline virtual bool report(std::string /*received*/, std::string /*approved*/) const override
    {
        called = true;
        return working;
    }
};

#endif //APPROVALTESTS_CPP_DuplicateFakeReporter_H
