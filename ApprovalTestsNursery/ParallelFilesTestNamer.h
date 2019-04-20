#ifndef APPROVALTESTS_CPP_PARALLELFILESTESTNAMER_H
#define APPROVALTESTS_CPP_PARALLELFILESTESTNAMER_H

#include "ApprovalTests/namers/ApprovalTestNamer.h"

/*! \brief Modified ApprovalTestNamer implementation that allows an entire directory of
approved and received files to be compared, using a directory-comparison tool.

This implementation of ApprovalNamer puts the approved and received files in parallel directories,
with identical file names.

The pattern used by this class for file names is:
- approved/[test file name].[test name].[extension]
- received/[test file name].[test name].[extension]

For example:
- approved/MyImageWriterTest.MyTestCase.png
- received/MyImageWriterTest.MyTestCase.png

This layout enables Beyond Compare 4 (or any other directory comparison tool) to compare the
"approved/" and "received/" directories, and "approve" one or more files by copying them from
"received/" to "approved/"

The "approved/" and "received/" directories are created automatically.

<h2>Limitations</h2>

As of version 3.1.0, ApprovalTests.cpp has no easy way to use a custom ApprovalNamer
implementation. Nearly all the convenience-methods, such as verifyAll(), and verifyAllCombinations(),
use ApprovalTestNamer internally.

So to use this class, you have to use FileApprover::verify() directly, which is the one
Approvals function that allows a custom namer class to be used.

<h2>Motivation</h2>

The default naming convention used by ApprovalTests is pairs of adjacent files, with approved and received
in the file names:
- [test file name].[test name].approved.[extension]
- [test file name].[test name].received.[extension]

For example:
- MyImageWriterTest.MyTestCase.approved.png
- MyImageWriterTest.MyTestCase.received.png

The problem with the default behaviour is when using Beyond Compare4 to approve images.
It only allows images to be copied from once side to the other when comparing entire folders,
not when comparing individual pairs of files.
https://www.scootersoftware.com/vbulletin/forum/beyond-compare-4-discussion/general/79793-in-image-comparisons-how-to-copy-left-to-right
*/
class ParallelFilesTestNamer : public ApprovalTestNamer
{
public:
    virtual ~ParallelFilesTestNamer() = default;

    std::string getFullFileNameWithExtraDirectory(string approved, string extensionWithDot);

    virtual std::string getApprovedFile(string extensionWithDot) override;
    virtual std::string getReceivedFile(string extensionWithDot) override;
};

#endif // APPROVALTESTS_CPP_PARALLELFILESTESTNAMER_H
