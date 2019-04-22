//filesystem::
// ReSharper disable once CppUnusedIncludeDirective

#define APPROVALS_CATCH
#include "ApprovalTests/Catch2Approvals.h"
#include "ApprovalTests/Approvals.h"
#include "ApprovalTests/reporters/QuietReporter.h"
#include "CIBuildOnlyReporter.h"
#include "TextDiffReporter.h"

auto directory = Approvals::useApprovalsSubdirectory("approval_tests");

// If it's a CI machine
//      use ConsoleDiffReporter - with 'C:\Windows\System32\fc.exe' or 'diff'
auto reporterForCIDisposer = 
    Approvals::useAsFrontLoadedReporter (
        std::make_shared<CIBuildOnlyReporter>(
            std::make_shared<TextDiffReporter>() ) );

// Otherwise, for developer builds, use QuietReporter, because we have some
// tests that deliberately report failures.
auto interactiveReporterDisposer =
    Approvals::useAsDefaultReporter (
        std::make_shared<QuietReporter>() );
