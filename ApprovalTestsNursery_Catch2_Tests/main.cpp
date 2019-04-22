//filesystem::
// ReSharper disable once CppUnusedIncludeDirective

#define APPROVALS_CATCH
#include "ApprovalTests/Catch2Approvals.h"
#include "ApprovalTests/Approvals.h"
#include "CIBuildOnlyReporter.h"
#include "TextDiffReporter.h"

auto directory = Approvals::useApprovalsSubdirectory("approval_tests");

// If it's a CI build, don't allow GUI applications to pop up.
// If it's a CI machine
//      use ConsoleDiffReporter - with 'C:\Windows\System32\fc.exe' or 'diff'
//      return true
// else
//      return false
auto reporterDisposer = 
    Approvals::useAsFrontLoadedReporter (
        std::make_shared<CIBuildOnlyReporter>(
            std::make_shared<TextDiffReporter>() ) );
