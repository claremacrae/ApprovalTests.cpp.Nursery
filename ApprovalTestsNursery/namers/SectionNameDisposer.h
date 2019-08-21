#ifndef APPROVALTESTS_CPP_EXTENDAPPROVALTESTNAME_H
#define APPROVALTESTS_CPP_EXTENDAPPROVALTESTNAME_H

#include "namers/ApprovalTestNamer.h"

class SectionNameDisposer
{
public:
    SectionNameDisposer(TestName& currentTest, const std::string& scope_name) :
        currentTest(currentTest)
    {
        // Add extra section to output filename, to allow multiple files
        // to verified from a single test:
        currentTest.sections.push_back(scope_name);
    }

    ~SectionNameDisposer()
    {
        // Remove the extra section we added in the constructor
        currentTest.sections.pop_back();
    }
private:
    TestName& currentTest;
};

struct NamerFactory
{
    static inline SectionNameDisposer appendToOutputFilename(std::string sectionName)
    {
        return SectionNameDisposer(ApprovalTestNamer::currentTest(), sectionName);
    }
};

#endif //APPROVALTESTS_CPP_EXTENDAPPROVALTESTNAME_H
