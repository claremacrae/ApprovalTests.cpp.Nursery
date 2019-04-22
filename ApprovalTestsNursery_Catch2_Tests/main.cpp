//filesystem::
// ReSharper disable once CppUnusedIncludeDirective

#define APPROVALS_CATCH
#include "ApprovalTests/Catch2Approvals.h"
#include "ApprovalTests/Approvals.h"
#include "ApprovalTests/reporters/DiffReporter.h"
#include "CIBuildOnlyReporter.h"
#include "TextDiffReporter.h"

auto directory = Approvals::useApprovalsSubdirectory("approval_tests");

// If it's a CI machine
//      use ConsoleDiffReporter - with 'C:\Windows\System32\fc.exe' or 'diff'
auto reporterForCIDisposer = 
    Approvals::useAsFrontLoadedReporter (
        std::make_shared<CIBuildOnlyReporter>(
            std::make_shared<TextDiffReporter>() ) );

// Demonstrate how to set a default reporter for tests on non-CI machines.
// (in fact, DiffReporter is the default anyway, so this doesn't actually
// change the behaviour)
auto interactiveReporterDisposer =
    Approvals::useAsDefaultReporter (
        std::make_shared<DiffReporter>() );
