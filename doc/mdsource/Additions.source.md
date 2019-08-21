<a id="top"></a>

# Additions - to be moved to AppovalTests.cpp

toc

## Approving multiple files from one test 

ApprovalTests uses the name of the current test to determine the names of output files that it writes. This means that it is by default only convenient to verify one thing per test case.

Sometimes it is useful to be able to verify multiple files in one test case, such as if the setup is slow, or the code being tested creates more than output file.

This can be done with Catch2's `SECTION` and doctest's `SUBCASE`. However, there is no supported way to do this with Google Tests, and it may be desirable to use an approach that Approval Tests can use with all test frameworks it supports.

The function `addAdditionalApprovalTestInformation()` adds an extra piece of text to be added to the filename used for output files.

Example of use:

snippet: verify_multiple_files

---

[Back to User Guide](/doc/README.md#top)
