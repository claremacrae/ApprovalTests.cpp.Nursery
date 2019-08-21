<a id="top"></a>

# Additions - to be moved to AppovalTests.cpp

toc

## Approving multiple files from one test 

ApprovalTests uses the name of the current test to determine the names of output files that it writes. This means that **by default, there is only one approval file per test case**.

However, sometimes it is useful to be able to verify multiple files in one test case, or have a file per OS or other environment configuration.

Here are some examples of files you might want.

&nbsp;

**Multiple data inputs:**

In this scenario, your test creates 3 files, all of which are being checked when you run the test.

```
TestProteinGeneration.createImage.protein1.approved.png
TestProteinGeneration.createImage.protein2.approved.png
TestProteinGeneration.createImage.protein3.approved.png
```

&nbsp;

**Multiple outputs:**

In this scenario, the code under test creates three different types of files, all of which are being checked.

```
TestProtein.processInput.logOutput.approved.txt
TestProtein.processInput.calculationResults.approved.txt
TestProtein.processInput.renderedResult.approved.png
```

&nbsp;

**Multiple environments:**

In this scenario, your test only creates one file, and which one it is checked against is dependent on which OS the test is running on.

```
TestQtDialog.loginScreen.onMacOSX.approved.png
TestQtDialog.loginScreen.onWindows.approved.png
TestQtDialog.loginScreen.onLinux.approved.png
```

&nbsp;

Here are a few ways to do that.

### Catch2

You can have a file-per-subsection.

snippet: catch2_section

### doctest

You can have a file-per-subcase.

snippet: doctest_section

### Approval Tests

This can be done with Catch2's `SECTION` and doctest's `SUBCASE`. However, there is no supported way to do this with Google Tests, and it may be desirable to use an approach that Approval Tests can use with all test frameworks it supports.

The function `addAdditionalApprovalTestInformation()` adds an extra piece of text to be added to the filename used for output files.

Example of use:

snippet: verify_multiple_files

---

[Back to User Guide](/doc/README.md#top)
